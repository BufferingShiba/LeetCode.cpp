#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "leetcode/problems/3sum.h"

using namespace leetcode::problem_15;

class ThreeSumTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  ThreeSumSolution solution_;
};

TEST_P(ThreeSumTest, Example1) {
  std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
  auto result = solution_.threeSum(nums);
  EXPECT_EQ(result.size(), 2);
  for (auto& t : result) std::sort(t.begin(), t.end());
  std::sort(result.begin(), result.end());
  std::vector<std::vector<int>> expected = {{-1, -1, 2}, {-1, 0, 1}};
  EXPECT_EQ(result, expected);
}

TEST_P(ThreeSumTest, Example2) {
  std::vector<int> nums = {0, 1, 1};
  auto result = solution_.threeSum(nums);
  EXPECT_TRUE(result.empty());
}

TEST_P(ThreeSumTest, Example3) {
  std::vector<int> nums = {0, 0, 0};
  auto result = solution_.threeSum(nums);
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0], std::vector<int>({0, 0, 0}));
}

TEST_P(ThreeSumTest, SelfAuthoredNoTriplet) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  auto result = solution_.threeSum(nums);
  EXPECT_TRUE(result.empty());
}

TEST_P(ThreeSumTest, SelfAuthoredAllNegative) {
  std::vector<int> nums = {-5, -4, -3, -2, -1};
  auto result = solution_.threeSum(nums);
  EXPECT_TRUE(result.empty());
}

TEST_P(ThreeSumTest, SelfAuthoredMultipleDuplicates) {
  std::vector<int> nums = {-2, 0, 0, 2, 2};
  auto result = solution_.threeSum(nums);
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0], std::vector<int>({-2, 0, 2}));
}

INSTANTIATE_TEST_SUITE_P(ThreeSum, ThreeSumTest,
                         testing::ValuesIn(ThreeSumSolution().getStrategyNames()));
