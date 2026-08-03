#include <gtest/gtest.h>

#include "leetcode/problems/permutation-difference-between-two-strings.h"

namespace leetcode::problem_3146 {

class PermutationDifferenceBetweenTwoStringsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  PermutationDifferenceBetweenTwoStringsSolution solution;
};

TEST_P(PermutationDifferenceBetweenTwoStringsTest, Example1) {
  EXPECT_EQ(solution.findPermutationDifference("abc", "bac"), 2);
}

TEST_P(PermutationDifferenceBetweenTwoStringsTest, Example2) {
  EXPECT_EQ(solution.findPermutationDifference("abcde", "edbac"), 12);
}

TEST_P(PermutationDifferenceBetweenTwoStringsTest, SelfAuthoredSingleChar) {
  EXPECT_EQ(solution.findPermutationDifference("a", "a"), 0);
}

INSTANTIATE_TEST_SUITE_P(
    PermutationDifferenceBetweenTwoStringsTest,
    PermutationDifferenceBetweenTwoStringsTest,
    ::testing::ValuesIn(
        PermutationDifferenceBetweenTwoStringsSolution().getStrategyNames()));

}  // namespace leetcode::problem_3146
