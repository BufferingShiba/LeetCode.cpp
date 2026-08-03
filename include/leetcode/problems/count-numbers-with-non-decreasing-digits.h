#ifndef LEETCODE_PROBLEMS_COUNT_NUMBERS_WITH_NON_DECREASING_DIGITS_H_
#define LEETCODE_PROBLEMS_COUNT_NUMBERS_WITH_NON_DECREASING_DIGITS_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3519 {

using Func = std::function<int(std::string, std::string, int)>;

class CountNumbersWithNonDecreasingDigitsSolution : public SolutionBase<Func> {
 public:
  CountNumbersWithNonDecreasingDigitsSolution();

  int countNumbers(std::string l, std::string r, int b);
};

}  // namespace problem_3519
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_NUMBERS_WITH_NON_DECREASING_DIGITS_H_
