#ifndef LEETCODE_PROBLEMS_MATRIX_SIMILARITY_AFTER_CYCLIC_SHIFTS_H
#define LEETCODE_PROBLEMS_MATRIX_SIMILARITY_AFTER_CYCLIC_SHIFTS_H

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode::problem_2946 {

using Func = std::function<bool(std::vector<std::vector<int>>&, int)>;

class MatrixSimilarityAfterCyclicShiftsSolution
    : public SolutionBase<Func> {
 public:
  MatrixSimilarityAfterCyclicShiftsSolution();
  bool areSimilar(std::vector<std::vector<int>>& mat, int k);
};

}  // namespace leetcode::problem_2946

#endif  // LEETCODE_PROBLEMS_MATRIX_SIMILARITY_AFTER_CYCLIC_SHIFTS_H
