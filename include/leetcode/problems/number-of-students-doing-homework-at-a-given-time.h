#ifndef LEETCODE_PROBLEMS_NUMBER_OF_STUDENTS_DOING_HOMEWORK_AT_A_GIVEN_TIME_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_STUDENTS_DOING_HOMEWORK_AT_A_GIVEN_TIME_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1450 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&, int)>;

class NumberOfStudentsDoingHomeworkAtAGivenTimeSolution
    : public SolutionBase<Func> {
 public:
  NumberOfStudentsDoingHomeworkAtAGivenTimeSolution();

  // LeetCode interface
  int busyStudent(std::vector<int>& startTime, std::vector<int>& endTime,
                  int queryTime);
};

}  // namespace problem_1450
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_STUDENTS_DOING_HOMEWORK_AT_A_GIVEN_TIME_H__
