#ifndef LEETCODE_PROBLEMS_INCREMENT_SUBMATRICES_BY_ONE_H_
#define LEETCODE_PROBLEMS_INCREMENT_SUBMATRICES_BY_ONE_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2536 {

using Func = std::function<std::vector<std::vector<int>>(int, std::vector<std::vector<int>>&)>;

class IncrementSubmatricesByOneSolution : public SolutionBase<Func> {
 public:
  IncrementSubmatricesByOneSolution();

  std::vector<std::vector<int>> rangeAddQueries(int n,
                                                 std::vector<std::vector<int>>& queries) {
    return getSolution()(n, queries);
  }
};

}  // namespace problem_2536
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_INCREMENT_SUBMATRICES_BY_ONE_H_
