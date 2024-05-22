#pragma once

#include <string>
#include <vector>

using DataLoadRanges = std::vector<std::pair<size_t, size_t>>;
namespace util {
template <typename T>
void PrintVector(const std::vector<T>& container, const std::string& label);

template <typename T>
void LoadCsvToDataColumn(const std::string& dataFilePath, const size_t begin, const size_t end, std::vector<T>& destination);

DataLoadRanges CalculateRangesToLoadDataOnNodes(int numberOfValues, int nOfNodes);
int CalculateNumberOfLinesInFile(const std::string& filePath);
std::vector<std::string> SplitStringToVector(const std::string& stringToSplit);
} // namespace util
