#ifndef LEETCODE_PROBLEMS_MINIMUM_SWAPS_TO_MOVE_ZEROS_TO_END_H__
#define LEETCODE_PROBLEMS_MINIMUM_SWAPS_TO_MOVE_ZEROS_TO_END_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3936 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumSwapsToMoveZerosToEndSolution
    : public SolutionBase<Func> {
 public:
  MinimumSwapsToMoveZerosToEndSolution();
  int minimumSwaps(std::vector<int>& nums);
};

}  // namespace problem_3936
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_SWAPS_TO_MOVE_ZEROS_TO_END_H__
