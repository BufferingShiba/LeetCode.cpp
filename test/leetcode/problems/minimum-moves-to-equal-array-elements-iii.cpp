#include <gtest/gtest.h>

#include "leetcode/problems/minimum-moves-to-equal-array-elements-iii.h"

#include <vector>

namespace leetcode {
namespace problem_3736 {
namespace {

std::vector<int> buildNums(std::vector<int> values) {
  return values;
}

}  // namespace

class MinimumMovesToEqualArrayElementsIiiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumMovesToEqualArrayElementsIiiSolution solution;
};

TEST_P(MinimumMovesToEqualArrayElementsIiiTest, Example1) {
  std::vector<int> nums = buildNums({2, 1, 3});
  EXPECT_EQ(solution.minMoves(nums), 3);
}

TEST_P(MinimumMovesToEqualArrayElementsIiiTest, Example2) {
  std::vector<int> nums = buildNums({4, 4, 5});
  EXPECT_EQ(solution.minMoves(nums), 2);
}

TEST_P(MinimumMovesToEqualArrayElementsIiiTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = buildNums({7});
  EXPECT_EQ(solution.minMoves(nums), 0);
}

TEST_P(MinimumMovesToEqualArrayElementsIiiTest, SelfAuthoredAllEqual) {
  std::vector<int> nums = buildNums({3, 3, 3, 3});
  EXPECT_EQ(solution.minMoves(nums), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumMovesToEqualArrayElementsIiiTestSuite,
    MinimumMovesToEqualArrayElementsIiiTest,
    ::testing::ValuesIn(MinimumMovesToEqualArrayElementsIiiSolution().getStrategyNames()));

}  // namespace problem_3736
}  // namespace leetcode
