#ifndef LEETCODE_PROBLEMS_SEMI_ORDERED_PERMUTATION_H_
#define LEETCODE_PROBLEMS_SEMI_ORDERED_PERMUTATION_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2717 {

using Func = std::function<int(std::vector<int>&)>;

class SemiOrderedPermutationSolution : public SolutionBase<Func> {
 public:
  SemiOrderedPermutationSolution();
};

}  // namespace problem_2717
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SEMI_ORDERED_PERMUTATION_H_
