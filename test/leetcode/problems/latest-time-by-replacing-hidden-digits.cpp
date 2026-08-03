#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "leetcode/problems/latest-time-by-replacing-hidden-digits.h"

namespace leetcode {
namespace problem_1736 {
namespace {

class LatestTimeByReplacingHiddenDigitsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  LatestTimeByReplacingHiddenDigitsSolution solution;
};

TEST_P(LatestTimeByReplacingHiddenDigitsTest, Example1) {
  EXPECT_EQ(solution.maximumTime("2?:?0"), "23:50");
}

TEST_P(LatestTimeByReplacingHiddenDigitsTest, Example2) {
  EXPECT_EQ(solution.maximumTime("0?:3?"), "09:39");
}

TEST_P(LatestTimeByReplacingHiddenDigitsTest, Example3) {
  EXPECT_EQ(solution.maximumTime("1?:22"), "19:22");
}

TEST_P(LatestTimeByReplacingHiddenDigitsTest, SelfAuthoredAllQuestion) {
  EXPECT_EQ(solution.maximumTime("??:??"), "23:59");
}

TEST_P(LatestTimeByReplacingHiddenDigitsTest, SelfAuthoredHourConstraint) {
  EXPECT_EQ(solution.maximumTime("?4:?0"), "14:50");
}

INSTANTIATE_TEST_SUITE_P(
    LatestTimeByReplacingHiddenDigitsTestSuite,
    LatestTimeByReplacingHiddenDigitsTest,
    ::testing::ValuesIn(
        LatestTimeByReplacingHiddenDigitsSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1736
}  // namespace leetcode
