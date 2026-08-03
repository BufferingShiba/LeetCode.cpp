#ifndef LEETCODE_PROBLEMS_VALID_DIGIT_NUMBER_H__
#define LEETCODE_PROBLEMS_VALID_DIGIT_NUMBER_H__

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3908 {

using Func = std::function<bool(int, int)>;

class ValidDigitNumberSolution : public SolutionBase<Func> {
 public:
  ValidDigitNumberSolution();
  bool validDigit(int n, int x);
};

}  // namespace problem_3908
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_VALID_DIGIT_NUMBER_H__
