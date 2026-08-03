#ifndef LEETCODE_PROBLEM_3585_H
#define LEETCODE_PROBLEM_3585_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3585 {

using Func = std::function<std::vector<int>(int, std::vector<std::vector<int>>&, std::vector<std::vector<int>>&)>;

class FindWeightedMedianNodeInTreeSolution : public SolutionBase<Func> {
 public:
  FindWeightedMedianNodeInTreeSolution();
  std::vector<int> findMedian(int n, std::vector<std::vector<int>>& edges, std::vector<std::vector<int>>& queries);
};

}  // namespace problem_3585
}  // namespace leetcode

#endif
