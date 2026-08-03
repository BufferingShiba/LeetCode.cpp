#ifndef LEETCODE_PROBLEMS_FIND_THE_LONGEST_VALID_OBSTACLE_COURSE_AT_EACH_POSITION_H_
#define LEETCODE_PROBLEMS_FIND_THE_LONGEST_VALID_OBSTACLE_COURSE_AT_EACH_POSITION_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1964 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class FindTheLongestValidObstacleCourseAtEachPositionSolution
    : public SolutionBase<Func> {
 public:
  FindTheLongestValidObstacleCourseAtEachPositionSolution();

  std::vector<int> longestObstacleCourseAtEachPosition(
      std::vector<int>& obstacles);
};

}  // namespace problem_1964
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_LONGEST_VALID_OBSTACLE_COURSE_AT_EACH_POSITION_H_
