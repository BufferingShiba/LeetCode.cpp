#include <gtest/gtest.h>

#include "leetcode/problems/possible-bipartition.h"

namespace leetcode {
namespace problem_886 {

class PossibleBipartitionTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  PossibleBipartitionSolution solution_;
};

TEST_P(PossibleBipartitionTest, Example1) {
  int n = 4;
  std::vector<std::vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 4}};
  EXPECT_TRUE(solution_.possibleBipartition(n, dislikes));
}

TEST_P(PossibleBipartitionTest, Example2) {
  int n = 3;
  std::vector<std::vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 3}};
  EXPECT_FALSE(solution_.possibleBipartition(n, dislikes));
}

TEST_P(PossibleBipartitionTest, SelfAuthoredSinglePerson) {
  int n = 1;
  std::vector<std::vector<int>> dislikes;
  EXPECT_TRUE(solution_.possibleBipartition(n, dislikes));
}

TEST_P(PossibleBipartitionTest, SelfAuthoredNoDislikes) {
  int n = 2000;
  std::vector<std::vector<int>> dislikes;
  EXPECT_TRUE(solution_.possibleBipartition(n, dislikes));
}

TEST_P(PossibleBipartitionTest, SelfAuthoredTwoDisconnectedComponents) {
  int n = 6;
  std::vector<std::vector<int>> dislikes = {{1, 2}, {3, 4}, {5, 6}};
  EXPECT_TRUE(solution_.possibleBipartition(n, dislikes));
}

TEST_P(PossibleBipartitionTest, SelfAuthoredOddCycle) {
  int n = 5;
  std::vector<std::vector<int>> dislikes = {
      {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 1}};
  EXPECT_FALSE(solution_.possibleBipartition(n, dislikes));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, PossibleBipartitionTest,
    testing::ValuesIn(PossibleBipartitionSolution().getStrategyNames()));

}  // namespace problem_886
}  // namespace leetcode
