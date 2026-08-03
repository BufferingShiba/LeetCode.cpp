#pragma once

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3769 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class SortIntegersByBinaryReflectionSolution
    : public SolutionBase<Func> {
 public:
  SortIntegersByBinaryReflectionSolution();

  std::vector<int> sortByReflection(std::vector<int>& nums);
};

}  // namespace problem_3769
}  // namespace leetcode
