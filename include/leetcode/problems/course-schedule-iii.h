#ifndef LEETCODE_PROBLEMS_COURSE_SCHEDULE_III_H
#define LEETCODE_PROBLEMS_COURSE_SCHEDULE_III_H

#include "leetcode/core.h"

namespace leetcode::problem_630 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class CourseScheduleIiiSolution : public SolutionBase<Func> {
 public:
  CourseScheduleIiiSolution();

  int scheduleCourse(std::vector<std::vector<int>>& courses);
};

}  // namespace leetcode::problem_630

#endif
