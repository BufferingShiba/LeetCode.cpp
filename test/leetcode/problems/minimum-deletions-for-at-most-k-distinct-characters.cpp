#include "leetcode/problems/minimum-deletions-for-at-most-k-distinct-characters.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_3545 {

class MinimumDeletionsForAtMostKDistinctCharactersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumDeletionsForAtMostKDistinctCharactersSolution solution;
};

TEST_P(MinimumDeletionsForAtMostKDistinctCharactersTest, Example1) {
  EXPECT_EQ(1, solution.minDeletion("abc", 2));
}

TEST_P(MinimumDeletionsForAtMostKDistinctCharactersTest, Example2) {
  EXPECT_EQ(0, solution.minDeletion("aabb", 2));
}

TEST_P(MinimumDeletionsForAtMostKDistinctCharactersTest, Example3) {
  EXPECT_EQ(2, solution.minDeletion("yyyzz", 1));
}

TEST_P(MinimumDeletionsForAtMostKDistinctCharactersTest,
       SelfAuthoredAlreadyWithinLimit) {
  EXPECT_EQ(0, solution.minDeletions("aaaa", 1));
}

INSTANTIATE_TEST_SUITE_P(
    MinimumDeletionsForAtMostKDistinctCharactersTestSuite,
    MinimumDeletionsForAtMostKDistinctCharactersTest,
    ::testing::ValuesIn(
        MinimumDeletionsForAtMostKDistinctCharactersSolution()
            .getStrategyNames()));

}  // namespace problem_3545
}  // namespace leetcode
