#ifndef LEETCODE_PROBLEMS_SPECIAL_PERMUTATIONS_H_
#define LEETCODE_PROBLEMS_SPECIAL_PERMUTATIONS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2741 {

using Func = std::function<int(std::vector<int>&)>;

class SpecialPermutationsSolution : public SolutionBase<Func> {
 public:
  SpecialPermutationsSolution();

  int specialPerm(std::vector<int>& nums);
};

}  // namespace problem_2741
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SPECIAL_PERMUTATIONS_H_
