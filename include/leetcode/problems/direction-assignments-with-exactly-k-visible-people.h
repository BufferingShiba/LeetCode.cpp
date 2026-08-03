#ifndef LEETCODE_PROBLEMS_DIRECTION_ASSIGNMENTS_WITH_EXACTLY_K_VISIBLE_PEOPLE_H
#define LEETCODE_PROBLEMS_DIRECTION_ASSIGNMENTS_WITH_EXACTLY_K_VISIBLE_PEOPLE_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3881 {

using Func = std::function<int(int, int, int)>;

class DirectionAssignmentsWithExactlyKVisiblePeopleSolution
    : public SolutionBase<Func> {
 public:
  DirectionAssignmentsWithExactlyKVisiblePeopleSolution();

  int countVisiblePeople(int n, int pos, int k);
};

}  // namespace problem_3881
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DIRECTION_ASSIGNMENTS_WITH_EXACTLY_K_VISIBLE_PEOPLE_H
