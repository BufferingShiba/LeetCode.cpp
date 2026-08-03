#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-elements-with-maximum-frequency.h"

namespace leetcode::problem_3005 {

class CountElementsWithMaximumFrequencyTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CountElementsWithMaximumFrequencySolution solution_;
};

TEST_P(CountElementsWithMaximumFrequencyTest, Example1) {
  std::vector<int> nums = {1, 2, 2, 3, 1, 4};
  EXPECT_EQ(4, solution_.maxFrequencyElements(nums));
}

TEST_P(CountElementsWithMaximumFrequencyTest, Example2) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  EXPECT_EQ(5, solution_.maxFrequencyElements(nums));
}

TEST_P(CountElementsWithMaximumFrequencyTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {7};
  EXPECT_EQ(1, solution_.maxFrequencyElements(nums));
}

INSTANTIATE_TEST_SUITE_P(
    CountElementsWithMaximumFrequencyTestCases,
    CountElementsWithMaximumFrequencyTest,
    ::testing::ValuesIn(CountElementsWithMaximumFrequencySolution().getStrategyNames()));

}  // namespace leetcode::problem_3005
