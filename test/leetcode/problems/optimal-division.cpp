#include <gtest/gtest.h>
#include "leetcode/problems/optimal-division.h"

using namespace leetcode::problem_553;

class OptimalDivisionTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }
  OptimalDivisionSolution solution_;
};

TEST_P(OptimalDivisionTest, Example1) {
  std::vector<int> nums = {1000, 100, 10, 2};
  EXPECT_EQ(solution_.optimalDivision(nums), "1000/(100/10/2)");
}

TEST_P(OptimalDivisionTest, Example2) {
  std::vector<int> nums = {2, 3, 4};
  EXPECT_EQ(solution_.optimalDivision(nums), "2/(3/4)");
}

TEST_P(OptimalDivisionTest, SelfAuthoredSingleElement) {
  std::vector<int> nums = {42};
  EXPECT_EQ(solution_.optimalDivision(nums), "42");
}

TEST_P(OptimalDivisionTest, SelfAuthoredTwoElements) {
  std::vector<int> nums = {7, 3};
  EXPECT_EQ(solution_.optimalDivision(nums), "7/3");
}

INSTANTIATE_TEST_SUITE_P(
  AllStrategies,
  OptimalDivisionTest,
  testing::ValuesIn(OptimalDivisionSolution().getStrategyNames())
);
