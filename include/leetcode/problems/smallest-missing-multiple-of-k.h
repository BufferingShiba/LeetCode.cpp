#ifndef LEETCODE_PROBLEMS_SMALLEST_MISSING_MULTIPLE_OF_K_H__
#define LEETCODE_PROBLEMS_SMALLEST_MISSING_MULTIPLE_OF_K_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode {
namespace problem_3718 {

using Func = std::function<int(std::vector<int>&, int)>;

class SmallestMissingMultipleOfKSolution : public SolutionBase<Func> {
 public:
  SmallestMissingMultipleOfKSolution();

  int missingMultiple(std::vector<int>& nums, int k);
};

}  // namespace problem_3718
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SMALLEST_MISSING_MULTIPLE_OF_K_H__
