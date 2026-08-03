#include <gtest/gtest.h>
#include "leetcode/problems/compute-alternating-sum.h"

using namespace leetcode::problem_3701;

class ComputeAlternatingSumTest : public ::testing::TestWithParam<std::string> {
 protected:
  ComputeAlternatingSumSolution solution;
  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(ComputeAlternatingSumTest, Example1) {
  std::vector<int> nums = {1, 3, 5, 7};
  EXPECT_EQ(solution.alternatingSum(nums), -4);
}

TEST_P(ComputeAlternatingSumTest, Example2) {
  std::vector<int> nums = {100};
  EXPECT_EQ(solution.alternatingSum(nums), 100);
}

TEST_P(ComputeAlternatingSumTest, SelfAuthoredCase1) {
  std::vector<int> nums = {2, 1, 2, 1};
  EXPECT_EQ(solution.alternatingSum(nums), 2);
}

TEST_P(ComputeAlternatingSumTest, SelfAuthoredCase2) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  EXPECT_EQ(solution.alternatingSum(nums), 3);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    ComputeAlternatingSumTest,
    ::testing::ValuesIn(ComputeAlternatingSumSolution().getStrategyNames())
);
