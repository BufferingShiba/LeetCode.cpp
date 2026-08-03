#include "leetcode/problems/number-of-students-doing-homework-at-a-given-time.h"

namespace leetcode {
namespace problem_1450 {

namespace {

int busyStudentImpl(std::vector<int>& startTime, std::vector<int>& endTime,
                    int queryTime) {
  int count = 0;
  for (size_t i = 0; i < startTime.size(); ++i) {
    if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
      ++count;
    }
  }
  return count;
}

}  // namespace

NumberOfStudentsDoingHomeworkAtAGivenTimeSolution::
    NumberOfStudentsDoingHomeworkAtAGivenTimeSolution() {
  setMetaInfo({.id = 1450,
               .title = "Number of Students Doing Homework at a Given Time",
               .url = "https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/"});
  registerStrategy({.name = "LinearScan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Enumeration"}},
                   busyStudentImpl);
}

int NumberOfStudentsDoingHomeworkAtAGivenTimeSolution::busyStudent(
    std::vector<int>& startTime, std::vector<int>& endTime, int queryTime) {
  return getSolution()(startTime, endTime, queryTime);
}

}  // namespace problem_1450
}  // namespace leetcode
