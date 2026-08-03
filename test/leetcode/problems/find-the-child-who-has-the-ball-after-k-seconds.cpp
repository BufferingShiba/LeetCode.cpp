#include <gtest/gtest.h>

#include "leetcode/problems/find-the-child-who-has-the-ball-after-k-seconds.h"

namespace leetcode::problem_3178 {

class FindTheChildWhoHasTheBallAfterKSecondsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindTheChildWhoHasTheBallAfterKSecondsSolution solution_;
};

TEST_P(FindTheChildWhoHasTheBallAfterKSecondsTest, Example1) {
  EXPECT_EQ(solution_.numberOfChild(3, 5), 1);
}

TEST_P(FindTheChildWhoHasTheBallAfterKSecondsTest, Example2) {
  EXPECT_EQ(solution_.numberOfChild(5, 6), 2);
}

TEST_P(FindTheChildWhoHasTheBallAfterKSecondsTest, Example3) {
  EXPECT_EQ(solution_.numberOfChild(4, 2), 2);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindTheChildWhoHasTheBallAfterKSecondsTest,
    testing::ValuesIn(
        FindTheChildWhoHasTheBallAfterKSecondsSolution().getStrategyNames()));

}  // namespace leetcode::problem_3178
