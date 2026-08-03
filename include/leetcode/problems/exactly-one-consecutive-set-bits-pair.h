#ifndef LEETCODE_PROBLEMS_EXACTLY_ONE_CONSECUTIVE_SET_BITS_PAIR_H__
#define LEETCODE_PROBLEMS_EXACTLY_ONE_CONSECUTIVE_SET_BITS_PAIR_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_3950 {

using Func = std::function<bool(int)>;

class ExactlyOneConsecutiveSetBitsPairSolution
    : public SolutionBase<Func> {
 public:
  ExactlyOneConsecutiveSetBitsPairSolution();

  bool consecutiveSetBits(int n);
};

}  // namespace leetcode::problem_3950

#endif  // LEETCODE_PROBLEMS_EXACTLY_ONE_CONSECUTIVE_SET_BITS_PAIR_H__
