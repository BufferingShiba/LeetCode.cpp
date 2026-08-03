#ifndef LEETCODE_PROBLEM_1250_H__
#define LEETCODE_PROBLEM_1250_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1250 {

using Func = std::function<bool(std::vector<int>&)>;

class CheckIfItIsAGoodArraySolution : public SolutionBase<Func> {
 public:
  CheckIfItIsAGoodArraySolution();

  bool isGoodArray(std::vector<int>& nums);
};

}  // namespace problem_1250
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_1250_H__
