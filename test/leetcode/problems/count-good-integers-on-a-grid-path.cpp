#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-good-integers-on-a-grid-path.h"

namespace leetcode::problem_3906 {

class CountGoodIntegersOnAGridPathTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CountGoodIntegersOnAGridPathSolution solution_;
};

TEST_P(CountGoodIntegersOnAGridPathTest, Example1) {
  EXPECT_EQ(2, solution_.countGoodIntegersOnPath(8, 10, "DDDRRR"));
}

TEST_P(CountGoodIntegersOnAGridPathTest, Example2) {
  EXPECT_EQ(1, solution_.countGoodIntegersOnPath(123456789, 123456790, "DDRRDR"));
}

TEST_P(CountGoodIntegersOnAGridPathTest, Example3) {
  EXPECT_EQ(0,
            solution_.countGoodIntegersOnPath(1288561398769758LL,
                                              1288561398769758LL, "RRRDDD"));
}

INSTANTIATE_TEST_SUITE_P(
    CountGoodIntegersOnAGridPathTestSuites, CountGoodIntegersOnAGridPathTest,
    ::testing::ValuesIn(CountGoodIntegersOnAGridPathSolution().getStrategyNames()));

}  // namespace leetcode::problem_3906
