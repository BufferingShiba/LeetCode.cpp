// LeetCode Problem 1460: Make Two Arrays Equal by Reversing Subarrays

#ifndef LEETCODE_PROBLEMS_MAKE_TWO_ARRAYS_EQUAL_BY_REVERSING_SUBARRAYS_H__
#define LEETCODE_PROBLEMS_MAKE_TWO_ARRAYS_EQUAL_BY_REVERSING_SUBARRAYS_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1460 {

using Func = std::function<bool(std::vector<int>&, std::vector<int>&)>;

class MakeTwoArraysEqualByReversingSubarraysSolution
    : public SolutionBase<Func> {
 public:
  MakeTwoArraysEqualByReversingSubarraysSolution();

  bool canBeEqual(std::vector<int>& target, std::vector<int>& arr);
};

}  // namespace problem_1460
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAKE_TWO_ARRAYS_EQUAL_BY_REVERSING_SUBARRAYS_H__
