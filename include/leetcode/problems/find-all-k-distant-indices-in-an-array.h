#ifndef LEETCODE_PROBLEMS_FIND_ALL_K_DISTANT_INDICES_IN_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_FIND_ALL_K_DISTANT_INDICES_IN_AN_ARRAY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_2200 {

using Func = std::function<std::vector<int>(std::vector<int>&, int, int)>;

class FindAllKDistantIndicesInAnArraySolution
    : public SolutionBase<Func> {
 public:
  FindAllKDistantIndicesInAnArraySolution();

  std::vector<int> findKDistantIndices(std::vector<int>& nums, int key, int k);
};

}  // namespace leetcode::problem_2200

#endif  // LEETCODE_PROBLEMS_FIND_ALL_K_DISTANT_INDICES_IN_AN_ARRAY_H__
