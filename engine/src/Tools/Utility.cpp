#include "Utility.h"
#include "constants.h"
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include <fstream>
#include <iostream>
#include <iterator>
#include <mutex>
#include <sstream>

namespace util {

const std::string DATA_FILE_PATH = std::string(DATA_PATH) + "/data/";
template void LoadCsvToDataColumn<int>(const std::string& dataFilePath, const size_t begin, const size_t end,
                                       std::vector<int>& destination);
template void LoadCsvToDataColumn<float>(const std::string& dataFilePath, const size_t begin, const size_t end,
                                         std::vector<float>& destination);
template void LoadCsvToDataColumn<double>(const std::string& dataFilePath, const size_t begin, const size_t end,
                                          std::vector<double>& destination);

template void PrintVector<int>(const std::vector<int>& container, const std::string& label);
template void PrintVector<float>(const std::vector<float>& container, const std::string& label);
template void PrintVector<double>(const std::vector<double>& container, const std::string& label);
template void PrintVector<std::string>(const std::vector<std::string>& container, const std::string& label);

std::vector<std::string> SplitStringToVector(const std::string& stringToSplit) {
    std::stringstream ss(stringToSplit);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> vstrings(begin, end);
    return vstrings;
}

std::optional<std::pair<const std::string, const std::string>> getTcpIpInfo(const std::string& connectionInfo) {
    std::vector<std::string> addressParts;
    boost::split(addressParts, connectionInfo, boost::is_any_of(":"));
    if (addressParts.size() != 2) {
        std::cerr << "Wrong TCP/IP server connection details " << std::endl;
        return std::nullopt;
    } else {
        return std::make_pair(std::as_const(addressParts[0]), std::as_const(addressParts[1]));
    }
}

std::optional<std::string> complyWithIpV4(const std::string& ipAddress) {
    try {
        boost::asio::ip::address_v4 ipv4 = boost::asio::ip::address_v4::from_string(ipAddress);
        return ipv4.to_string();
    } catch (const boost::system::system_error& e) {
        std::cerr << "Wrong IpV4 address conversion" << std::endl;
        return std::nullopt;
    }
}

std::optional<uint16_t> convertToTcpPortCompliantType(const std::string& ipPort) {
    try {
        return boost::lexical_cast<uint16_t>(ipPort);
    } catch (const boost::bad_lexical_cast& e) {
        std::cerr << "Error in cast: " << e.what() << std::endl;
        return std::nullopt;
    }
}

int CalculateNumberOfLinesInFile(const std::string& filePath) {
    std::ifstream inFile(DATA_FILE_PATH + filePath);
    try {
        if (!inFile.is_open()) {
            throw std::runtime_error("Failed to open file: " + filePath);
        }
    } catch (const std::exception& e) {
        std::cerr << "Problem with file:" << e.what() << std::endl;
    }
    return std::count(std::istreambuf_iterator<char>(inFile), std::istreambuf_iterator<char>(), '\n') + 1;
}

DataLoadRanges CalculateRangesToLoadDataOnNodes(int numberOfValues, int nOfNodes) {
    DataLoadRanges ranges;

    size_t length = numberOfValues / nOfNodes;
    size_t remain = numberOfValues % nOfNodes;

    size_t begin = 0;
    size_t end = 0;

    for (int i = 0; i < std::min(nOfNodes, numberOfValues); ++i) {
        end += (remain > 0) ? (length + !!(remain--)) : length;

        ranges.emplace_back(std::make_pair(begin, end));
        begin = end;
    }

    return ranges;
}

template <typename T>
void PrintVector(const std::vector<T>& container, const std::string& label) {
    for (auto& x : container) {
        std::cout << label << ": " << x << '\n';
    }

    std::cout << std::flush;
}

template <typename T>
void LoadCsvToDataColumn(const std::string& fileName, const size_t begin, const size_t end, std::vector<T>& destination) {
    std::mutex m;
    m.lock();
    std::ifstream myfile(DATA_FILE_PATH + fileName);

    try {
        if (!myfile.is_open()) {
            throw std::runtime_error("Failed to open file: " + fileName);
        }
    } catch (const std::exception& e) {
        std::cerr << "Problem with file:" << e.what() << std::endl;
    }

    size_t count = 0;
    std::string line;
    while (std::getline(myfile, line)) {
        std::istringstream iss(line);
        T value;
        ++count;
        if (count > end) {
            break;
        }
        if (count <= begin) {
            continue;
        }
        if (iss >> value) {
            destination.push_back(value);
        } else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }

    m.unlock();
}

} // namespace util
