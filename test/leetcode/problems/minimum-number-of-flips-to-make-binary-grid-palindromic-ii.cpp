#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-ii.h"

namespace leetcode::problem_3240 {

class MinimumNumberOfFlipsToMakeBinaryGridPalindromicIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumNumberOfFlipsToMakeBinaryGridPalindromicIiSolution solution;
};

TEST_P(MinimumNumberOfFlipsToMakeBinaryGridPalindromicIiTest, Example1) {
  std::vector<std::vector<int>> grid = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  EXPECT_EQ(solution.minFlips(grid), 3);
}

TEST_P(MinimumNumberOfFlipsToMakeBinaryGridPalindromicIiTest, Example2) {
  std::vector<std::vector<int>> grid = {{0, 1}, {0, 1}, {0, 0}};
  EXPECT_EQ(solution.minFlips(grid), 2);
}

TEST_P(MinimumNumberOfFlipsToMakeBinaryGridPalindromicIiTest, Example3) {
  std::vector<std::vector<int>> grid = {{1}, {1}};
  EXPECT_EQ(solution.minFlips(grid), 2);
}

TEST_P(MinimumNumberOfFlipsToMakeBinaryGridPalindromicIiTest, SingleOne) {
  std::vector<std::vector<int>> grid = {{1}};
  // [[1]]: trivially palindromic but total ones=1 is not divisible by 4.
  // Flip 1->0 to reach 0 ones (divisible by 4), cost 1.
  EXPECT_EQ(solution.minFlips(grid), 1);
}

TEST_P(MinimumNumberOfFlipsToMakeBinaryGridPalindromicIiTest, SingleZero) {
  std::vector<std::vector<int>> grid = {{0}};
  EXPECT_EQ(solution.minFlips(grid), 0);
}

TEST_P(MinimumNumberOfFlipsToMakeBinaryGridPalindromicIiTest, TwoByTwo) {
  std::vector<std::vector<int>> grid = {{1, 0}, {0, 1}};
  // Symmetric group all four cells: ones=2 -> cost 2, total 1s=4 -> ok
  EXPECT_EQ(solution.minFlips(grid), 2);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumNumberOfFlipsToMakeBinaryGridPalindromicIiTestSuite,
    MinimumNumberOfFlipsToMakeBinaryGridPalindromicIiTest,
    ::testing::ValuesIn(
        MinimumNumberOfFlipsToMakeBinaryGridPalindromicIiSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_3240
