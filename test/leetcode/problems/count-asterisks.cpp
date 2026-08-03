#include <gtest/gtest.h>

#include "leetcode/problems/count-asterisks.h"

namespace leetcode {
namespace problem_2315 {

class CountAsterisksTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  CountAsterisksSolution solution;
};

TEST_P(CountAsterisksTest, Example1) {
  EXPECT_EQ(solution.countAsterisks("l|*e*et|c**o|*de|"), 2);
}

TEST_P(CountAsterisksTest, Example2) {
  EXPECT_EQ(solution.countAsterisks("iamprogrammer"), 0);
}

TEST_P(CountAsterisksTest, Example3) {
  EXPECT_EQ(solution.countAsterisks("yo|uar|e**|b|e***au|tifu|l"), 5);
}

TEST_P(CountAsterisksTest, SelfAuthored) {
  EXPECT_EQ(solution.countAsterisks(""), 0);
  EXPECT_EQ(solution.countAsterisks("*"), 1);
  EXPECT_EQ(solution.countAsterisks("|*|"), 0);
  EXPECT_EQ(solution.countAsterisks("*|*|*"), 2);
  EXPECT_EQ(solution.countAsterisks("a*b|c*d|e*f"), 2);
}

INSTANTIATE_TEST_SUITE_P(Strategies, CountAsterisksTest,
                         ::testing::ValuesIn(
                             CountAsterisksSolution().getStrategyNames()));

}  // namespace problem_2315
}  // namespace leetcode
