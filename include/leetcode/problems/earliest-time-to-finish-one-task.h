#ifndef LEETCODE_EARLIEST_TIME_TO_FINISH_ONE_TASK_H_
#define LEETCODE_EARLIEST_TIME_TO_FINISH_ONE_TASK_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3683 {

using EarliestTimeFunc = std::function<int(std::vector<std::vector<int>>&)>;

class EarliestTimeToFinishOneTaskSolution : public SolutionBase<EarliestTimeFunc> {
 public:
  EarliestTimeToFinishOneTaskSolution();

  int earliestTime(std::vector<std::vector<int>>& tasks);
};

}  // namespace problem_3683
}  // namespace leetcode

#endif  // LEETCODE_EARLIEST_TIME_TO_FINISH_ONE_TASK_H_
