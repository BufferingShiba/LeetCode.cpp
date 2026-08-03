#ifndef LEETCODE_PROBLEMS_MAXIMIZE_THE_TOPMOST_ELEMENT_AFTER_K_MOVES_H__
#define LEETCODE_PROBLEMS_MAXIMIZE_THE_TOPMOST_ELEMENT_AFTER_K_MOVES_H__

#include "leetcode/core.h"
#include <algorithm>
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2202 {

using Func = std::function<int(std::vector<int>&, int)>;

class MaximizeTheTopmostElementAfterKMovesSolution
    : public SolutionBase<Func> {
 public:
  MaximizeTheTopmostElementAfterKMovesSolution();

  int maximumTop(std::vector<int>& nums, int k);
};

}  // namespace problem_2202
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMIZE_THE_TOPMOST_ELEMENT_AFTER_K_MOVES_H__
