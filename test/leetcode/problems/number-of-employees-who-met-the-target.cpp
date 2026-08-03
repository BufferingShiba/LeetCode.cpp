#include <gtest/gtest.h>

#include "leetcode/problems/number-of-employees-who-met-the-target.h"

#include <string>
#include <vector>

namespace leetcode::problem_2798 {

class NumberOfEmployeesWhoMetTheTargetTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  NumberOfEmployeesWhoMetTheTargetSolution solution_;
};

TEST_P(NumberOfEmployeesWhoMetTheTargetTest, Example1) {
  std::vector<int> hours{0, 1, 2, 3, 4};
  int target = 2;
  EXPECT_EQ(3, solution_.numberOfEmployeesWhoMetTarget(hours, target));
}

TEST_P(NumberOfEmployeesWhoMetTheTargetTest, Example2) {
  std::vector<int> hours{5, 1, 4, 2, 2};
  int target = 6;
  EXPECT_EQ(0, solution_.numberOfEmployeesWhoMetTarget(hours, target));
}

TEST_P(NumberOfEmployeesWhoMetTheTargetTest, SelfAuthoredAllMeetsTarget) {
  std::vector<int> hours{3, 3, 3};
  int target = 3;
  EXPECT_EQ(3, solution_.numberOfEmployeesWhoMetTarget(hours, target));
}

TEST_P(NumberOfEmployeesWhoMetTheTargetTest, SelfAuthoredNoneMeetTarget) {
  std::vector<int> hours{0, 1};
  int target = 2;
  EXPECT_EQ(0, solution_.numberOfEmployeesWhoMetTarget(hours, target));
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfEmployeesWhoMetTheTargetStrategies,
    NumberOfEmployeesWhoMetTheTargetTest,
    ::testing::ValuesIn(
        NumberOfEmployeesWhoMetTheTargetSolution().getStrategyNames()));

}  // namespace leetcode::problem_2798
