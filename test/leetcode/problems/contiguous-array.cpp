#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/contiguous-array.h"

namespace leetcode::problem_525 {

class ContiguousArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ContiguousArraySolution solution;
};

TEST_P(ContiguousArrayTest, Example1) {
  std::vector<int> nums = {0, 1};
  EXPECT_EQ(2, solution.findMaxLength(nums));
}

TEST_P(ContiguousArrayTest, Example2) {
  std::vector<int> nums = {0, 1, 0};
  EXPECT_EQ(2, solution.findMaxLength(nums));
}

TEST_P(ContiguousArrayTest, Example3) {
  std::vector<int> nums = {0, 1, 1, 1, 1, 1, 0, 0, 0};
  EXPECT_EQ(6, solution.findMaxLength(nums));
}

TEST_P(ContiguousArrayTest, SelfAuthoredAllZeros) {
  std::vector<int> nums = {0, 0};
  EXPECT_EQ(0, solution.findMaxLength(nums));
}

TEST_P(ContiguousArrayTest, SelfAuthoredAllOnes) {
  std::vector<int> nums = {1, 1, 1, 1};
  EXPECT_EQ(0, solution.findMaxLength(nums));
}

TEST_P(ContiguousArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {0};
  EXPECT_EQ(0, solution.findMaxLength(nums));
}

INSTANTIATE_TEST_SUITE_P(
    ContiguousArrayTestSuite, ContiguousArrayTest,
    ::testing::ValuesIn(ContiguousArraySolution().getStrategyNames()));

}  // namespace leetcode::problem_525
