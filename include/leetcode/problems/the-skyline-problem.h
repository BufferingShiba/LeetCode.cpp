#pragma once

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_218 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<std::vector<int>>&)>;

class TheSkylineProblemSolution : public SolutionBase<Func> {
 public:
  TheSkylineProblemSolution();

  std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>>& buildings);
};

}  // namespace problem_218
}  // namespace leetcode
