#ifndef LEETCODE_PROBLEMS_NEXT_PERMUTATION_H_
#define LEETCODE_PROBLEMS_NEXT_PERMUTATION_H_

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_31 {

using Func = std::function<void(std::vector<int>&)>;

class NextPermutationSolution : public SolutionBase<Func> {
 public:
  NextPermutationSolution();
  void nextPermutation(std::vector<int>& nums);
};

}  // namespace problem_31
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NEXT_PERMUTATION_H_
