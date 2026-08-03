#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-maximum-length-of-valid-subsequence-ii.h"

namespace leetcode::problem_3202 {

class FindTheMaximumLengthOfValidSubsequenceIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheMaximumLengthOfValidSubsequenceIiSolution solution;
};

TEST_P(FindTheMaximumLengthOfValidSubsequenceIiTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  EXPECT_EQ(solution.maximumLength(nums, 2), 5);
}

TEST_P(FindTheMaximumLengthOfValidSubsequenceIiTest, Example2) {
  std::vector<int> nums = {1, 4, 2, 3, 1, 4};
  EXPECT_EQ(solution.maximumLength(nums, 3), 4);
}

TEST_P(FindTheMaximumLengthOfValidSubsequenceIiTest, SelfAuthoredAllSameRemainder) {
  std::vector<int> nums = {3, 6, 9, 4, 7};
  // 余数(k=3): 0,0,0,1,1。最长为 {3,6,9} 长度 3。
  EXPECT_EQ(solution.maximumLength(nums, 3), 3);
}

TEST_P(FindTheMaximumLengthOfValidSubsequenceIiTest, SelfAuthoredTwoElements) {
  std::vector<int> nums = {5, 8};
  EXPECT_EQ(solution.maximumLength(nums, 3), 2);
}

INSTANTIATE_TEST_SUITE_P(
    FindTheMaximumLengthOfValidSubsequenceIiTestSuite,
    FindTheMaximumLengthOfValidSubsequenceIiTest,
    ::testing::ValuesIn(
        FindTheMaximumLengthOfValidSubsequenceIiSolution().getStrategyNames()));

}  // namespace leetcode::problem_3202
