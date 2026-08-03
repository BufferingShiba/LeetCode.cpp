#ifndef LEETCODE_PROBLEMS_FLIP_STRING_TO_MONOTONE_INCREASING_H__
#define LEETCODE_PROBLEMS_FLIP_STRING_TO_MONOTONE_INCREASING_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_926 {

using Func = std::function<int(std::string)>;

class FlipStringToMonotoneIncreasingSolution : public SolutionBase<Func> {
 public:
  FlipStringToMonotoneIncreasingSolution();

  int minFlipsMonoIncr(const std::string& s) { return getSolution()(s); }
};

}  // namespace problem_926
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FLIP_STRING_TO_MONOTONE_INCREASING_H__
