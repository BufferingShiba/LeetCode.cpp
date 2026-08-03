#ifndef LEETCODE_PROBLEMS_N_QUEENS_II_H_
#define LEETCODE_PROBLEMS_N_QUEENS_II_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_52 {

using Func = std::function<int(int)>;

class NQueensIiSolution : public SolutionBase<Func> {
 public:
  NQueensIiSolution();

  int totalNQueens(int n) {
    return getSolution()(n);
  }
};

}  // namespace problem_52
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_N_QUEENS_II_H_
