#include <gtest/gtest.h>

#include "leetcode/problems/self-dividing-numbers.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_728 {

class SelfDividingNumbersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SelfDividingNumbersSolution solution;
};

TEST_P(SelfDividingNumbersTest, Example1) {
  std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22};
  EXPECT_EQ(expected, solution.selfDividingNumbers(1, 22));
}

TEST_P(SelfDividingNumbersTest, Example2) {
  std::vector<int> expected = {48, 55, 66, 77};
  EXPECT_EQ(expected, solution.selfDividingNumbers(47, 85));
}

TEST_P(SelfDividingNumbersTest, SelfAuthoredSingleDigit) {
  std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(expected, solution.selfDividingNumbers(1, 9));
}

INSTANTIATE_TEST_SUITE_P(
    SelfDividingNumbersTestSuite, SelfDividingNumbersTest,
    ::testing::ValuesIn(SelfDividingNumbersSolution().getStrategyNames()));

}  // namespace problem_728
}  // namespace leetcode
