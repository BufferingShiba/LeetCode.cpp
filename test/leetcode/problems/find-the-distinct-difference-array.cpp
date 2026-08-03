#include "leetcode/problems/find-the-distinct-difference-array.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_2670 {
namespace {

class FindTheDistinctDifferenceArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindTheDistinctDifferenceArraySolution solution;
};

TEST_P(FindTheDistinctDifferenceArrayTest, Example1) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  std::vector<int> expected = {-3, -1, 1, 3, 5};
  EXPECT_EQ(solution.distinctDifferenceArray(nums), expected);
}

TEST_P(FindTheDistinctDifferenceArrayTest, Example2) {
  std::vector<int> nums = {3, 2, 3, 4, 2};
  std::vector<int> expected = {-2, -1, 0, 2, 3};
  EXPECT_EQ(solution.distinctDifferenceArray(nums), expected);
}

TEST_P(FindTheDistinctDifferenceArrayTest, SingleElement) {
  std::vector<int> nums = {7};
  std::vector<int> expected = {1};
  EXPECT_EQ(solution.distinctDifferenceArray(nums), expected);
}

TEST_P(FindTheDistinctDifferenceArrayTest, AllSame) {
  std::vector<int> nums = {5, 5, 5};
  std::vector<int> expected = {0, 0, 1};
  EXPECT_EQ(solution.distinctDifferenceArray(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    FindTheDistinctDifferenceArrayTestSuite,
    FindTheDistinctDifferenceArrayTest,
    ::testing::ValuesIn(FindTheDistinctDifferenceArraySolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2670
}  // namespace leetcode
