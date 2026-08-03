#ifndef LEETCODE_PROBLEMS_COUNT_DOMINANT_INDICES_H__
#define LEETCODE_PROBLEMS_COUNT_DOMINANT_INDICES_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_3833 {

using Func = std::function<int(std::vector<int>&)>;

class CountDominantIndicesSolution
    : public SolutionBase<Func> {
 public:
  CountDominantIndicesSolution();

  int dominantIndices(std::vector<int>& nums);
};

}  // namespace leetcode::problem_3833

#endif  // LEETCODE_PROBLEMS_COUNT_DOMINANT_INDICES_H__
