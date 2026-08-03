#ifndef LEETCODE_PROBLEMS_COURSE_SCHEDULE_H__
#define LEETCODE_PROBLEMS_COURSE_SCHEDULE_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_207 {

using Func = std::function<bool(int, std::vector<std::vector<int>>&)>;

class CourseScheduleSolution : public SolutionBase<Func> {
 public:
  CourseScheduleSolution();

  bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites);
};

}  // namespace problem_207
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COURSE_SCHEDULE_H__
