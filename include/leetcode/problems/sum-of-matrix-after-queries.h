#ifndef LEETCODE_PROBLEMS_SUM_OF_MATRIX_AFTER_QUERIES_H_
#define LEETCODE_PROBLEMS_SUM_OF_MATRIX_AFTER_QUERIES_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2718 {

using Func = std::function<long long(int, std::vector<std::vector<int>>&)>;

class SumOfMatrixAfterQueriesSolution : public SolutionBase<Func> {
 public:
  SumOfMatrixAfterQueriesSolution();

  long long matrixSumQueries(int n, std::vector<std::vector<int>>& queries);
};

}  // namespace leetcode::problem_2718

#endif  // LEETCODE_PROBLEMS_SUM_OF_MATRIX_AFTER_QUERIES_H_
