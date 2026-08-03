#include <gtest/gtest.h>

#include "leetcode/problems/online-majority-element-in-subarray.h"

using leetcode::problem_1157::OnlineMajorityElementInSubarraySolution;

class OnlineMajorityElementInSubarrayTest
    : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override { (void)GetParam(); }
};

TEST_P(OnlineMajorityElementInSubarrayTest, Example1) {
  std::vector<int> arr = {1, 1, 2, 2, 1, 1};
  OnlineMajorityElementInSubarraySolution solution(arr);
  EXPECT_EQ(solution.query(0, 5, 4), 1);
  EXPECT_EQ(solution.query(0, 3, 3), -1);
  EXPECT_EQ(solution.query(2, 3, 2), 2);
}

TEST_P(OnlineMajorityElementInSubarrayTest, SelfAuthoredSingleElement) {
  std::vector<int> arr = {7};
  OnlineMajorityElementInSubarraySolution solution(arr);
  EXPECT_EQ(solution.query(0, 0, 1), 7);
}

TEST_P(OnlineMajorityElementInSubarrayTest, SelfAuthoredNoMajority) {
  std::vector<int> arr = {1, 2, 3, 4};
  OnlineMajorityElementInSubarraySolution solution(arr);
  // threshold 3, len 4: no element appears >= 3 times.
  EXPECT_EQ(solution.query(0, 3, 3), -1);
  // subarray [1,1]: value 2 appears twice, threshold 2.
  EXPECT_EQ(solution.query(1, 2, 2), -1);
}

INSTANTIATE_TEST_SUITE_P(
    OnlineMajorityElementInSubarrayTestSuite, OnlineMajorityElementInSubarrayTest,
    ::testing::Values(0));
