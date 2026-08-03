#include <gtest/gtest.h>
#include "leetcode/problems/count-distinct-numbers-on-board.h"

namespace leetcode::problem_2549 {

class CountDistinctNumbersOnBoardTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  CountDistinctNumbersOnBoardSolution solution;
};

TEST_P(CountDistinctNumbersOnBoardTest, OfficialCases) {
  EXPECT_EQ(solution.distinctIntegers(5), 4);
  EXPECT_EQ(solution.distinctIntegers(3), 2);
}

TEST_P(CountDistinctNumbersOnBoardTest, SelfAuthored) {
  EXPECT_EQ(solution.distinctIntegers(1), 1);
  EXPECT_EQ(solution.distinctIntegers(2), 1);
  EXPECT_EQ(solution.distinctIntegers(100), 99);
}

INSTANTIATE_TEST_SUITE_P(
    , CountDistinctNumbersOnBoardTest,
    testing::ValuesIn(
        CountDistinctNumbersOnBoardSolution().getStrategyNames()));

}  // namespace leetcode::problem_2549
