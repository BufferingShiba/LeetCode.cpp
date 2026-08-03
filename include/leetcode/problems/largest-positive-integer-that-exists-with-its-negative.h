#ifndef LEETCODE_PROBLEM_2441_H_
#define LEETCODE_PROBLEM_2441_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2441 {

using Func = std::function<int(std::vector<int>&)>;

class LargestPositiveIntegerThatExistsWithItsNegativeSolution : public SolutionBase<Func> {
 public:
  LargestPositiveIntegerThatExistsWithItsNegativeSolution();
  int findMaxK(std::vector<int>& nums);
};

}  // namespace problem_2441
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_2441_H_
