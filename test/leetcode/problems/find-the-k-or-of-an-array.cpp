#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-k-or-of-an-array.h"

namespace leetcode {
namespace problem_2917 {
namespace {

class FindTheKOrOfAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheKOrOfAnArraySolution solution;
};

TEST_P(FindTheKOrOfAnArrayTest, Example1) {
  std::vector<int> nums{7, 12, 9, 8, 9, 15};
  int k = 4;
  EXPECT_EQ(solution.findKOr(nums, k), 9);
}

TEST_P(FindTheKOrOfAnArrayTest, Example2) {
  std::vector<int> nums{2, 12, 1, 11, 4, 5};
  int k = 6;
  EXPECT_EQ(solution.findKOr(nums, k), 0);
}

TEST_P(FindTheKOrOfAnArrayTest, Example3) {
  std::vector<int> nums{10, 8, 5, 9, 11, 6, 8};
  int k = 1;
  EXPECT_EQ(solution.findKOr(nums, k), 15);
}

TEST_P(FindTheKOrOfAnArrayTest, SelfAuthoredSingleElement) {
  std::vector<int> nums{5};
  int k = 1;
  EXPECT_EQ(solution.findKOr(nums, k), 5);
}

TEST_P(FindTheKOrOfAnArrayTest, SelfAuthoredAllZeros) {
  std::vector<int> nums{0, 0, 0};
  int k = 2;
  EXPECT_EQ(solution.findKOr(nums, k), 0);
}

INSTANTIATE_TEST_SUITE_P(
    FindTheKOrOfAnArrayTestSuite, FindTheKOrOfAnArrayTest,
    ::testing::ValuesIn(FindTheKOrOfAnArraySolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2917
}  // namespace leetcode
