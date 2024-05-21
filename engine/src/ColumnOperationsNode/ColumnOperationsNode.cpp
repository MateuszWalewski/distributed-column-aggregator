#include "ColumnOperationsNode.h"

#include <Loki/Singleton.h>
#include <vector>

namespace calcs
{
template void CreateColumn<int>( const std::string& id );
template void CreateColumn<double>( const std::string& id );
template void CreateColumn<float>( const std::string& id );

template void DeleteColumn<int>( const std::string& id );
template void DeleteColumn<double>( const std::string& id );
template void DeleteColumn<float>( const std::string& id );

template void AddElement<int>( const std::string& id, const int elem );
template void AddElement<double>( const std::string& id, const double elem );
template void AddElement<float>( const std::string& id, const float elem );

template int Sum<int>( const std::string& id );
template double Sum<double>( const std::string& id );
template float Sum<float>( const std::string& id );

template double SumX2<int>( const std::string& id );
template double SumX2<double>( const std::string& id );
template double SumX2<float>( const std::string& id );

template int Count<int>( const std::string& id );
template int Count<double>( const std::string& id );
template int Count<float>( const std::string& id );

template int Fetch<int>( const std::string& id );
template int Fetch<double>( const std::string& id );
template int Fetch<float>( const std::string& id );

template void PrintColumn<int>( const std::string& id );
template void PrintColumn<double>( const std::string& id );
template void PrintColumn<float>( const std::string& id );

template void LoadCsvData<int>( size_t begin, size_t end, const std::string& dataPath, const std::string& id );
template void LoadCsvData<double>( size_t begin, size_t end, const std::string& dataPath, const std::string& id );
template void LoadCsvData<float>( size_t begin, size_t end, const std::string& dataPath, const std::string& id );

template <typename T>
void CreateColumn( const std::string& id )
{
    auto& cSInstance = Loki::SingletonHolder<ColumnNodeStorage>::Instance();
    auto& map = cSInstance.GetColumnStorage<T>();
    map[id] = std::make_shared<ColumnNode<T>>( id );
}

template <typename T>
void DeleteColumn( const std::string& id )
{
    auto& cSInstance = Loki::SingletonHolder<ColumnNodeStorage>::Instance();
    auto& map = cSInstance.GetColumnStorage<T>();
    map.erase( id );
}

template <typename T>
void AddElement( const std::string& id, const T elem )
{
    auto& cSInstance = Loki::SingletonHolder<ColumnNodeStorage>::Instance();
    auto& map = cSInstance.GetColumnStorage<T>();
    map[id]->AddElement( elem );
}

template <typename T>
T Sum( const std::string& id )
{
    auto& cSInstance = Loki::SingletonHolder<ColumnNodeStorage>::Instance();
    auto& map = cSInstance.GetColumnStorage<T>();
    return map[id]->Sum();
}

template <typename T>
double SumX2( const std::string& id )
{
    auto& cSInstance = Loki::SingletonHolder<ColumnNodeStorage>::Instance();
    auto& map = cSInstance.GetColumnStorage<T>();
    return map[id]->SumX2();
}

template <typename T>
int Count( const std::string& id )
{
    auto& cSInstance = Loki::SingletonHolder<ColumnNodeStorage>::Instance();
    auto& map = cSInstance.GetColumnStorage<T>();
    return map[id]->Count();
}

template <typename T>
void PrintColumn( const std::string& id )
{
    auto& cSInstance = Loki::SingletonHolder<ColumnNodeStorage>::Instance();
    auto& map = cSInstance.GetColumnStorage<T>();
    map[id]->Print();
}

template <typename T>
void LoadCsvData( size_t begin, size_t end, const std::string& dataPath, const std::string& id )
{
    auto& cSInstance = Loki::SingletonHolder<ColumnNodeStorage>::Instance();
    auto& map = cSInstance.GetColumnStorage<T>();
    map[id]->LoadData( dataPath, begin, end );
}

template <typename T>
int Fetch( const std::string& id )
{
    auto& cSInstance = Loki::SingletonHolder<ColumnNodeStorage>::Instance();
    auto& map = cSInstance.GetColumnStorage<T>();
    return map[id]->Fetch();
}

} // namespace calcs
