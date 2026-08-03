#include "leetcode/problems/course-schedule-iv.h"

#include <gtest/gtest.h>

namespace leetcode {
namespace problem_1462 {

class CourseScheduleIvTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CourseScheduleIvSolution solution_;
};

TEST_P(CourseScheduleIvTest, Example1) {
  int numCourses = 2;
  std::vector<std::vector<int>> prerequisites = {{1, 0}};
  std::vector<std::vector<int>> queries = {{0, 1}, {1, 0}};
  std::vector<bool> expected = {false, true};
  EXPECT_EQ(expected, solution_.checkIfPrerequisite(numCourses, prerequisites, queries));
}

TEST_P(CourseScheduleIvTest, Example2) {
  int numCourses = 2;
  std::vector<std::vector<int>> prerequisites = {};
  std::vector<std::vector<int>> queries = {{1, 0}, {0, 1}};
  std::vector<bool> expected = {false, false};
  EXPECT_EQ(expected, solution_.checkIfPrerequisite(numCourses, prerequisites, queries));
}

TEST_P(CourseScheduleIvTest, Example3) {
  int numCourses = 3;
  std::vector<std::vector<int>> prerequisites = {{1, 2}, {1, 0}, {2, 0}};
  std::vector<std::vector<int>> queries = {{1, 0}, {1, 2}};
  std::vector<bool> expected = {true, true};
  EXPECT_EQ(expected, solution_.checkIfPrerequisite(numCourses, prerequisites, queries));
}

TEST_P(CourseScheduleIvTest, SelfAuthoredIndirectPrereqChain) {
  int numCourses = 4;
  std::vector<std::vector<int>> prerequisites = {{0, 1}, {1, 2}, {2, 3}};
  std::vector<std::vector<int>> queries = {{0, 3}, {1, 3}, {3, 0}, {0, 2}};
  std::vector<bool> expected = {true, true, false, true};
  EXPECT_EQ(expected, solution_.checkIfPrerequisite(numCourses, prerequisites, queries));
}

INSTANTIATE_TEST_SUITE_P(
    CourseScheduleIvTestSuite,
    CourseScheduleIvTest,
    ::testing::ValuesIn(CourseScheduleIvSolution().getStrategyNames()));

}  // namespace problem_1462
}  // namespace leetcode
