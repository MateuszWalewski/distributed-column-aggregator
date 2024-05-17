#include "ColumnImpl.h"
#include "TraitsCol.h"
#include <Loki/Singleton.h>
#include <Networking/RPCManager.h>
#include <ParameterController/ParameterControllerHub.h>
#include <TCPChannel/TCPServer.h>
#include <Tools/Utility.h>

#include <cmath>
#include <exception>
#include <numeric>

template class ColumnImpl<double>;
template class ColumnImpl<float>;
template class ColumnImpl<int>;

template <typename T>
ColumnImpl<T>::ColumnImpl()
{
    typeName = std::string( typeid( T ).name() );
    colId = GenerateUniqueColumnId();
    ++instanceId;
}

template <typename T>
ColumnImpl<T>::~ColumnImpl()
{
}

template <typename T>
ColumnImpl<T>::ColumnImpl( const ColumnImpl<T>& obj )
{
    if ( this != &obj )
        ++instanceId;
}

template <typename T>
void ColumnImpl<T>::CreateColumnOnNode()
{
    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();
    RPCInstance.CallRPCMethod( "CreateColumn" + typeName, colId );
}

template <typename T>
void ColumnImpl<T>::DeleteColumnOnNode()
{
    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();
    RPCInstance.CallRPCMethod( "DeleteColumn" + typeName, colId );
}

template <typename T>
void ColumnImpl<T>::PrintColumnOnNode()
{
    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();
    RPCInstance.CallRPCMethod( "PrintColumn" + typeName, colId );
}

template <typename T>
void ColumnImpl<T>::AddElement( const size_t nodeNumber, const std::any element )
{
    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto elem = std::any_cast<T>( element );
    RPCInstance.CallRPCMethodOnTheGivenNode( "AddElement" + typeName, nodeNumber, colId, elem );
}

template <typename T>
std::any ColumnImpl<T>::GetElement( size_t index )
{
    assert( index + 1 <= data.size() );
    if ( data.size() == 0 )
    {
        return std::make_any<T>( 0 );
    }
    return data[index];
}

template <typename T>
void ColumnImpl<T>::LoadDataToNode( const std::string& dataFilePath )
{
    auto& pCInstance = Loki::SingletonHolder<ParameterControllerHub>::Instance();
    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();
    int nOfNodes = pCInstance.GetNumberOfNodes();
    auto ranges = util::CalculateRangesToLoadDataOnNodes( dataFilePath, nOfNodes );
    RPCInstance.CallRPCMethod( "LoadCsvData" + typeName, ranges, dataFilePath, colId );
}

template <typename T>
std::any ColumnImpl<T>::Sum()
{
    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto results = RPCInstance.CallRPCMethod<T>( "Sum" + typeName, colId );
    return std::accumulate( results.begin(), results.end(), static_cast<T>( 0 ) );
}

template <typename T>
int ColumnImpl<T>::Count()
{
    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto results = RPCInstance.CallRPCMethod<T>( "Count" + typeName, colId );
    return std::accumulate( results.begin(), results.end(), static_cast<int>( 0 ) );
}

template <typename T>
int ColumnImpl<T>::Fetch()
{
    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();
    boost::asio::io_context io_context;
    TCPServer tcpServer( io_context );
    auto as = std::async( std::launch::async, &TCPServer::Accept, &tcpServer );
    auto results = RPCInstance.CallRPCMethodSizes<T>( "Fetch" + typeName, colId );
    as.get();
    auto dataSize = std::accumulate( results.begin(), results.end(), static_cast<int>( 0 ) );
    data.resize( dataSize );
    tcpServer.Read( data, results );

    return dataSize;
}

template <typename T>
double ColumnImpl<T>::MomentI()
{
    return static_cast<double>( std::any_cast<T>( Sum() ) ) / Count();
}

template <typename T>
double ColumnImpl<T>::MomentII()
{
    auto& RPCInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto results = RPCInstance.CallRPCMethod<double>( "SumX2" + typeName, colId );
    return static_cast<double>( std::accumulate( results.begin(), results.end(), static_cast<double>( 0 ) ) ) / Count();
}

template <typename T>
double ColumnImpl<T>::Stddev()
{
    auto momentI = MomentI();
    auto momentII = MomentII();
    auto count = Count();
    return sqrt( ( momentII - momentI * momentI ) * ( static_cast<double>( count ) / ( count - 1 ) ) );
}

template <typename T>
std::string ColumnImpl<T>::GenerateUniqueColumnId() const
{
    return std::string( TypeNameCol<T>::name ) + std::to_string( instanceId );
}
