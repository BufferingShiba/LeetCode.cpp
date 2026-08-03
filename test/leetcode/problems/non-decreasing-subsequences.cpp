#include "leetcode/problems/non-decreasing-subsequences.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <string>

namespace leetcode::problem_491 {

namespace {

void Normalize(std::vector<std::vector<int>>& v) {
  for (auto& sub : v) {
    std::sort(sub.begin(), sub.end());
  }
  std::sort(v.begin(), v.end());
}

}  // namespace

class NonDecreasingSubsequencesTest
    : public ::testing::TestWithParam<std::string> {
 public:
  void SetUp() override { solution_.setStrategy(GetParam()); }

 protected:
  NonDecreasingSubsequencesSolution solution_;
};

TEST_P(NonDecreasingSubsequencesTest, Example1) {
  std::vector<int> nums{4, 6, 7, 7};
  std::vector<std::vector<int>> expected{
      {4, 6}, {4, 6, 7}, {4, 6, 7, 7}, {4, 7},
      {4, 7, 7}, {6, 7}, {6, 7, 7}, {7, 7}};
  auto actual = solution_.findSubsequences(nums);
  Normalize(actual);
  Normalize(expected);
  EXPECT_EQ(actual, expected);
}

TEST_P(NonDecreasingSubsequencesTest, Example2) {
  std::vector<int> nums{4, 4, 3, 2, 1};
  std::vector<std::vector<int>> expected{{4, 4}};
  auto actual = solution_.findSubsequences(nums);
  Normalize(actual);
  Normalize(expected);
  EXPECT_EQ(actual, expected);
}

TEST_P(NonDecreasingSubsequencesTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{1};
  std::vector<std::vector<int>> expected{};
  auto actual = solution_.findSubsequences(nums);
  Normalize(actual);
  Normalize(expected);
  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    NonDecreasingSubsequencesTestSuite, NonDecreasingSubsequencesTest,
    ::testing::ValuesIn(
        NonDecreasingSubsequencesSolution().getStrategyNames()));

}  // namespace leetcode::problem_491
