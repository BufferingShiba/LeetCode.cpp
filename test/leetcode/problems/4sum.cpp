#include "leetcode/problems/4sum.h"

#include <algorithm>
#include <gtest/gtest.h>

namespace leetcode {
namespace problem_18 {
namespace {

class FourSumTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FourSumSolution solution_;
};

bool SameQuadruplets(const std::vector<std::vector<int>>& a,
                     const std::vector<std::vector<int>>& b) {
  if (a.size() != b.size()) {
    return false;
  }
  auto sorted = [](std::vector<std::vector<int>> v) {
    for (auto& vec : v) std::sort(vec.begin(), vec.end());
    std::sort(v.begin(), v.end());
    return v;
  };
  return sorted(a) == sorted(b);
}

TEST_P(FourSumTest, Example1) {
  std::vector<int> nums = {1, 0, -1, 0, -2, 2};
  int target = 0;
  std::vector<std::vector<int>> expected = {
      {-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
  auto actual = solution_.fourSum(nums, target);
  EXPECT_TRUE(SameQuadruplets(actual, expected));
}

TEST_P(FourSumTest, Example2) {
  std::vector<int> nums = {2, 2, 2, 2, 2};
  int target = 8;
  std::vector<std::vector<int>> expected = {{2, 2, 2, 2}};
  auto actual = solution_.fourSum(nums, target);
  EXPECT_TRUE(SameQuadruplets(actual, expected));
}

TEST_P(FourSumTest, LessThan4Numbers) {
  std::vector<int> nums = {1, 2, 3};
  int target = 10;
  EXPECT_TRUE(solution_.fourSum(nums, target).empty());
}

TEST_P(FourSumTest, DuplicatesAcrossAll) {
  std::vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};
  int target = 0;
  std::vector<std::vector<int>> expected = {
      {-3, -2, 2, 3}, {-3, -1, 1, 3}, {-3, 0, 0, 3},
      {-3, 0, 1, 2},  {-2, -1, 0, 3}, {-2, -1, 1, 2},
      {-2, 0, 0, 2},  {-1, 0, 0, 1}};
  auto actual = solution_.fourSum(nums, target);
  EXPECT_TRUE(SameQuadruplets(actual, expected));
}

INSTANTIATE_TEST_SUITE_P(
    FourSumStrategies, FourSumTest,
    ::testing::ValuesIn(FourSumSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_18
}  // namespace leetcode
