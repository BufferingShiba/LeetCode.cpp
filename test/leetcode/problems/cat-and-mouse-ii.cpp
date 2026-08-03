#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/cat-and-mouse-ii.h"

namespace leetcode::problem_1728 {

class CatAndMouseIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CatAndMouseIiSolution solution;
};

TEST_P(CatAndMouseIiTest, OfficialExample1) {
  std::vector<std::string> grid = {"####F", "#C...", "M...."};
  int catJump = 1, mouseJump = 2;
  EXPECT_EQ(solution.canMouseWin(grid, catJump, mouseJump), true);
}

TEST_P(CatAndMouseIiTest, OfficialExample2) {
  std::vector<std::string> grid = {"M.C...F"};
  int catJump = 1, mouseJump = 4;
  EXPECT_EQ(solution.canMouseWin(grid, catJump, mouseJump), true);
}

TEST_P(CatAndMouseIiTest, OfficialExample3) {
  std::vector<std::string> grid = {"M.C...F"};
  int catJump = 1, mouseJump = 3;
  EXPECT_EQ(solution.canMouseWin(grid, catJump, mouseJump), false);
}

INSTANTIATE_TEST_SUITE_P(
    CatAndMouseIiStrategies, CatAndMouseIiTest,
    testing::ValuesIn(CatAndMouseIiSolution().getStrategyNames()));

}  // namespace leetcode::problem_1728
