#include <gtest/gtest.h>

#include "leetcode/problems/find-occurrences-of-an-element-in-an-array.h"

namespace leetcode::problem_3159 {

namespace {
using Solution = FindOccurrencesOfAnElementInAnArraySolution;
using TestParam = std::pair<Func, std::vector<int>>;
}  // namespace

class FindOccurrencesOfAnElementInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  Solution solution_;
};

TEST_P(FindOccurrencesOfAnElementInAnArrayTest, Example1) {
  std::vector<int> nums = {1, 3, 1, 7};
  std::vector<int> queries = {1, 3, 2, 4};
  int x = 1;
  std::vector<int> expected = {0, -1, 2, -1};
  EXPECT_EQ(solution_.occurrencesOfElement(nums, queries, x), expected);
}

TEST_P(FindOccurrencesOfAnElementInAnArrayTest, Example2) {
  std::vector<int> nums = {1, 2, 3};
  std::vector<int> queries = {10};
  int x = 5;
  std::vector<int> expected = {-1};
  EXPECT_EQ(solution_.occurrencesOfElement(nums, queries, x), expected);
}

TEST_P(FindOccurrencesOfAnElementInAnArrayTest, SelfAuthoredMultipleOccurrencesFirstQuery) {
  std::vector<int> nums = {5, 1, 5, 2, 5, 3};
  std::vector<int> queries = {3};
  int x = 5;
  std::vector<int> expected = {4};
  EXPECT_EQ(solution_.occurrencesOfElement(nums, queries, x), expected);
}

INSTANTIATE_TEST_SUITE_P(
    FindOccurrencesOfAnElementInAnArrayTestSuite,
    FindOccurrencesOfAnElementInAnArrayTest,
    ::testing::ValuesIn(Solution().getStrategyNames()));

}  // namespace leetcode::problem_3159
