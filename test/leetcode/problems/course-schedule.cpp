#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/course-schedule.h"

namespace leetcode {
namespace problem_207 {
namespace {

struct TestCase {
  int numCourses;
  std::vector<std::vector<int>> prerequisites;
  bool expected;
};

}  // namespace

class CourseScheduleTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CourseScheduleSolution solution;
};

TEST_P(CourseScheduleTest, Example1) {
  std::vector<std::vector<int>> prerequisites = {{1, 0}};
  EXPECT_TRUE(solution.canFinish(2, prerequisites));
}

TEST_P(CourseScheduleTest, Example2) {
  std::vector<std::vector<int>> prerequisites = {{1, 0}, {0, 1}};
  EXPECT_FALSE(solution.canFinish(2, prerequisites));
}

TEST_P(CourseScheduleTest, SelfAuthoredNoPrerequisites) {
  std::vector<std::vector<int>> prerequisites = {};
  EXPECT_TRUE(solution.canFinish(3, prerequisites));
}

TEST_P(CourseScheduleTest, SelfAuthoredDiamondAcyclic) {
  // 3 requires 0 and 1, 1 requires 0. No cycle.
  std::vector<std::vector<int>> prerequisites = {{1, 0}, {3, 0}, {3, 1}};
  EXPECT_TRUE(solution.canFinish(4, prerequisites));
}

TEST_P(CourseScheduleTest, SelfAuthoredCycleInSubgraph) {
  // Cycle among {1, 2}, course 0 independent.
  std::vector<std::vector<int>> prerequisites = {{1, 2}, {2, 1}};
  EXPECT_FALSE(solution.canFinish(3, prerequisites));
}

INSTANTIATE_TEST_SUITE_P(
    CourseScheduleStrategies, CourseScheduleTest,
    ::testing::ValuesIn(CourseScheduleSolution().getStrategyNames()));

}  // namespace problem_207
}  // namespace leetcode
