#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/height-checker.h"

namespace leetcode::problem_1051 {

class HeightCheckerTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  HeightCheckerSolution solution;
};

TEST_P(HeightCheckerTest, Example1) {
  std::vector<int> heights = {1, 1, 4, 2, 1, 3};
  EXPECT_EQ(solution.heightChecker(heights), 3);
}

TEST_P(HeightCheckerTest, Example2) {
  std::vector<int> heights = {5, 1, 2, 3, 4};
  EXPECT_EQ(solution.heightChecker(heights), 5);
}

TEST_P(HeightCheckerTest, Example3) {
  std::vector<int> heights = {1, 2, 3, 4, 5};
  EXPECT_EQ(solution.heightChecker(heights), 0);
}

TEST_P(HeightCheckerTest, SelfAuthoredAlreadySorted) {
  std::vector<int> heights = {1, 1, 1, 1};
  EXPECT_EQ(solution.heightChecker(heights), 0);
}

TEST_P(HeightCheckerTest, SelfAuthoredReversed) {
  std::vector<int> heights = {4, 3, 2, 1};
  EXPECT_EQ(solution.heightChecker(heights), 4);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    HeightCheckerTest,
    testing::ValuesIn(HeightCheckerSolution().getStrategyNames()));

}  // namespace leetcode::problem_1051
