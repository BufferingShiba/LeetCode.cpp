#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-string-length-after-balanced-removals.h"

namespace leetcode {
namespace problem_3746 {

class MinimumStringLengthAfterBalancedRemovalsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  MinimumStringLengthAfterBalancedRemovalsSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MinimumStringLengthAfterBalancedRemovalsTest, Example1) {
  EXPECT_EQ(solution.minLengthAfterRemovals("aabbab"), 0);
}

TEST_P(MinimumStringLengthAfterBalancedRemovalsTest, Example2) {
  EXPECT_EQ(solution.minLengthAfterRemovals("aaaa"), 4);
}

TEST_P(MinimumStringLengthAfterBalancedRemovalsTest, Example3) {
  EXPECT_EQ(solution.minLengthAfterRemovals("aaabb"), 1);
}

TEST_P(MinimumStringLengthAfterBalancedRemovalsTest, SelfAuthoredAllB) {
  EXPECT_EQ(solution.minLengthAfterRemovals("bbb"), 3);
}

TEST_P(MinimumStringLengthAfterBalancedRemovalsTest, SelfAuthoredBalanced) {
  EXPECT_EQ(solution.minLengthAfterRemovals("ababab"), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumStringLengthAfterBalancedRemovalsStrategies,
    MinimumStringLengthAfterBalancedRemovalsTest,
    ::testing::ValuesIn(
        MinimumStringLengthAfterBalancedRemovalsSolution().getStrategyNames()));

}  // namespace problem_3746
}  // namespace leetcode
