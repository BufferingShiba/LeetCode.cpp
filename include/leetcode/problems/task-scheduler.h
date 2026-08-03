#ifndef LEETCODE_PROBLEMS_TASK_SCHEDULER_H__
#define LEETCODE_PROBLEMS_TASK_SCHEDULER_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_621 {

using Func = std::function<int(std::vector<char>&, int)>;

class TaskSchedulerSolution : public SolutionBase<Func> {
 public:
  TaskSchedulerSolution();

  int leastInterval(std::vector<char>& tasks, int n);
};

}  // namespace problem_621
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_TASK_SCHEDULER_H__
