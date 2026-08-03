#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/number-of-people-aware-of-a-secret.h"

namespace leetcode::problem_2327 {

class NumberOfPeopleAwareOfASecretTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfPeopleAwareOfASecretSolution solution;
};

TEST_P(NumberOfPeopleAwareOfASecretTest, Example1) {
  EXPECT_EQ(solution.peopleAwareOfSecret(6, 2, 4), 5);
}

TEST_P(NumberOfPeopleAwareOfASecretTest, Example2) {
  EXPECT_EQ(solution.peopleAwareOfSecret(4, 1, 3), 6);
}

TEST_P(NumberOfPeopleAwareOfASecretTest, SelfAuthoredMinimalCase) {
  EXPECT_EQ(solution.peopleAwareOfSecret(2, 1, 2), 2);
}

TEST_P(NumberOfPeopleAwareOfASecretTest, SelfAuthoredDelayIgnoresFirstShare) {
  EXPECT_EQ(solution.peopleAwareOfSecret(3, 2, 3), 2);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfPeopleAwareOfASecretTestSuite,
    NumberOfPeopleAwareOfASecretTest,
    ::testing::ValuesIn(NumberOfPeopleAwareOfASecretSolution().getStrategyNames()));

}  // namespace leetcode::problem_2327
