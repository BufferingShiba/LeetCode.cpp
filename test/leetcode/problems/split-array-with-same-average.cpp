#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/split-array-with-same-average.h"

namespace leetcode {
namespace problem_805 {

class SplitArrayWithSameAverageTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SplitArrayWithSameAverageSolution solution;
};

TEST_P(SplitArrayWithSameAverageTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_TRUE(solution.splitArraySameAverage(nums));
}

TEST_P(SplitArrayWithSameAverageTest, Example2) {
  std::vector<int> nums = {3, 1};
  EXPECT_FALSE(solution.splitArraySameAverage(nums));
}

TEST_P(SplitArrayWithSameAverageTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {5};
  EXPECT_FALSE(solution.splitArraySameAverage(nums));
}

TEST_P(SplitArrayWithSameAverageTest, SelfAuthoredTwoEqual) {
  std::vector<int> nums = {4, 4};
  EXPECT_TRUE(solution.splitArraySameAverage(nums));
}

TEST_P(SplitArrayWithSameAverageTest, SelfAuthoredTwoDifferent) {
  std::vector<int> nums = {1, 5};
  EXPECT_FALSE(solution.splitArraySameAverage(nums));
}

INSTANTIATE_TEST_SUITE_P(
    SplitArrayWithSameAverageTestSuite, SplitArrayWithSameAverageTest,
    ::testing::ValuesIn(SplitArrayWithSameAverageSolution().getStrategyNames()));

}  // namespace problem_805
}  // namespace leetcode
