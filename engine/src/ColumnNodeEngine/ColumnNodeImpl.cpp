#include "ColumnNodeImpl.h"
#include <Loki/Singleton.h>
#include <TCPChannel/TCPClient.h>
#include <Tools/Utility.h>

#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>

template class ColumnNodeImpl<double>;
template class ColumnNodeImpl<float>;
template class ColumnNodeImpl<int>;

template <typename T>
void ColumnNodeImpl<T>::Print() {
    util::PrintVector(_data, "elements:");
}

template <typename T>
void ColumnNodeImpl<T>::LoadData(const std::string& dataFilePath, const size_t begin, const size_t end) {
    util::LoadCsvToDataColumn(dataFilePath, begin, end, _data);
}

template <typename T>
double ColumnNodeImpl<T>::Sum() {
    return std::accumulate(_data.begin(), _data.end(), 0.0, [](double acc, T val) { return acc + static_cast<double>(val); });
}

template <typename T>
size_t ColumnNodeImpl<T>::Count() {
    return _data.size(); // O(1)
}

template <typename T>
double ColumnNodeImpl<T>::SumX2() {
    // should be normalized to multiplicity to avoid overflow for big numbers
    return std::transform_reduce(std::execution::par, _data.cbegin(), _data.cend(), 0.0L, std::plus{},
                                 [&](auto val) { return static_cast<double>(val) * val / _data.size(); }) *
           _data.size();
}

template <typename T>
void ColumnNodeImpl<T>::AddElement(const std::any element) {
    auto elem = std::any_cast<T>(element);
    _data.push_back(std::any_cast<T>(elem));
    std::cout << "Element: " << std::to_string(elem) << " added to node." << '\n';
}

template <typename T>
size_t ColumnNodeImpl<T>::Fetch() {
    boost::asio::io_context io_context;
    TCPClient tcpClient(io_context);
    tcpClient.Send(_data);
    return _data.size();
}
