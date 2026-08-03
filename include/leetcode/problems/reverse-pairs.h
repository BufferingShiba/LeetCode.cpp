#ifndef LEETCODE_PROBLEM_493_H_
#define LEETCODE_PROBLEM_493_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_493 {

using Func = std::function<int(std::vector<int>&)>;

class ReversePairsSolution : public SolutionBase<Func> {
 public:
  ReversePairsSolution();

  int reversePairs(std::vector<int>& nums);
};

}  // namespace problem_493
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_493_H_
