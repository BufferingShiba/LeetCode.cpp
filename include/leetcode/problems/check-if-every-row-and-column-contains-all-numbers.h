#pragma once

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2133 {

using Func = std::function<bool(std::vector<std::vector<int>>&)>;

class CheckIfEveryRowAndColumnContainsAllNumbersSolution
    : public SolutionBase<Func> {
 public:
  bool checkValid(std::vector<std::vector<int>>& matrix);

  CheckIfEveryRowAndColumnContainsAllNumbersSolution();
};

}  // namespace problem_2133
}  // namespace leetcode
