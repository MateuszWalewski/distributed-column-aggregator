#include "ColumnImpl.h"
#include "TraitsCol.h"
#include <ConfigurationManager/ConfigurationManager.h>
#include <Loki/Singleton.h>
#include <Networking/RPCManager.h>
#include <TCPChannel/TCPServer.h>
#include <Tools/Utility.h>

#include <cmath>
#include <exception>
#include <execution>
#include <numeric>

template class ColumnImpl<double>;
template class ColumnImpl<float>;
template class ColumnImpl<int>;

template <typename T>
ColumnImpl<T>::ColumnImpl() : _isDataFetchedFromNodes(false) {
    _typeName = std::string(TypeNameCol<T>::name);
    _colId = GenerateUniqueColumnId();
    ++_instanceId;
}

template <typename T>
void ColumnImpl<T>::CreateColumnOnNode() {
    auto& rpcInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto rpcHandlers = rpcInstance.CallRpcMethodVoid(_typeName + "CreateColumn", _colId);
    rpcInstance.CompleteRpcTasks(rpcHandlers);
}

template <typename T>
void ColumnImpl<T>::DeleteColumnOnNode() {
    auto& rpcInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto rpcHandlers = rpcInstance.CallRpcMethodVoid(_typeName + "DeleteColumn", _colId);
    rpcInstance.CompleteRpcTasks(rpcHandlers);
}

template <typename T>
void ColumnImpl<T>::PrintColumnOnNode() {
    auto& rpcInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto rpcHandlers = rpcInstance.CallRpcMethodVoid(_typeName + "PrintColumn", _colId);
    rpcInstance.CompleteRpcTasks(rpcHandlers);
}

template <typename T>
void ColumnImpl<T>::AddElement(const size_t nodeNumber, const std::any element) {
    auto& rpcInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto elem = std::any_cast<T>(element);
    rpcInstance.CallRpcMethodOnTheGivenNode(_typeName + "AddElement", nodeNumber, _colId, elem);
}

template <typename T>
std::any ColumnImpl<T>::GetElement(size_t index) {
    assert(index + 1 <= _data.size());
    if (_data.size() == 0) {
        return std::make_any<T>(0);
    }
    return _data[index];
}

template <typename T>
void ColumnImpl<T>::LoadDataToNode(const std::string& dataFilePath) {
    auto& cMInstance = Loki::SingletonHolder<ConfigurationManager>::Instance();
    auto& rpcInstance = Loki::SingletonHolder<RPCManager>::Instance();
    int nOfNodes = std::get<size_t>(cMInstance.getConfigParameter(NUMBER_OF_NODES));
    auto nOfLines = util::CalculateNumberOfLinesInFile(dataFilePath);
    auto ranges = util::CalculateRangesToLoadDataOnNodes(nOfLines, nOfNodes);
    rpcInstance.CallRpcMethod(_typeName + "LoadCsvData", ranges, dataFilePath, _colId);
}

template <typename T>
double ColumnImpl<T>::Sum() {
    auto& rpcInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto results = rpcInstance.CallRpcMethod<double>(_typeName + "Sum", _colId);
    return std::accumulate(results.cbegin(), results.cend(), 0.0);
}

template <typename T>
size_t ColumnImpl<T>::Count() {
    auto& rpcInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto results = rpcInstance.CallRpcMethod<T>(_typeName + "Count", _colId);
    return std::accumulate(results.cbegin(), results.cend(), size_t{0});
}

template <typename T>
std::any ColumnImpl<T>::Min() {
    auto& rpcInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto results = rpcInstance.CallRpcMethod<T>(_typeName + "Min", _colId);
    return std::any_cast<T>(*std::min_element(std::execution::par, results.cbegin(), results.cend()));
}

template <typename T>
std::any ColumnImpl<T>::Max() {
    auto& rpcInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto results = rpcInstance.CallRpcMethod<T>(_typeName + "Max", _colId);
    return std::any_cast<T>(*std::max_element(std::execution::par, results.cbegin(), results.cend()));
}

template <typename T>
size_t ColumnImpl<T>::Fetch() {
    if (_isDataFetchedFromNodes) {
        std::cout << "Data already fetched from nodes." << std::endl;
        return _data.size();
    }

    auto& rpcInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto results = rpcInstance.CallRpcMethod<int>(_typeName + "Count", _colId);
    boost::asio::io_context io_context;
    TCPServer tcpServer(io_context);
    auto tcpAsync = std::async(std::launch::async, &TCPServer::Accept, &tcpServer);
    auto handles = rpcInstance.CallRpcMethodVoid(_typeName + "Fetch", _colId);
    tcpAsync.get();
    auto dataSize = std::accumulate(results.begin(), results.end(), size_t{0});
    _data.resize(dataSize);
    tcpServer.Read(_data, results);
    rpcInstance.CompleteRpcTasks(handles);
    _isDataFetchedFromNodes = true;
    return dataSize;
}

template <typename T>
double ColumnImpl<T>::MomentI() {
    return Sum() / Count();
}

template <typename T>
double ColumnImpl<T>::MomentII() {
    auto& rpcInstance = Loki::SingletonHolder<RPCManager>::Instance();
    auto results = rpcInstance.CallRpcMethod<double>(_typeName + "SumX2", _colId);
    return std::accumulate(results.cbegin(), results.cend(), 0.0) / Count();
}

template <typename T>
double ColumnImpl<T>::Stddev() {
    auto momentI = MomentI();
    auto momentII = MomentII();
    auto count = static_cast<double>(Count());
    return sqrt((momentII - momentI * momentI) * (count / (count - 1)));
}

template <typename T>
std::string ColumnImpl<T>::GenerateUniqueColumnId() const {
    return std::string(TypeNameCol<T>::name) + std::to_string(_instanceId);
}
