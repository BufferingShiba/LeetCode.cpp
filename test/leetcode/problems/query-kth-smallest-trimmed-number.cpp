#include "leetcode/problems/query-kth-smallest-trimmed-number.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2343 {
namespace {

class QueryKthSmallestTrimmedNumberTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  QueryKthSmallestTrimmedNumberSolution solution;
};

TEST_P(QueryKthSmallestTrimmedNumberTest, Example1) {
  std::vector<std::string> nums = {"102", "473", "251", "814"};
  std::vector<std::vector<int>> queries = {{1, 1}, {2, 3}, {4, 2}, {1, 2}};
  std::vector<int> expected = {2, 2, 1, 0};
  EXPECT_EQ(solution.smallestTrimmedNumbers(nums, queries), expected);
}

TEST_P(QueryKthSmallestTrimmedNumberTest, Example2) {
  std::vector<std::string> nums = {"24", "37", "96", "04"};
  std::vector<std::vector<int>> queries = {{2, 1}, {2, 2}};
  std::vector<int> expected = {3, 0};
  EXPECT_EQ(solution.smallestTrimmedNumbers(nums, queries), expected);
}

TEST_P(QueryKthSmallestTrimmedNumberTest, SingleElement) {
  std::vector<std::string> nums = {"000"};
  std::vector<std::vector<int>> queries = {{1, 3}};
  std::vector<int> expected = {0};
  EXPECT_EQ(solution.smallestTrimmedNumbers(nums, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    QueryKthSmallestTrimmedNumberTestSuite,
    QueryKthSmallestTrimmedNumberTest,
    ::testing::ValuesIn(QueryKthSmallestTrimmedNumberSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2343
}  // namespace leetcode
