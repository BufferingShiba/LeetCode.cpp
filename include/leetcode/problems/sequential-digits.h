#ifndef LEETCODE_PROBLEMS_SEQUENTIAL_DIGITS_H__
#define LEETCODE_PROBLEMS_SEQUENTIAL_DIGITS_H__

#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1291 {

class SequentialDigitsSolution
    : public SolutionBase<std::function<std::vector<int>(int, int)>> {
 public:
  SequentialDigitsSolution();

  std::vector<int> sequentialDigits(int low, int high);
};

}  // namespace leetcode::problem_1291

#endif  // LEETCODE_PROBLEMS_SEQUENTIAL_DIGITS_H__
