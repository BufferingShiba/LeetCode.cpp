#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-distance-between-three-equal-elements-ii.h"

namespace leetcode::problem_3741 {

namespace {

int expectedBruteForce(const std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  int best = -1;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      for (int k = j + 1; k < n; ++k)
        if (nums[i] == nums[j] && nums[j] == nums[k]) {
          int d = (j - i) + (k - j) + (k - i);
          if (best == -1 || d < best) best = d;
        }
  return best;
}

}  // namespace

class MinimumDistanceBetweenThreeEqualElementsIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumDistanceBetweenThreeEqualElementsIiSolution solution_;
};

TEST_P(MinimumDistanceBetweenThreeEqualElementsIiTest, Example1) {
  std::vector<int> nums = {1, 2, 1, 1, 3};
  EXPECT_EQ(6, solution_.minimumDistance(nums));
}

TEST_P(MinimumDistanceBetweenThreeEqualElementsIiTest, Example2) {
  std::vector<int> nums = {1, 1, 2, 3, 2, 1, 2};
  EXPECT_EQ(8, solution_.minimumDistance(nums));
}

TEST_P(MinimumDistanceBetweenThreeEqualElementsIiTest, Example3) {
  std::vector<int> nums = {1};
  EXPECT_EQ(-1, solution_.minimumDistance(nums));
}

TEST_P(MinimumDistanceBetweenThreeEqualElementsIiTest, SelfAuthoredBruteForceRandom) {
  std::vector<int> nums = {2, 1, 2, 2, 3, 1, 1, 2, 3, 3};
  EXPECT_EQ(expectedBruteForce(nums), solution_.minimumDistance(nums));
}

TEST_P(MinimumDistanceBetweenThreeEqualElementsIiTest, SelfAuthoredNoTripleSingleValue) {
  std::vector<int> nums = {1, 1, 2, 2, 3, 3};
  EXPECT_EQ(-1, solution_.minimumDistance(nums));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumDistanceBetweenThreeEqualElementsIiStrategies,
    MinimumDistanceBetweenThreeEqualElementsIiTest,
    ::testing::ValuesIn(
        MinimumDistanceBetweenThreeEqualElementsIiSolution().getStrategyNames()));

}  // namespace leetcode::problem_3741
