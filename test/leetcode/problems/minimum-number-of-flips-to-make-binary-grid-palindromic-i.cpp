#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i.h"

namespace leetcode {
namespace problem_3239 {
namespace {

class MinimumNumberOfFlipsToMakeBinaryGridPalindromicITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumNumberOfFlipsToMakeBinaryGridPalindromicISolution solution;
};

TEST_P(MinimumNumberOfFlipsToMakeBinaryGridPalindromicITest, Example1) {
  std::vector<std::vector<int>> grid = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
  EXPECT_EQ(2, solution.minFlips(grid));
}

TEST_P(MinimumNumberOfFlipsToMakeBinaryGridPalindromicITest, Example2) {
  std::vector<std::vector<int>> grid = {{0, 1}, {0, 1}, {0, 0}};
  EXPECT_EQ(1, solution.minFlips(grid));
}

TEST_P(MinimumNumberOfFlipsToMakeBinaryGridPalindromicITest, Example3) {
  std::vector<std::vector<int>> grid = {{1}, {0}};
  EXPECT_EQ(0, solution.minFlips(grid));
}

TEST_P(MinimumNumberOfFlipsToMakeBinaryGridPalindromicITest, SelfAuthoredAlreadyPalindromic) {
  std::vector<std::vector<int>> grid = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
  EXPECT_EQ(0, solution.minFlips(grid));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumNumberOfFlipsToMakeBinaryGridPalindromicITestInstance,
    MinimumNumberOfFlipsToMakeBinaryGridPalindromicITest,
    ::testing::ValuesIn(
        MinimumNumberOfFlipsToMakeBinaryGridPalindromicISolution()
            .getStrategyNames()));

}  // namespace
}  // namespace problem_3239
}  // namespace leetcode
