#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/smallest-missing-integer-greater-than-sequential-prefix-sum.h"

namespace leetcode {
namespace problem_2996 {
namespace {

class SmallestMissingIntegerGreaterThanSequentialPrefixSumTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  SmallestMissingIntegerGreaterThanSequentialPrefixSumSolution solution_;
};

TEST_P(SmallestMissingIntegerGreaterThanSequentialPrefixSumTest, Example1) {
  std::vector<int> nums{1, 2, 3, 2, 5};
  EXPECT_EQ(solution_.missingInteger(nums), 6);
}

TEST_P(SmallestMissingIntegerGreaterThanSequentialPrefixSumTest, Example2) {
  std::vector<int> nums{3, 4, 5, 1, 12, 14, 13};
  EXPECT_EQ(solution_.missingInteger(nums), 15);
}

TEST_P(SmallestMissingIntegerGreaterThanSequentialPrefixSumTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{1};
  // Sequential prefix = [1], sum = 1, 1 is in nums, so next missing is 2.
  EXPECT_EQ(solution_.missingInteger(nums), 2);
}

INSTANTIATE_TEST_SUITE_P(
    SmallestMissingIntegerGreaterThanSequentialPrefixSumTestSuite,
    SmallestMissingIntegerGreaterThanSequentialPrefixSumTest,
    ::testing::ValuesIn(
        SmallestMissingIntegerGreaterThanSequentialPrefixSumSolution()
            .getStrategyNames()));

}  // namespace
}  // namespace problem_2996
}  // namespace leetcode
