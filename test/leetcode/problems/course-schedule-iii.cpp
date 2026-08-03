#include <gtest/gtest.h>

#include "leetcode/problems/course-schedule-iii.h"

namespace leetcode::problem_630 {

class CourseScheduleIiiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CourseScheduleIiiSolution solution_;
};

TEST_P(CourseScheduleIiiTest, Example1) {
  std::vector<std::vector<int>> courses = {
      {100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
  EXPECT_EQ(solution_.scheduleCourse(courses), 3);
}

TEST_P(CourseScheduleIiiTest, Example2) {
  std::vector<std::vector<int>> courses = {{1, 2}};
  EXPECT_EQ(solution_.scheduleCourse(courses), 1);
}

TEST_P(CourseScheduleIiiTest, Example3) {
  std::vector<std::vector<int>> courses = {{3, 2}, {4, 3}};
  EXPECT_EQ(solution_.scheduleCourse(courses), 0);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, CourseScheduleIiiTest,
    ::testing::ValuesIn(CourseScheduleIiiSolution().getStrategyNames()));

}  // namespace leetcode::problem_630
