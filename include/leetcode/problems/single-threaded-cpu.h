#ifndef LEETCODE_PROBLEM_1834_H_
#define LEETCODE_PROBLEM_1834_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode::problem_1834 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&)>;

class SingleThreadedCpuSolution : public SolutionBase<Func> {
 public:
  SingleThreadedCpuSolution();

  std::vector<int> getOrder(std::vector<std::vector<int>>& tasks);
};

}  // namespace leetcode::problem_1834

#endif  // LEETCODE_PROBLEM_1834_H_
