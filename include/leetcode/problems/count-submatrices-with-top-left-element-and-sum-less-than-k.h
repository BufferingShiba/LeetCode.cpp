#ifndef LEETCODE_PROBLEMS_COUNT_SUBMATRICES_WITH_TOP_LEFT_ELEMENT_AND_SUM_LESS_THAN_K_H__
#define LEETCODE_PROBLEMS_COUNT_SUBMATRICES_WITH_TOP_LEFT_ELEMENT_AND_SUM_LESS_THAN_K_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3070 {

using Func = std::function<int(std::vector<std::vector<int>>&, int)>;

class CountSubmatricesWithTopLeftElementAndSumLessThanKSolution
    : public SolutionBase<Func> {
 public:
  CountSubmatricesWithTopLeftElementAndSumLessThanKSolution();

  int countSubmatrices(std::vector<std::vector<int>>& grid, int k);
};

}  // namespace problem_3070
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_SUBMATRICES_WITH_TOP_LEFT_ELEMENT_AND_SUM_LESS_THAN_K_H__
