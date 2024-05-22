#include <Tools/Utility.h>
#include <gtest/gtest.h>

TEST(UtilityTests, CacluateRangesTest) {
    std::string dataPath = "data1.csv";
    int nOfNodes = 2;
    // TODO: finish this test
    auto numberOfLines = util::CalculateNumberOfLinesInFile(dataPath);
    util::CalculateRangesToLoadDataOnNodes(numberOfLines, nOfNodes);
}
