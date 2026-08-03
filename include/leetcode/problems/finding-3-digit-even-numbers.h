#ifndef LEETCODE_PROBLEMS_FINDING_3_DIGIT_EVEN_NUMBERS_H__
#define LEETCODE_PROBLEMS_FINDING_3_DIGIT_EVEN_NUMBERS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2094 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class Finding3DigitEvenNumbersSolution
    : public SolutionBase<Func> {
 public:
  Finding3DigitEvenNumbersSolution();

  std::vector<int> findEvenNumbers(std::vector<int>& digits);
};

}  // namespace leetcode::problem_2094

#endif  // LEETCODE_PROBLEMS_FINDING_3_DIGIT_EVEN_NUMBERS_H__
