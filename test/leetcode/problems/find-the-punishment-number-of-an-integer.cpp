#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-the-punishment-number-of-an-integer.h"

namespace leetcode {
namespace problem_2698 {

class FindThePunishmentNumberOfAnIntegerTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindThePunishmentNumberOfAnIntegerSolution solution;
};

TEST_P(FindThePunishmentNumberOfAnIntegerTest, Example1) {
  EXPECT_EQ(solution.punishmentNumber(10), 182);
}

TEST_P(FindThePunishmentNumberOfAnIntegerTest, Example2) {
  EXPECT_EQ(solution.punishmentNumber(37), 1478);
}

TEST_P(FindThePunishmentNumberOfAnIntegerTest, SelfAuthoredEdgeN1) {
  // i=1 only: 1*1=1 partitions to [1] == 1.
  EXPECT_EQ(solution.punishmentNumber(1), 1);
}

INSTANTIATE_TEST_SUITE_P(
    FindThePunishmentNumberOfAnIntegerTestParam,
    FindThePunishmentNumberOfAnIntegerTest,
    ::testing::ValuesIn(FindThePunishmentNumberOfAnIntegerSolution().getStrategyNames()));

}  // namespace problem_2698
}  // namespace leetcode
