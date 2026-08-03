#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/number-of-ways-to-separate-numbers.h"

namespace leetcode {
namespace problem_1977 {

class NumberOfWaysToSeparateNumbersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfWaysToSeparateNumbersSolution solution;
};

TEST_P(NumberOfWaysToSeparateNumbersTest, Example1) {
  EXPECT_EQ(solution.numberOfCombinations("327"), 2);
}

TEST_P(NumberOfWaysToSeparateNumbersTest, Example2) {
  EXPECT_EQ(solution.numberOfCombinations("094"), 0);
}

TEST_P(NumberOfWaysToSeparateNumbersTest, Example3) {
  EXPECT_EQ(solution.numberOfCombinations("0"), 0);
}


// LeetCode 失败用例: WrongAnswerCase1_AllNines
TEST_P(NumberOfWaysToSeparateNumbersTest, WrongAnswerCase1_AllNines) {
  // 输入: num = "9999999999999"
    // 期望: 101
    std::string num = "9999999999999";
    int expected = 101;
    int result = solution.numberOfCombinations(num);
    EXPECT_EQ(expected, result);
}
INSTANTIATE_TEST_SUITE_P(
    NumberOfWaysToSeparateNumbersTests, NumberOfWaysToSeparateNumbersTest,
    ::testing::ValuesIn(NumberOfWaysToSeparateNumbersSolution().getStrategyNames()));

}  // namespace problem_1977
}  // namespace leetcode
