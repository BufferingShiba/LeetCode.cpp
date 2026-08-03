#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/reformat-date.h"

namespace leetcode::problem_1507 {

class ReformatDateTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  ReformatDateSolution solution_;
};

TEST_P(ReformatDateTest, Example1) {
  EXPECT_EQ(solution_.reformatDate("20th Oct 2052"), "2052-10-20");
}

TEST_P(ReformatDateTest, Example2) {
  EXPECT_EQ(solution_.reformatDate("6th Jun 1933"), "1933-06-06");
}

TEST_P(ReformatDateTest, Example3) {
  EXPECT_EQ(solution_.reformatDate("26th May 1960"), "1960-05-26");
}

TEST_P(ReformatDateTest, SelfAuthoredSingleDigitDay) {
  EXPECT_EQ(solution_.reformatDate("1st Jan 2000"), "2000-01-01");
}

TEST_P(ReformatDateTest, SelfAuthoredDoubleDigitDay) {
  EXPECT_EQ(solution_.reformatDate("31st Dec 2100"), "2100-12-31");
}

INSTANTIATE_TEST_SUITE_P(
    ReformatDateTestSuite, ReformatDateTest,
    ::testing::ValuesIn(ReformatDateSolution().getStrategyNames()));

}  // namespace leetcode::problem_1507
