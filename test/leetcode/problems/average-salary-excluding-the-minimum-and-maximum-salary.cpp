#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/average-salary-excluding-the-minimum-and-maximum-salary.h"

namespace leetcode::problem_1491 {

class AverageSalaryExcludingTheMinimumAndMaximumSalaryTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  AverageSalaryExcludingTheMinimumAndMaximumSalarySolution solution_;
};

TEST_P(AverageSalaryExcludingTheMinimumAndMaximumSalaryTest, Example1) {
  std::vector<int> salary{4000, 3000, 1000, 2000};
  EXPECT_DOUBLE_EQ(solution_.average(salary), 2500.0);
}

TEST_P(AverageSalaryExcludingTheMinimumAndMaximumSalaryTest, Example2) {
  std::vector<int> salary{1000, 2000, 3000};
  EXPECT_DOUBLE_EQ(solution_.average(salary), 2000.0);
}

TEST_P(AverageSalaryExcludingTheMinimumAndMaximumSalaryTest, SelfAuthoredThreeElements) {
  std::vector<int> salary{1000, 9999, 1000000};
  EXPECT_DOUBLE_EQ(solution_.average(salary), 9999.0);
}

TEST_P(AverageSalaryExcludingTheMinimumAndMaximumSalaryTest, SelfAuthoredMiddleValue) {
  std::vector<int> salary{1000, 2000, 3000, 4000, 5000};
  EXPECT_DOUBLE_EQ(solution_.average(salary), 3000.0);
}

INSTANTIATE_TEST_SUITE_P(
    AverageSalaryExcludingTheMinimumAndMaximumSalaryTestSuite,
    AverageSalaryExcludingTheMinimumAndMaximumSalaryTest,
    ::testing::ValuesIn(
        AverageSalaryExcludingTheMinimumAndMaximumSalarySolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_1491
