#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/number-of-senior-citizens.h"

namespace leetcode {
namespace problem_2678 {

class NumberOfSeniorCitizensTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfSeniorCitizensSolution solution;
};

TEST_P(NumberOfSeniorCitizensTest, Example1) {
  std::vector<std::string> details = {"7868190130M7522", "5303914400F9211",
                                       "9273338290F4010"};
  EXPECT_EQ(2, solution.countSeniors(details));
}

TEST_P(NumberOfSeniorCitizensTest, Example2) {
  std::vector<std::string> details = {"1313579440F2036", "2921522980M5644"};
  EXPECT_EQ(0, solution.countSeniors(details));
}

TEST_P(NumberOfSeniorCitizensTest, SelfAuthoredAllSenior) {
  std::vector<std::string> details = {"0000000000M6111", "0000000000M9900",
                                       "0000000000O6210"};
  EXPECT_EQ(3, solution.countSeniors(details));
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfSeniorCitizensTestSuite, NumberOfSeniorCitizensTest,
    ::testing::ValuesIn(NumberOfSeniorCitizensSolution().getStrategyNames()));

}  // namespace problem_2678
}  // namespace leetcode
