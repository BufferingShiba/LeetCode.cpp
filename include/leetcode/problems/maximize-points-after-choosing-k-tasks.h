#ifndef LEETCODE_PROBLEMS_MAXIMIZE_POINTS_AFTER_CHOOSING_K_TASKS_H_
#define LEETCODE_PROBLEMS_MAXIMIZE_POINTS_AFTER_CHOOSING_K_TASKS_H_

#include <vector>
#include <functional>

#include "leetcode/core.h"

namespace leetcode::problem_3767 {

using Func = std::function<long long(std::vector<int>&, std::vector<int>&, int)>;

class MaximizePointsAfterChoosingKTasksSolution : public SolutionBase<Func> {
 public:
  MaximizePointsAfterChoosingKTasksSolution();

  long long maxPoints(std::vector<int>& technique1,
                      std::vector<int>& technique2, int k);
};

}  // namespace leetcode::problem_3767

#endif  // LEETCODE_PROBLEMS_MAXIMIZE_POINTS_AFTER_CHOOSING_K_TASKS_H_
