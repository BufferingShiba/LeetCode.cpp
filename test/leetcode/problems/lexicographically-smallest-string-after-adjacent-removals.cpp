#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/lexicographically-smallest-string-after-adjacent-removals.h"

using leetcode::problem_3563::LexicographicallySmallestStringAfterAdjacentRemovalsSolution;

class LexicographicallySmallestStringAfterAdjacentRemovalsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  LexicographicallySmallestStringAfterAdjacentRemovalsSolution solution;
};

TEST_P(LexicographicallySmallestStringAfterAdjacentRemovalsTest, Example1) {
  EXPECT_EQ("a", solution.lexicographicallySmallestString("abc"));
}

TEST_P(LexicographicallySmallestStringAfterAdjacentRemovalsTest, Example2) {
  EXPECT_EQ("", solution.lexicographicallySmallestString("bcda"));
}

TEST_P(LexicographicallySmallestStringAfterAdjacentRemovalsTest, Example3) {
  EXPECT_EQ("zdce", solution.lexicographicallySmallestString("zdce"));
}

INSTANTIATE_TEST_SUITE_P(
    LexicographicallySmallestStringAfterAdjacentRemovalsTest,
    LexicographicallySmallestStringAfterAdjacentRemovalsTest,
    ::testing::ValuesIn(
        LexicographicallySmallestStringAfterAdjacentRemovalsSolution().getStrategyNames()));
