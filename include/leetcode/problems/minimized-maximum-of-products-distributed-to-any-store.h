#ifndef LEETCODE_PROBLEM_2064_H_
#define LEETCODE_PROBLEM_2064_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2064 {

using Func = std::function<int(int, std::vector<int>&)>;

class MinimizedMaximumOfProductsDistributedToAnyStoreSolution : public SolutionBase<Func> {
 public:
  MinimizedMaximumOfProductsDistributedToAnyStoreSolution();

  int minimizedMaximum(int n, std::vector<int>& quantities);
};

}  // namespace problem_2064
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_2064_H_
