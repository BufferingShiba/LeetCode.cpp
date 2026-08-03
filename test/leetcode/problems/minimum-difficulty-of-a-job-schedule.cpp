#include <gtest/gtest.h>

#include "leetcode/problems/minimum-difficulty-of-a-job-schedule.h"

namespace leetcode {
namespace problem_1335 {

class MinimumDifficultyOfAJobScheduleTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumDifficultyOfAJobScheduleSolution solution_;
};

TEST_P(MinimumDifficultyOfAJobScheduleTest, Example1) {
  std::vector<int> jobDifficulty = {6, 5, 4, 3, 2, 1};
  int d = 2;
  EXPECT_EQ(solution_.minDifficulty(jobDifficulty, d), 7);
}

TEST_P(MinimumDifficultyOfAJobScheduleTest, Example2) {
  std::vector<int> jobDifficulty = {9, 9, 9};
  int d = 4;
  EXPECT_EQ(solution_.minDifficulty(jobDifficulty, d), -1);
}

TEST_P(MinimumDifficultyOfAJobScheduleTest, Example3) {
  std::vector<int> jobDifficulty = {1, 1, 1};
  int d = 3;
  EXPECT_EQ(solution_.minDifficulty(jobDifficulty, d), 3);
}

TEST_P(MinimumDifficultyOfAJobScheduleTest, SelfAuthoredSingleDay) {
  std::vector<int> jobDifficulty = {7, 1, 7, 1, 7, 1};
  int d = 1;
  // All jobs in one day, difficulty = max = 7
  EXPECT_EQ(solution_.minDifficulty(jobDifficulty, d), 7);
}

TEST_P(MinimumDifficultyOfAJobScheduleTest, SelfAuthoredOneJobPerDay) {
  std::vector<int> jobDifficulty = {3, 1, 4, 1, 5};
  int d = 5;
  // Each job on its own day, sum = 3+1+4+1+5 = 14
  EXPECT_EQ(solution_.minDifficulty(jobDifficulty, d), 14);
}

TEST_P(MinimumDifficultyOfAJobScheduleTest, SelfAuthoredNotEnoughJobs) {
  std::vector<int> jobDifficulty = {5, 5, 5};
  int d = 5;
  EXPECT_EQ(solution_.minDifficulty(jobDifficulty, d), -1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumDifficultyOfAJobScheduleTest,
    testing::ValuesIn(
        MinimumDifficultyOfAJobScheduleSolution().getStrategyNames()));

}  // namespace problem_1335
}  // namespace leetcode
