#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/monotonic-array.h"

namespace leetcode {
namespace problem_896 {
namespace {

class MonotonicArrayTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MonotonicArraySolution solution;
};

TEST_P(MonotonicArrayTest, Example1) {
  std::vector<int> nums = {1, 2, 2, 3};
  EXPECT_TRUE(solution.isMonotonic(nums));
}

TEST_P(MonotonicArrayTest, Example2) {
  std::vector<int> nums = {6, 5, 4, 4};
  EXPECT_TRUE(solution.isMonotonic(nums));
}

TEST_P(MonotonicArrayTest, Example3) {
  std::vector<int> nums = {1, 3, 2};
  EXPECT_FALSE(solution.isMonotonic(nums));
}

TEST_P(MonotonicArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {7};
  EXPECT_TRUE(solution.isMonotonic(nums));
}

TEST_P(MonotonicArrayTest, SelfAuthoredAllEqual) {
  std::vector<int> nums = {3, 3, 3, 3};
  EXPECT_TRUE(solution.isMonotonic(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MonotonicArrayStrategies, MonotonicArrayTest,
    ::testing::ValuesIn(MonotonicArraySolution().getStrategyNames()));

}  // namespace
}  // namespace problem_896
}  // namespace leetcode
