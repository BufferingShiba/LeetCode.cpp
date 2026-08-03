#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/merge-strings-alternately.h"

namespace leetcode {
namespace problem_1768 {

class MergeStringsAlternatelyTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MergeStringsAlternatelySolution solution;
};

TEST_P(MergeStringsAlternatelyTest, Example1) {
  EXPECT_EQ("apbqcr", solution.mergeAlternately("abc", "pqr"));
}

TEST_P(MergeStringsAlternatelyTest, Example2) {
  EXPECT_EQ("apbqrs", solution.mergeAlternately("ab", "pqrs"));
}

TEST_P(MergeStringsAlternatelyTest, Example3) {
  EXPECT_EQ("apbqcd", solution.mergeAlternately("abcd", "pq"));
}

INSTANTIATE_TEST_SUITE_P(
    MergeStringsAlternatelyTestSuite, MergeStringsAlternatelyTest,
    ::testing::ValuesIn(MergeStringsAlternatelySolution().getStrategyNames()));

}  // namespace problem_1768
}  // namespace leetcode
