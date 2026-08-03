#ifndef LEETCODE_PROBLEM_2369_H_
#define LEETCODE_PROBLEM_2369_H_

#include "leetcode/core.h"

namespace leetcode::problem_2369 {

using Func = std::function<bool(std::vector<int>&)>;

class CheckIfThereIsAValidPartitionForTheArraySolution : public SolutionBase<Func> {
 public:
  CheckIfThereIsAValidPartitionForTheArraySolution();

  bool validPartition(std::vector<int>& nums);
};

}  // namespace leetcode::problem_2369

#endif  // LEETCODE_PROBLEM_2369_H_
