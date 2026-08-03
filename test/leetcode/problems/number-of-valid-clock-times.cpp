#include <gtest/gtest.h>
#include "leetcode/problems/number-of-valid-clock-times.h"

namespace leetcode {
namespace problem_2437 {

class NumberOfValidClockTimesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  NumberOfValidClockTimesSolution solution;
};

TEST_P(NumberOfValidClockTimesTest, Example1) {
  EXPECT_EQ(solution.countTime("?5:00"), 2);
}

TEST_P(NumberOfValidClockTimesTest, Example2) {
  EXPECT_EQ(solution.countTime("0?:0?"), 100);
}

TEST_P(NumberOfValidClockTimesTest, Example3) {
  EXPECT_EQ(solution.countTime("??:??"), 1440);
}

TEST_P(NumberOfValidClockTimesTest, SelfAuthoredNoQuestionMark) {
  EXPECT_EQ(solution.countTime("12:34"), 1);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfValidClockTimesTestSuite,
    NumberOfValidClockTimesTest,
    ::testing::ValuesIn(NumberOfValidClockTimesSolution().getStrategyNames()));

}  // namespace problem_2437
}  // namespace leetcode
