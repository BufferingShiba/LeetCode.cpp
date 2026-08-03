#include <gtest/gtest.h>

#include "leetcode/problems/maximum-number-of-weeks-for-which-you-can-work.h"

using namespace leetcode::problem_1953;

class MaximumNumberOfWeeksForWhichYouCanWorkTest : public testing::TestWithParam<std::string> {
 protected:
  MaximumNumberOfWeeksForWhichYouCanWorkSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MaximumNumberOfWeeksForWhichYouCanWorkTest, Example1) {
  std::vector<int> milestones = {1, 2, 3};
  EXPECT_EQ(solution.numberOfWeeks(milestones), 6);
}

TEST_P(MaximumNumberOfWeeksForWhichYouCanWorkTest, Example2) {
  std::vector<int> milestones = {5, 2, 1};
  EXPECT_EQ(solution.numberOfWeeks(milestones), 7);
}

TEST_P(MaximumNumberOfWeeksForWhichYouCanWorkTest, SelfAuthoredSingleProject) {
  std::vector<int> milestones = {1};
  EXPECT_EQ(solution.numberOfWeeks(milestones), 1);
}

TEST_P(MaximumNumberOfWeeksForWhichYouCanWorkTest, SelfAuthoredAllEqual) {
  std::vector<int> milestones = {2, 2, 2};
  EXPECT_EQ(solution.numberOfWeeks(milestones), 6);
}

TEST_P(MaximumNumberOfWeeksForWhichYouCanWorkTest, SelfAuthoredLargeDominant) {
  std::vector<int> milestones = {10, 1, 1};
  // total=12, max=10, rest=2, max>rest => 2*2+1=5
  EXPECT_EQ(solution.numberOfWeeks(milestones), 5);
}

INSTANTIATE_TEST_SUITE_P(Strategies, MaximumNumberOfWeeksForWhichYouCanWorkTest,
                         testing::ValuesIn(MaximumNumberOfWeeksForWhichYouCanWorkSolution().getStrategyNames()));
