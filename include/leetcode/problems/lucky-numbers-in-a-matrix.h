#ifndef LEETCODE_PROBLEMS_LUCKY_NUMBERS_IN_A_MATRIX_H__
#define LEETCODE_PROBLEMS_LUCKY_NUMBERS_IN_A_MATRIX_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_1380 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&)>;

class LuckyNumbersInAMatrixSolution : public SolutionBase<Func> {
 public:
  LuckyNumbersInAMatrixSolution();

  std::vector<int> luckyNumbers(std::vector<std::vector<int>>& matrix) {
    return getSolution()(matrix);
  }
};

}  // namespace problem_1380
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_LUCKY_NUMBERS_IN_A_MATRIX_H__
