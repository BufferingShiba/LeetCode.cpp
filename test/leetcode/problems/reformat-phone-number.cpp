#include <gtest/gtest.h>
#include "leetcode/problems/reformat-phone-number.h"

namespace leetcode {
namespace problem_1694 {

class ReformatPhoneNumberTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ReformatPhoneNumberSolution solution;
};

TEST_P(ReformatPhoneNumberTest, Example1) {
  EXPECT_EQ("123-456", solution.reformatNumber("1-23-45 6"));
}

TEST_P(ReformatPhoneNumberTest, Example2) {
  EXPECT_EQ("123-45-67", solution.reformatNumber("123 4-567"));
}

TEST_P(ReformatPhoneNumberTest, Example3) {
  EXPECT_EQ("123-456-78", solution.reformatNumber("123 4-5678"));
}

TEST_P(ReformatPhoneNumberTest, SelfAuthoredTwoDigits) {
  EXPECT_EQ("12", solution.reformatNumber("1 2"));
}

TEST_P(ReformatPhoneNumberTest, SelfAuthoredFourDigits) {
  EXPECT_EQ("12-34", solution.reformatNumber("12-34"));
}

INSTANTIATE_TEST_SUITE_P(
    ReformatPhoneNumberTestSuite, ReformatPhoneNumberTest,
    ::testing::ValuesIn(ReformatPhoneNumberSolution().getStrategyNames()));

}  // namespace problem_1694
}  // namespace leetcode
