#include <gtest/gtest.h>
#include "leetcode/problems/binary-prefix-divisible-by-5.h"

#include <string>
#include <vector>

namespace leetcode::problem_1018 {

class BinaryPrefixDivisibleBy5Test
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  BinaryPrefixDivisibleBy5Solution solution;
};

TEST_P(BinaryPrefixDivisibleBy5Test, Example1) {
  std::vector<int> nums{0, 1, 1};
  std::vector<bool> expected{true, false, false};
  EXPECT_EQ(solution.prefixesDivBy5(nums), expected);
}

TEST_P(BinaryPrefixDivisibleBy5Test, Example2) {
  std::vector<int> nums{1, 1, 1};
  std::vector<bool> expected{false, false, false};
  EXPECT_EQ(solution.prefixesDivBy5(nums), expected);
}

TEST_P(BinaryPrefixDivisibleBy5Test, SelfAuthoredSingleBit) {
  std::vector<int> nums{0};
  std::vector<bool> expected{true};
  EXPECT_EQ(solution.prefixesDivBy5(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    BinaryPrefixDivisibleBy5TestSuite, BinaryPrefixDivisibleBy5Test,
    ::testing::ValuesIn(BinaryPrefixDivisibleBy5Solution().getStrategyNames()));

}  // namespace leetcode::problem_1018
