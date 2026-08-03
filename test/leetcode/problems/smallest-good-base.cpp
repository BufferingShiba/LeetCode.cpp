#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/smallest-good-base.h"

namespace leetcode {
namespace problem_483 {

class SmallestGoodBaseTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SmallestGoodBaseSolution solution;
};

TEST_P(SmallestGoodBaseTest, Example1) {
  EXPECT_EQ("3", solution.smallestGoodBase("13"));
}

TEST_P(SmallestGoodBaseTest, Example2) {
  EXPECT_EQ("8", solution.smallestGoodBase("4681"));
}

TEST_P(SmallestGoodBaseTest, Example3) {
  EXPECT_EQ("999999999999999999", solution.smallestGoodBase("1000000000000000000"));
}

TEST_P(SmallestGoodBaseTest, SelfAuthorednIs3) {
  // 3 base 2 is 11.
  EXPECT_EQ("2", solution.smallestGoodBase("3"));
}

TEST_P(SmallestGoodBaseTest, SelfAuthorednIs7) {
  // 7 base 2 is 111.
  EXPECT_EQ("2", solution.smallestGoodBase("7"));
}

INSTANTIATE_TEST_SUITE_P(SmallestGoodBaseTestSuite, SmallestGoodBaseTest,
                         ::testing::ValuesIn(SmallestGoodBaseSolution().getStrategyNames()));

}  // namespace problem_483
}  // namespace leetcode
