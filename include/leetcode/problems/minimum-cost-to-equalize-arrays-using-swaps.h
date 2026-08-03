#pragma once

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3868 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class MinimumCostToEqualizeArraysUsingSwapsSolution
    : public SolutionBase<Func> {
 public:
  MinimumCostToEqualizeArraysUsingSwapsSolution();

  int minCost(std::vector<int>& nums1, std::vector<int>& nums2) {
    return getSolution()(nums1, nums2);
  }
};

}  // namespace problem_3868
}  // namespace leetcode
