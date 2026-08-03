#ifndef LEETCODE_PROBLEM_2071_H_
#define LEETCODE_PROBLEM_2071_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2071 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&, int, int)>;

class MaximumNumberOfTasksYouCanAssignSolution : public SolutionBase<Func> {
 public:
  MaximumNumberOfTasksYouCanAssignSolution();

  int maxTaskAssign(std::vector<int>& tasks, std::vector<int>& workers, int pills,
                    int strength);
};

}  // namespace problem_2071
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_2071_H_
