#include <gtest/gtest.h>

#include "leetcode/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero.h"

namespace leetcode::problem_1466 {

class ReorderRoutesToMakeAllPathsLeadToTheCityZeroTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ReorderRoutesToMakeAllPathsLeadToTheCityZeroSolution solution;
};

TEST_P(ReorderRoutesToMakeAllPathsLeadToTheCityZeroTest, OfficialExample1) {
  int n = 6;
  std::vector<std::vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
  EXPECT_EQ(solution.minReorder(n, connections), 3);
}

TEST_P(ReorderRoutesToMakeAllPathsLeadToTheCityZeroTest, OfficialExample2) {
  int n = 5;
  std::vector<std::vector<int>> connections = {{1, 0}, {1, 2}, {3, 2}, {3, 4}};
  EXPECT_EQ(solution.minReorder(n, connections), 2);
}

TEST_P(ReorderRoutesToMakeAllPathsLeadToTheCityZeroTest, OfficialExample3) {
  int n = 3;
  std::vector<std::vector<int>> connections = {{1, 0}, {2, 0}};
  EXPECT_EQ(solution.minReorder(n, connections), 0);
}

TEST_P(ReorderRoutesToMakeAllPathsLeadToTheCityZeroTest, SelfAuthored) {
  // 最小情况：只有两个节点，0→1 需要翻转
  {
    int n = 2;
    std::vector<std::vector<int>> connections = {{0, 1}};
    EXPECT_EQ(solution.minReorder(n, connections), 1);
  }

  // 两个节点，1→0 已经指向 0，不需要翻转
  {
    int n = 2;
    std::vector<std::vector<int>> connections = {{1, 0}};
    EXPECT_EQ(solution.minReorder(n, connections), 0);
  }

  // 链状 0→1→2→3，全部需要翻转
  {
    int n = 4;
    std::vector<std::vector<int>> connections = {{0, 1}, {1, 2}, {2, 3}};
    EXPECT_EQ(solution.minReorder(n, connections), 3);
  }

  // 星形，所有边指向 0，无需翻转
  {
    int n = 4;
    std::vector<std::vector<int>> connections = {{1, 0}, {2, 0}, {3, 0}};
    EXPECT_EQ(solution.minReorder(n, connections), 0);
  }
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    ReorderRoutesToMakeAllPathsLeadToTheCityZeroTest,
    testing::ValuesIn(
        ReorderRoutesToMakeAllPathsLeadToTheCityZeroSolution().getStrategyNames()));

}  // namespace leetcode::problem_1466
