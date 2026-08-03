#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-good-people-based-on-statements.h"

namespace leetcode {
namespace problem_2151 {
namespace {

using MaximumGoodPeopleBasedOnStatementsTestParam = std::string;

}  // namespace

class MaximumGoodPeopleBasedOnStatementsTest
    : public ::testing::TestWithParam<MaximumGoodPeopleBasedOnStatementsTestParam> {
 protected:
  MaximumGoodPeopleBasedOnStatementsSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MaximumGoodPeopleBasedOnStatementsTest, Example1) {
  std::vector<std::vector<int>> statements = {
      {2, 1, 2}, {1, 2, 2}, {2, 0, 2}};
  EXPECT_EQ(solution.maximumGood(statements), 2);
}

TEST_P(MaximumGoodPeopleBasedOnStatementsTest, Example2) {
  std::vector<std::vector<int>> statements = {{2, 0}, {0, 2}};
  EXPECT_EQ(solution.maximumGood(statements), 1);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumGoodPeopleBasedOnStatementsTestSuite,
    MaximumGoodPeopleBasedOnStatementsTest,
    ::testing::ValuesIn(
        MaximumGoodPeopleBasedOnStatementsSolution().getStrategyNames()));

}  // namespace problem_2151
}  // namespace leetcode
