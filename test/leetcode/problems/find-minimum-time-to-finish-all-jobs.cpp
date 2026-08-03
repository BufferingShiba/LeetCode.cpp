#include "leetcode/problems/find-minimum-time-to-finish-all-jobs.h"
#include <gtest/gtest.h>
#include <vector>

namespace leetcode {
namespace problem_1723 {

class FindMinimumTimeToFinishAllJobsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }
  FindMinimumTimeToFinishAllJobsSolution solution;
};

TEST_P(FindMinimumTimeToFinishAllJobsTest, Example1) {
  std::vector<int> jobs = {3, 2, 3};
  int k = 3;
  EXPECT_EQ(3, solution.minimumTimeRequired(jobs, k));
}

TEST_P(FindMinimumTimeToFinishAllJobsTest, Example2) {
  std::vector<int> jobs = {1, 2, 4, 7, 8};
  int k = 2;
  EXPECT_EQ(11, solution.minimumTimeRequired(jobs, k));
}

TEST_P(FindMinimumTimeToFinishAllJobsTest, SelfAuthoredSingleWorker) {
  std::vector<int> jobs = {5, 7, 2};
  int k = 1;
  EXPECT_EQ(14, solution.minimumTimeRequired(jobs, k));
}

TEST_P(FindMinimumTimeToFinishAllJobsTest, SelfAuthoredMaxWorkers) {
  std::vector<int> jobs = {1, 1, 1};
  int k = 3;
  EXPECT_EQ(1, solution.minimumTimeRequired(jobs, k));
}

INSTANTIATE_TEST_SUITE_P(
    FindMinimumTimeToFinishAllJobsTestSuite,
    FindMinimumTimeToFinishAllJobsTest,
    ::testing::ValuesIn(
        FindMinimumTimeToFinishAllJobsSolution().getStrategyNames()));

}  // namespace problem_1723
}  // namespace leetcode
