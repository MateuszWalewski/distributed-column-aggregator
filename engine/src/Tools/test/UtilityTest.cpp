#include <Tools/Utility.h>
#include <gtest/gtest.h>

TEST(UtilityTests, CacluateNumberOfLinesInFile_Test) {
    std::string dataPath = "data3.csv";
    auto numberOfLines = util::CalculateNumberOfLinesInFile(dataPath);
    EXPECT_EQ(numberOfLines, 9);
}

TEST(UtilityTests, CacluateRanges_Test) {
    int nOfNodes = 2;
    int nOfLines = 9;
    auto ranges = util::CalculateRangesToLoadDataOnNodes(nOfLines, nOfNodes);
    EXPECT_EQ(ranges.size(), 2);
    auto [begin1, end1] = ranges[0];
    EXPECT_EQ(begin1, 0);
    EXPECT_EQ(end1, 5);
    auto [begin2, end2] = ranges[1];
    EXPECT_EQ(begin2, 5);
    EXPECT_EQ(end2, 9);
}

TEST(UtilityTests, GetTcpIpInfo_1_Test) {
    std::string tcp = "192.168.1.14:8081";
    auto tcpInfo = util::getTcpIpInfo(tcp);
    EXPECT_TRUE(tcpInfo);
    auto [tcpAddress, tcpPort] = tcpInfo.value();
    EXPECT_EQ(tcpAddress, "192.168.1.14");
    EXPECT_EQ(tcpPort, "8081");
}

TEST(UtilityTests, GetTcpIpInfo_2_Test) {
    std::string tcp = "192.168.1.14:8081:8082";
    auto tcpInfo = util::getTcpIpInfo(tcp);
    EXPECT_FALSE(tcpInfo);
}

TEST(UtilityTests, complyWithIpV4_1_Test) {
    std::string tcp = "192.168.1.14";
    auto tcpInfo = util::complyWithIpV4(tcp);
    EXPECT_TRUE(tcpInfo);
}

TEST(UtilityTests, complyWithIpV4_2_Test) {
    std::string tcp = "192.168..14";
    auto tcpInfo = util::complyWithIpV4(tcp);
    EXPECT_FALSE(tcpInfo);
}

TEST(UtilityTests, complyWithIpV4_3_Test) {
    std::string tcp = "092.168.1.14";
    auto tcpInfo = util::complyWithIpV4(tcp);
    EXPECT_FALSE(tcpInfo);
}

TEST(UtilityTests, convertToTcpPortCompliantType_1_Test) {
    std::string port = "65535";
    auto tcpInfo = util::convertToTcpPortCompliantType(port);
    EXPECT_TRUE(tcpInfo);
}

TEST(UtilityTests, convertToTcpPortCompliantType_2_Test) {
    std::string port = "65536";
    auto tcpInfo = util::convertToTcpPortCompliantType(port);
    EXPECT_FALSE(tcpInfo);
}

TEST(UtilityTests, convertToTcpPortCompliantType_3_Test) {
    std::string port = "655d6";
    auto tcpInfo = util::convertToTcpPortCompliantType(port);
    EXPECT_FALSE(tcpInfo);
}
