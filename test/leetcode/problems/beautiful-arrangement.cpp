#include <gtest/gtest.h>

#include "leetcode/problems/beautiful-arrangement.h"

namespace leetcode::problem_526 {

class BeautifulArrangementTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  BeautifulArrangementSolution solution_;
};

TEST_P(BeautifulArrangementTest, OfficialExamples) {
  EXPECT_EQ(solution_.countArrangement(1), 1);
  EXPECT_EQ(solution_.countArrangement(2), 2);
}

TEST_P(BeautifulArrangementTest, SelfAuthored) {
  // n=3: [1,2,3], [2,1,3], [3,2,1] → 3
  EXPECT_EQ(solution_.countArrangement(3), 3);
  // n=4: known from OEIS / brute force
  EXPECT_EQ(solution_.countArrangement(4), 8);
}

INSTANTIATE_TEST_SUITE_P(Strategies,
                         BeautifulArrangementTest,
                         testing::ValuesIn(BeautifulArrangementSolution().getStrategyNames()));

}  // namespace leetcode::problem_526
