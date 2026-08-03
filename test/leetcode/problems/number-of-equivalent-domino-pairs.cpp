#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/number-of-equivalent-domino-pairs.h"

namespace leetcode::problem_1128 {

class NumberOfEquivalentDominoPairsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  NumberOfEquivalentDominoPairsSolution solution_;
};

TEST_P(NumberOfEquivalentDominoPairsTest, Example1) {
  std::vector<std::vector<int>> dominoes = {{1, 2}, {2, 1}, {3, 4}, {5, 6}};
  EXPECT_EQ(solution_.numEquivDominoPairs(dominoes), 1);
}

TEST_P(NumberOfEquivalentDominoPairsTest, Example2) {
  std::vector<std::vector<int>> dominoes = {
      {1, 2}, {1, 2}, {1, 1}, {1, 2}, {2, 2}};
  EXPECT_EQ(solution_.numEquivDominoPairs(dominoes), 3);
}

TEST_P(NumberOfEquivalentDominoPairsTest, SelfAuthoredSingleDomino) {
  std::vector<std::vector<int>> dominoes = {{3, 7}};
  EXPECT_EQ(solution_.numEquivDominoPairs(dominoes), 0);
}

TEST_P(NumberOfEquivalentDominoPairsTest, SelfAuthoredAllEquivalent) {
  std::vector<std::vector<int>> dominoes = {{2, 2}, {2, 2}, {2, 2}};
  EXPECT_EQ(solution_.numEquivDominoPairs(dominoes), 3);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfEquivalentDominoPairsTestSuite, NumberOfEquivalentDominoPairsTest,
    ::testing::ValuesIn(NumberOfEquivalentDominoPairsSolution().getStrategyNames()));

}  // namespace leetcode::problem_1128
