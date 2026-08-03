#ifndef LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_ASSIGN_EDGE_WEIGHTS_I_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_ASSIGN_EDGE_WEIGHTS_I_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3558 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class NumberOfWaysToAssignEdgeWeightsISolution
    : public SolutionBase<Func> {
 public:
  NumberOfWaysToAssignEdgeWeightsISolution();

  int assignEdgeWeights(std::vector<std::vector<int>>& edges);
};

}  // namespace problem_3558
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_WAYS_TO_ASSIGN_EDGE_WEIGHTS_I_H__
