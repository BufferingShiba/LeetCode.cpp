#ifndef LEETCODE_PROBLEM_3938_H
#define LEETCODE_PROBLEM_3938_H

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3938 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class MaximumPathIntersectionSumInAGridSolution : public SolutionBase<Func> {
 public:
  MaximumPathIntersectionSumInAGridSolution();

  int maxScore(std::vector<std::vector<int>>& grid);
};

}  // namespace problem_3938
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_3938_H
