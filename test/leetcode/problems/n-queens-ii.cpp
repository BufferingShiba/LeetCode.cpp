#include <gtest/gtest.h>

#include "leetcode/problems/n-queens-ii.h"

namespace leetcode {
namespace problem_52 {

class NQueensIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  NQueensIiSolution solution_;
};

TEST_P(NQueensIiTest, OfficialExample1) {
  EXPECT_EQ(solution_.totalNQueens(4), 2);
}

TEST_P(NQueensIiTest, OfficialExample2) {
  EXPECT_EQ(solution_.totalNQueens(1), 1);
}

TEST_P(NQueensIiTest, SelfAuthoredEdge) {
  // n = 2: no solutions
  EXPECT_EQ(solution_.totalNQueens(2), 0);
  // n = 3: no solutions
  EXPECT_EQ(solution_.totalNQueens(3), 0);
  // n = 5: known count = 10
  EXPECT_EQ(solution_.totalNQueens(5), 10);
  // n = 8: known count = 92
  EXPECT_EQ(solution_.totalNQueens(8), 92);
}

INSTANTIATE_TEST_SUITE_P(AllStrategies, NQueensIiTest,
                         ::testing::ValuesIn(NQueensIiSolution().getStrategyNames()));

}  // namespace problem_52
}  // namespace leetcode
