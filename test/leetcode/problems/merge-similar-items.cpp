#include <gtest/gtest.h>

#include <limits>
#include <string>
#include <vector>

#include "leetcode/problems/merge-similar-items.h"

namespace leetcode {
namespace problem_2363 {
namespace {

class MergeSimilarItemsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MergeSimilarItemsSolution solution;
};

TEST_P(MergeSimilarItemsTest, Example1) {
  std::vector<std::vector<int>> items1 = {{1, 1}, {4, 5}, {3, 8}};
  std::vector<std::vector<int>> items2 = {{3, 1}, {1, 5}};
  std::vector<std::vector<int>> expected = {{1, 6}, {3, 9}, {4, 5}};
  EXPECT_EQ(solution.mergeSimilarItems(items1, items2), expected);
}

TEST_P(MergeSimilarItemsTest, Example2) {
  std::vector<std::vector<int>> items1 = {{1, 1}, {3, 2}, {2, 3}};
  std::vector<std::vector<int>> items2 = {{2, 1}, {3, 2}, {1, 3}};
  std::vector<std::vector<int>> expected = {{1, 4}, {2, 4}, {3, 4}};
  EXPECT_EQ(solution.mergeSimilarItems(items1, items2), expected);
}

TEST_P(MergeSimilarItemsTest, Example3) {
  std::vector<std::vector<int>> items1 = {{1, 3}, {2, 2}};
  std::vector<std::vector<int>> items2 = {{7, 1}, {2, 2}, {1, 4}};
  std::vector<std::vector<int>> expected = {{1, 7}, {2, 4}, {7, 1}};
  EXPECT_EQ(solution.mergeSimilarItems(items1, items2), expected);
}

TEST_P(MergeSimilarItemsTest, SelfAuthoredNoOverlap) {
  std::vector<std::vector<int>> items1 = {{1, 2}, {3, 4}};
  std::vector<std::vector<int>> items2 = {{5, 6}, {7, 8}};
  std::vector<std::vector<int>> expected = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  EXPECT_EQ(solution.mergeSimilarItems(items1, items2), expected);
}

INSTANTIATE_TEST_SUITE_P(
    MergeSimilarItemsTestSuite,
    MergeSimilarItemsTest,
    ::testing::ValuesIn(MergeSimilarItemsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2363
}  // namespace leetcode
