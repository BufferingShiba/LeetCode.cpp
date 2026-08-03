#pragma once

#include "leetcode/core.h"
#include <functional>

namespace leetcode {
namespace problem_2909 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumSumOfMountainTripletsIiSolution
    : public SolutionBase<Func> {
 public:
  MinimumSumOfMountainTripletsIiSolution();

  int minimumSum(std::vector<int>& nums);
};

}  // namespace problem_2909
}  // namespace leetcode
