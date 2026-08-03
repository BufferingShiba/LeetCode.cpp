#ifndef LEETCODE_PROBLEMS_REDUNDANT_CONNECTION_II_H_
#define LEETCODE_PROBLEMS_REDUNDANT_CONNECTION_II_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_685 {

using Func = std::function<std::vector<int>(std::vector<std::vector<int>>&)>;

class RedundantConnectionIiSolution : public SolutionBase<Func> {
 public:
  RedundantConnectionIiSolution();

  std::vector<int> findRedundantDirectedConnection(
      std::vector<std::vector<int>>& edges);
};

}  // namespace problem_685
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REDUNDANT_CONNECTION_II_H_
