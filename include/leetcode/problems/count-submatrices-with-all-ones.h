#ifndef LEETCODE_PROBLEMS_COUNT_SUBMATRICES_WITH_ALL_ONES_H__
#define LEETCODE_PROBLEMS_COUNT_SUBMATRICES_WITH_ALL_ONES_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1504 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class CountSubmatricesWithAllOnesSolution : public SolutionBase<Func> {
 public:
  CountSubmatricesWithAllOnesSolution();

  int numSubmat(std::vector<std::vector<int>>& mat);
};

}  // namespace problem_1504
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_SUBMATRICES_WITH_ALL_ONES_H__
