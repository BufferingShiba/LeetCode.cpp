#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/maximum-score-using-exactly-k-pairs.h"

namespace leetcode {
namespace problem_3836 {

class MaximumScoreUsingExactlyKPairsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MaximumScoreUsingExactlyKPairsSolution solution_;
};

TEST_P(MaximumScoreUsingExactlyKPairsTest, Example1) {
  std::vector<int> nums1 = {1, 3, 2};
  std::vector<int> nums2 = {4, 5, 1};
  int k = 2;
  EXPECT_EQ(solution_.maxScore(nums1, nums2, k), 22);
}

TEST_P(MaximumScoreUsingExactlyKPairsTest, Example2) {
  std::vector<int> nums1 = {-2, 0, 5};
  std::vector<int> nums2 = {-3, 4, -1, 2};
  int k = 2;
  EXPECT_EQ(solution_.maxScore(nums1, nums2, k), 26);
}

TEST_P(MaximumScoreUsingExactlyKPairsTest, Example3) {
  std::vector<int> nums1 = {-3, -2};
  std::vector<int> nums2 = {1, 2};
  int k = 2;
  EXPECT_EQ(solution_.maxScore(nums1, nums2, k), -7);
}

TEST_P(MaximumScoreUsingExactlyKPairsTest, SinglePair) {
  std::vector<int> nums1 = {10};
  std::vector<int> nums2 = {20};
  int k = 1;
  EXPECT_EQ(solution_.maxScore(nums1, nums2, k), 200);
}

TEST_P(MaximumScoreUsingExactlyKPairsTest, AllNegative) {
  std::vector<int> nums1 = {-5, -3, -1};
  std::vector<int> nums2 = {-4, -2};
  int k = 2;
  // (-5)*(-4)=20, (-3)*(-2)=6 → total 26
  EXPECT_EQ(solution_.maxScore(nums1, nums2, k), 26);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MaximumScoreUsingExactlyKPairsTest,
    ::testing::ValuesIn(
        MaximumScoreUsingExactlyKPairsSolution().getStrategyNames()));

}  // namespace problem_3836
}  // namespace leetcode
