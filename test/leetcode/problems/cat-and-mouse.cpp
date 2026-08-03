#include <gtest/gtest.h>

#include "leetcode/problems/cat-and-mouse.h"

namespace leetcode::problem_913 {

class CatAndMouseTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CatAndMouseSolution solution;
};

TEST_P(CatAndMouseTest, Example1) {
  std::vector<std::vector<int>> graph = {
      {2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}};
  EXPECT_EQ(0, solution.getSolution()(graph));
}

TEST_P(CatAndMouseTest, Example2) {
  std::vector<std::vector<int>> graph = {{1, 3}, {0}, {3}, {0, 2}};
  EXPECT_EQ(1, solution.getSolution()(graph));
}

TEST_P(CatAndMouseTest, MouseReachesHoleFirst) {
  // Mouse (1) can move directly to hole (0).
  std::vector<std::vector<int>> graph = {{1, 2}, {0, 2}, {0, 1}};
  EXPECT_EQ(1, solution.getSolution()(graph));
}

TEST_P(CatAndMouseTest, CatTrapsMouse) {
  // Degenerate two-node active game; mouse wins immediately via hole.
  std::vector<std::vector<int>> graph = {{1, 2}, {0, 2}, {0, 1}};
  EXPECT_EQ(1, solution.getSolution()(graph));
}


// LeetCode 失败用例: WrongAnswerCase1
TEST_P(CatAndMouseTest, WrongAnswerCase1) {
  // 输入: graph = [[2,3],[2],[0,1],[0,4],[3]], 期望: 2 (猫赢)
    // 老鼠在1只能移到2(=猫位置)被捕获。
    std::vector<std::vector<int>> graph = {{2, 3}, {2}, {0, 1}, {0, 4}, {3}};
    EXPECT_EQ(2, solution.getSolution()(graph));
}
INSTANTIATE_TEST_SUITE_P(
    CatAndMouseTestSuite, CatAndMouseTest,
    ::testing::ValuesIn(CatAndMouseSolution().getStrategyNames()));

}  // namespace leetcode::problem_913
