#include <gtest/gtest.h>

#include "leetcode/problems/maximum-value-of-a-string-in-an-array.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2496 {

class MaximumValueOfAStringInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumValueOfAStringInAnArraySolution solution;
};

TEST_P(MaximumValueOfAStringInAnArrayTest, Example1) {
  std::vector<std::string> strs = {"alic3", "bob", "3", "4", "00000"};
  EXPECT_EQ(solution.maximumValue(strs), 5);
}

TEST_P(MaximumValueOfAStringInAnArrayTest, Example2) {
  std::vector<std::string> strs = {"1", "01", "001", "0001"};
  EXPECT_EQ(solution.maximumValue(strs), 1);
}

TEST_P(MaximumValueOfAStringInAnArrayTest, SelfAuthoredAllLetters) {
  std::vector<std::string> strs = {"a", "ab", "abc", "abcdef"};
  // All are letters: values are 1, 2, 3, 6 -> max 6
  EXPECT_EQ(solution.maximumValue(strs), 6);
}

TEST_P(MaximumValueOfAStringInAnArrayTest, SelfAuthoredMixedSingleDigits) {
  std::vector<std::string> strs = {"9", "8", "10a"};
  // "9" -> 9, "8" -> 8, "10a" -> 3 -> max 9
  EXPECT_EQ(solution.maximumValue(strs), 9);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumValueOfAStringInAnArrayTestSuite,
    MaximumValueOfAStringInAnArrayTest,
    ::testing::ValuesIn(
        MaximumValueOfAStringInAnArraySolution().getStrategyNames()));

}  // namespace problem_2496
}  // namespace leetcode
