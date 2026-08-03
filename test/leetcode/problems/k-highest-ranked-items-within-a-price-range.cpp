#include "leetcode/problems/k-highest-ranked-items-within-a-price-range.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2146 {

class KHighestRankedItemsWithinAPriceRangeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  KHighestRankedItemsWithinAPriceRangeSolution solution;
};

TEST_P(KHighestRankedItemsWithinAPriceRangeTest, Example1) {
  std::vector<std::vector<int>> grid = {{1, 2, 0, 1},
                                        {1, 3, 0, 1},
                                        {0, 2, 5, 1}};
  std::vector<int> pricing = {2, 5};
  std::vector<int> start = {0, 0};
  int k = 3;
  std::vector<std::vector<int>> expected = {{0, 1}, {1, 1}, {2, 1}};
  EXPECT_EQ(solution.highestRankedKItems(grid, pricing, start, k), expected);
}

TEST_P(KHighestRankedItemsWithinAPriceRangeTest, Example2) {
  std::vector<std::vector<int>> grid = {{1, 2, 0, 1},
                                        {1, 3, 3, 1},
                                        {0, 2, 5, 1}};
  std::vector<int> pricing = {2, 3};
  std::vector<int> start = {2, 3};
  int k = 2;
  std::vector<std::vector<int>> expected = {{2, 1}, {1, 2}};
  EXPECT_EQ(solution.highestRankedKItems(grid, pricing, start, k), expected);
}

TEST_P(KHighestRankedItemsWithinAPriceRangeTest, Example3) {
  std::vector<std::vector<int>> grid = {{1, 1, 1}, {0, 0, 1}, {2, 3, 4}};
  std::vector<int> pricing = {2, 3};
  std::vector<int> start = {0, 0};
  int k = 3;
  std::vector<std::vector<int>> expected = {{2, 1}, {2, 0}};
  EXPECT_EQ(solution.highestRankedKItems(grid, pricing, start, k), expected);
}

TEST_P(KHighestRankedItemsWithinAPriceRangeTest, SelfAuthoredStartWithinRange) {
  std::vector<std::vector<int>> grid = {{2, 0}, {0, 1}};
  std::vector<int> pricing = {2, 2};
  std::vector<int> start = {0, 0};
  int k = 5;
  // Start cell has price 2 (within range) and distance 0.
  std::vector<std::vector<int>> expected = {{0, 0}};
  EXPECT_EQ(solution.highestRankedKItems(grid, pricing, start, k), expected);
}

INSTANTIATE_TEST_SUITE_P(
    KHighestRankedItemsWithinAPriceRangeTest,
    KHighestRankedItemsWithinAPriceRangeTest,
    ::testing::ValuesIn(
        KHighestRankedItemsWithinAPriceRangeSolution().getStrategyNames()));

}  // namespace problem_2146
}  // namespace leetcode
