#include <gtest/gtest.h>

#include "leetcode/problems/count-pairs-that-form-a-complete-day-ii.h"

using namespace leetcode::problem_3185;

class CountPairsThatFormACompleteDayIiTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountPairsThatFormACompleteDayIiSolution solution;
};

TEST_P(CountPairsThatFormACompleteDayIiTest, Example1) {
  std::vector<int> hours = {12, 12, 30, 24, 24};
  EXPECT_EQ(solution.countCompleteDayPairs(hours), 2);
}

TEST_P(CountPairsThatFormACompleteDayIiTest, Example2) {
  std::vector<int> hours = {72, 48, 24, 3};
  EXPECT_EQ(solution.countCompleteDayPairs(hours), 3);
}

INSTANTIATE_TEST_SUITE_P(AllStrategies, CountPairsThatFormACompleteDayIiTest,
                         testing::ValuesIn(CountPairsThatFormACompleteDayIiSolution()
                                               .getStrategyNames()));
