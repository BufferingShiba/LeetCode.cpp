#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/smallest-range-covering-elements-from-k-lists.h"

namespace leetcode {
namespace problem_632 {

class SmallestRangeCoveringElementsFromKListsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SmallestRangeCoveringElementsFromKListsSolution solution;
};

TEST_P(SmallestRangeCoveringElementsFromKListsTest, Example1) {
  std::vector<std::vector<int>> nums = {
      {4, 10, 15, 24, 26},
      {0, 9, 12, 20},
      {5, 18, 22, 30}};
  std::vector<int> expected = {20, 24};
  EXPECT_EQ(solution.smallestRange(nums), expected);
}

TEST_P(SmallestRangeCoveringElementsFromKListsTest, Example2) {
  std::vector<std::vector<int>> nums = {
      {1, 2, 3},
      {1, 2, 3},
      {1, 2, 3}};
  std::vector<int> expected = {1, 1};
  EXPECT_EQ(solution.smallestRange(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    SmallestRangeCoveringElementsFromKListsTest,
    testing::ValuesIn(
        SmallestRangeCoveringElementsFromKListsSolution().getStrategyNames()));

}  // namespace problem_632
}  // namespace leetcode
