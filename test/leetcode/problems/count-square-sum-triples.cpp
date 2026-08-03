#include <gtest/gtest.h>

#include "leetcode/problems/count-square-sum-triples.h"

using namespace leetcode::problem_1925;

class CountSquareSumTriplesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  CountSquareSumTriplesSolution solution_;
};

TEST_P(CountSquareSumTriplesTest, OfficialExamples) {
  EXPECT_EQ(solution_.countTriples(5), 2);
  EXPECT_EQ(solution_.countTriples(10), 4);
}

TEST_P(CountSquareSumTriplesTest, SelfAuthored) {
  // n=1: no triples (need a,b,c >= 1 and a^2+b^2=c^2, minimum is 3,4,5)
  EXPECT_EQ(solution_.countTriples(1), 0);
  // n=2: still none
  EXPECT_EQ(solution_.countTriples(2), 0);
  // n=3: none
  EXPECT_EQ(solution_.countTriples(3), 0);
}

INSTANTIATE_TEST_SUITE_P(Strategies, CountSquareSumTriplesTest,
                         ::testing::ValuesIn(
                             CountSquareSumTriplesSolution().getStrategyNames()));
