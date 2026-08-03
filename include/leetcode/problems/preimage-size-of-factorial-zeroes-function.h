#ifndef LEETCODE_PROBLEMS_PREIMAGE_SIZE_OF_FACTORIAL_ZEROES_FUNCTION_H__
#define LEETCODE_PROBLEMS_PREIMAGE_SIZE_OF_FACTORIAL_ZEROES_FUNCTION_H__

#include "leetcode/core.h"
#include <functional>

namespace leetcode {
namespace problem_793 {

using Func = std::function<int(int)>;

// Free function (defined in source).
int preimageSizeFZF(int k);

class PreimageSizeOfFactorialZeroesFunctionSolution
    : public SolutionBase<Func> {
 public:
  PreimageSizeOfFactorialZeroesFunctionSolution() {
    setMetaInfo({.id = 793,
                 .title = "Preimage Size of Factorial Zeroes Function",
                 .url = "https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/"});
    registerStrategy(
        {.name = "math_binary_search",
         .expected = "Accepted",
         .time_complexity = "O(log k)",
         .space_complexity = "O(1)",
         .tags = {"Math", "Binary Search"},
         .notes = "f(x) = sum(floor(x/5^i)) is monotone; binary search smallest x with f(x)>=k"},
        ::leetcode::problem_793::preimageSizeFZF);
  }

  int preimageSizeFZF(int k) { return getSolution()(k); }
};

}  // namespace problem_793
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PREIMAGE_SIZE_OF_FACTORIAL_ZEROES_FUNCTION_H__
