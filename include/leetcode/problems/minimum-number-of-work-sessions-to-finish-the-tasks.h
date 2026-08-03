#ifndef LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_WORK_SESSIONS_TO_FINISH_THE_TASKS_H_
#define LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_WORK_SESSIONS_TO_FINISH_THE_TASKS_H_

#include "leetcode/core.h"

namespace leetcode::problem_1986 {

using Func = std::function<int(std::vector<int>&, int)>;

class MinimumNumberOfWorkSessionsToFinishTheTasksSolution
    : public SolutionBase<Func> {
 public:
  MinimumNumberOfWorkSessionsToFinishTheTasksSolution();
  int minSessions(std::vector<int>& tasks, int sessionTime);
};

}  // namespace leetcode::problem_1986

#endif  // LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_WORK_SESSIONS_TO_FINISH_THE_TASKS_H_
