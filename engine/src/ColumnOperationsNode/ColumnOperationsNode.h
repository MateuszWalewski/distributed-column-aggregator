#pragma once

#include <ColumnNodeStorage/ColumnNodeStorage.h>

namespace calcs {
template <typename T>
void CreateColumn(const std::string& id);

template <typename T>
void DeleteColumn(const std::string& id);

template <typename T>
void AddElement(const std::string& id, const T elem);

template <typename T>
size_t Fetch(const std::string& id);

template <typename T>
void PrintColumn(const std::string& id);

template <typename T>
void LoadCsvData(size_t begin, size_t end, const std::string& dataPath, const std::string& id);

template <typename T>
size_t Count(const std::string& id);

template <typename T>
double Sum(const std::string& id);

template <typename T>
double SumX2(const std::string& id);

template <typename T>
T Min(const std::string& id);

template <typename T>
T Max(const std::string& id);

} // namespace calcs
