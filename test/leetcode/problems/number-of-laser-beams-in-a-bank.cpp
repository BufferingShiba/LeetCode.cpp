#include <gtest/gtest.h>

#include "leetcode/problems/number-of-laser-beams-in-a-bank.h"
#include <string>
#include <vector>

namespace leetcode::problem_2125 {

class NumberOfLaserBeamsInABankTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution_.setStrategy(GetParam());
    }

    NumberOfLaserBeamsInABankSolution solution_;
};

TEST_P(NumberOfLaserBeamsInABankTest, Example1) {
    std::vector<std::string> bank = {"011001", "000000", "010100", "001000"};
    EXPECT_EQ(solution_.numberOfBeams(bank), 8);
}

TEST_P(NumberOfLaserBeamsInABankTest, Example2) {
    std::vector<std::string> bank = {"000", "111", "000"};
    EXPECT_EQ(solution_.numberOfBeams(bank), 0);
}

TEST_P(NumberOfLaserBeamsInABankTest, SelfAuthoredAllEmptyRows) {
    std::vector<std::string> bank = {"0000", "0000", "0000"};
    EXPECT_EQ(solution_.numberOfBeams(bank), 0);
}

TEST_P(NumberOfLaserBeamsInABankTest, SelfAuthoredSingleRowWithDevices) {
    std::vector<std::string> bank = {"10101"};
    EXPECT_EQ(solution_.numberOfBeams(bank), 0);
}

TEST_P(NumberOfLaserBeamsInABankTest, SelfAuthoredConsecutiveDeviceRows) {
    std::vector<std::string> bank = {"11", "11"};
    EXPECT_EQ(solution_.numberOfBeams(bank), 4);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfLaserBeamsInABankTestSuite,
    NumberOfLaserBeamsInABankTest,
    ::testing::ValuesIn(
        NumberOfLaserBeamsInABankSolution().getStrategyNames()));

}  // namespace leetcode::problem_2125
