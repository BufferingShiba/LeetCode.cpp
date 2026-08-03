#ifndef LEETCODE_PROBLEMS_FIND_NUMBERS_WITH_EVEN_NUMBER_OF_DIGITS_H_
#define LEETCODE_PROBLEMS_FIND_NUMBERS_WITH_EVEN_NUMBER_OF_DIGITS_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1295 {

using Func = std::function<int(std::vector<int>&)>;

class FindNumbersWithEvenNumberOfDigitsSolution
    : public SolutionBase<Func> {
 public:
  FindNumbersWithEvenNumberOfDigitsSolution();

  int findNumbers(std::vector<int>& nums);
};

}  // namespace problem_1295
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_NUMBERS_WITH_EVEN_NUMBER_OF_DIGITS_H_
