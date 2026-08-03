#include <gtest/gtest.h>

#include "leetcode/problems/smallest-even-multiple.h"

namespace leetcode::problem_2413 {

class SmallestEvenMultipleTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SmallestEvenMultipleSolution solution;
};

TEST_P(SmallestEvenMultipleTest, OfficialExamples) {
  EXPECT_EQ(solution.smallestEvenMultiple(5), 10);
  EXPECT_EQ(solution.smallestEvenMultiple(6), 6);
}

TEST_P(SmallestEvenMultipleTest, SelfAuthored) {
  EXPECT_EQ(solution.smallestEvenMultiple(1), 2);
  EXPECT_EQ(solution.smallestEvenMultiple(2), 2);
  EXPECT_EQ(solution.smallestEvenMultiple(150), 150);
}

INSTANTIATE_TEST_SUITE_P(Strategies, SmallestEvenMultipleTest,
                         testing::ValuesIn(SmallestEvenMultipleSolution().getStrategyNames()));

}  // namespace leetcode::problem_2413
