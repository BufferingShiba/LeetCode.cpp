#ifndef L1462_COURSE_SCHEDULE_IV_H__
#define L1462_COURSE_SCHEDULE_IV_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1462 {

using Func = std::function<std::vector<bool>(int, std::vector<std::vector<int>>&, std::vector<std::vector<int>>&)>;

class CourseScheduleIvSolution : public SolutionBase<Func> {
 public:
  CourseScheduleIvSolution();

  std::vector<bool> checkIfPrerequisite(int numCourses,
                                        std::vector<std::vector<int>>& prerequisites,
                                        std::vector<std::vector<int>>& queries);
};

}  // namespace problem_1462
}  // namespace leetcode

#endif  // L1462_COURSE_SCHEDULE_IV_H__
