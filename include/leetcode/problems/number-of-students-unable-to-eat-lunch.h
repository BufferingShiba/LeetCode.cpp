#ifndef LEETCODE_PROBLEMS_NUMBER_OF_STUDENTS_UNABLE_TO_EAT_LUNCH_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_STUDENTS_UNABLE_TO_EAT_LUNCH_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1700 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class NumberOfStudentsUnableToEatLunchSolution
    : public SolutionBase<Func> {
 public:
  NumberOfStudentsUnableToEatLunchSolution();
  int countStudents(std::vector<int>& students,
                    std::vector<int>& sandwiches);
};

}  // namespace problem_1700
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_STUDENTS_UNABLE_TO_EAT_LUNCH_H__
