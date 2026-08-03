#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/identify-the-largest-outlier-in-an-array.h"

namespace leetcode {
namespace problem_3371 {

class IdentifyTheLargestOutlierInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  IdentifyTheLargestOutlierInAnArraySolution solution_;
};

TEST_P(IdentifyTheLargestOutlierInAnArrayTest, Example1) {
  std::vector<int> nums = {2, 3, 5, 10};
  EXPECT_EQ(solution_.getLargestOutlier(nums), 10);
}

TEST_P(IdentifyTheLargestOutlierInAnArrayTest, Example2) {
  std::vector<int> nums = {-2, -1, -3, -6, 4};
  EXPECT_EQ(solution_.getLargestOutlier(nums), 4);
}

TEST_P(IdentifyTheLargestOutlierInAnArrayTest, Example3) {
  std::vector<int> nums = {1, 1, 1, 1, 1, 5, 5};
  EXPECT_EQ(solution_.getLargestOutlier(nums), 5);
}

TEST_P(IdentifyTheLargestOutlierInAnArrayTest, AllZeros) {
  std::vector<int> nums = {0, 0, 0};
  // special: [0], sum=0, outlier=0
  EXPECT_EQ(solution_.getLargestOutlier(nums), 0);
}

TEST_P(IdentifyTheLargestOutlierInAnArrayTest, NegativeCase) {
  std::vector<int> nums = {-4, -2, -2};
  // total = -8; y=-2 => x = -8 - (-4) = -4 (in array, != -2)
  // y=-4 => x = -8 - (-8) = 0 (not in array)
  // max outlier = -4
  EXPECT_EQ(solution_.getLargestOutlier(nums), -4);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    IdentifyTheLargestOutlierInAnArrayTest,
    ::testing::ValuesIn(
        IdentifyTheLargestOutlierInAnArraySolution().getStrategyNames()));

}  // namespace problem_3371
}  // namespace leetcode
