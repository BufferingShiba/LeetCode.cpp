#pragma once

#include "leetcode/core.h"

namespace leetcode::problem_661 {

using Func = std::function<std::vector<std::vector<int>>(std::vector<std::vector<int>>&)>;

class ImageSmootherSolution : public SolutionBase<Func> {
 public:
  ImageSmootherSolution();

  std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img) {
    return getSolution()(img);
  }
};

}  // namespace leetcode::problem_661
