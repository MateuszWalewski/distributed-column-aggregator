#include <gtest/gtest.h>
#include <Tools/Utility.h>

TEST( UtilityTests, CacluateRangesTest )
{
    std::string dataPath = "data1.csv";
    int nOfNodes = 2;
    // TODO: finish this test
    util::CalculateRangesToLoadDataOnNodes(dataPath, nOfNodes);

}