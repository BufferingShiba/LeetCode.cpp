#ifndef LEETCODE_PROBLEMS_CHECK_ADJACENT_DIGIT_DIFFERENCES_H_
#define LEETCODE_PROBLEMS_CHECK_ADJACENT_DIGIT_DIFFERENCES_H_

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3931 {

using Func = std::function<bool(std::string)>;

class CheckAdjacentDigitDifferencesSolution
    : public SolutionBase<Func> {
 public:
  CheckAdjacentDigitDifferencesSolution();

  bool isAdjacentDiffAtMostTwo(std::string s);
};

}  // namespace problem_3931
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_ADJACENT_DIGIT_DIFFERENCES_H_
