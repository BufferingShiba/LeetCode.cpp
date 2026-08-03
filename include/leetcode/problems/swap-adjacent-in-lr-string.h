#ifndef LEETCODE_PROBLEMS_SWAP_ADJACENT_IN_LR_STRING_H__
#define LEETCODE_PROBLEMS_SWAP_ADJACENT_IN_LR_STRING_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode::problem_777 {

using Func = std::function<bool(const std::string&, const std::string&)>;

class SwapAdjacentInLrStringSolution : public SolutionBase<Func> {
 public:
  SwapAdjacentInLrStringSolution();
  bool canTransform(const std::string& start, const std::string& result);
};

}  // namespace leetcode::problem_777

#endif  // LEETCODE_PROBLEMS_SWAP_ADJACENT_IN_LR_STRING_H__
