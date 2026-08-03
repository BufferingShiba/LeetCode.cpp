#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/number-of-students-doing-homework-at-a-given-time.h"

namespace leetcode {
namespace problem_1450 {

class NumberOfStudentsDoingHomeworkAtAGivenTimeTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  NumberOfStudentsDoingHomeworkAtAGivenTimeSolution solution_;
};

TEST_P(NumberOfStudentsDoingHomeworkAtAGivenTimeTest, Example1) {
  std::vector<int> startTime = {1, 2, 3};
  std::vector<int> endTime = {3, 2, 7};
  int queryTime = 4;
  EXPECT_EQ(solution_.busyStudent(startTime, endTime, queryTime), 1);
}

TEST_P(NumberOfStudentsDoingHomeworkAtAGivenTimeTest, Example2) {
  std::vector<int> startTime = {4};
  std::vector<int> endTime = {4};
  int queryTime = 4;
  EXPECT_EQ(solution_.busyStudent(startTime, endTime, queryTime), 1);
}

TEST_P(NumberOfStudentsDoingHomeworkAtAGivenTimeTest, SelfAuthoredBoundaryAllInclusive) {
  std::vector<int> startTime = {1, 2};
  std::vector<int> endTime = {5, 6};
  int queryTime = 2;
  EXPECT_EQ(solution_.busyStudent(startTime, endTime, queryTime), 2);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfStudentsDoingHomeworkAtAGivenTimeTestInstance,
    NumberOfStudentsDoingHomeworkAtAGivenTimeTest,
    ::testing::ValuesIn(
        NumberOfStudentsDoingHomeworkAtAGivenTimeSolution().getStrategyNames()));

}  // namespace problem_1450
}  // namespace leetcode
