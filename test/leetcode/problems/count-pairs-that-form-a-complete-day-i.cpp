#include "leetcode/problems/count-pairs-that-form-a-complete-day-i.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode::problem_3184 {

class CountPairsThatFormACompleteDayITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountPairsThatFormACompleteDayISolution solution;
};

TEST_P(CountPairsThatFormACompleteDayITest, Example1) {
  std::vector<int> hours{12, 12, 30, 24, 24};
  EXPECT_EQ(solution.countCompleteDayPairs(hours), 2);
}

TEST_P(CountPairsThatFormACompleteDayITest, Example2) {
  std::vector<int> hours{72, 48, 24, 3};
  EXPECT_EQ(solution.countCompleteDayPairs(hours), 3);
}

TEST_P(CountPairsThatFormACompleteDayITest, SelfAuthoredAllMultipleOf24) {
  std::vector<int> hours{24, 48, 72, 96};
  // all pairs are complete days: C(4,2) = 6
  EXPECT_EQ(solution.countCompleteDayPairs(hours), 6);
}

TEST_P(CountPairsThatFormACompleteDayITest, SelfAuthoredNoPairs) {
  std::vector<int> hours{1, 2, 3};
  EXPECT_EQ(solution.countCompleteDayPairs(hours), 0);
}

INSTANTIATE_TEST_SUITE_P(
    CountPairsThatFormACompleteDayITestSuite,
    CountPairsThatFormACompleteDayITest,
    ::testing::ValuesIn(CountPairsThatFormACompleteDayISolution().getStrategyNames()));

}  // namespace leetcode::problem_3184
