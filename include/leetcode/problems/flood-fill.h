#ifndef LEETCODE_PROBLEMS_FLOOD_FILL_H__
#define LEETCODE_PROBLEMS_FLOOD_FILL_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_733 {

using Func = std::function<std::vector<std::vector<int>>(
    std::vector<std::vector<int>>&, int, int, int)>;

class FloodFillSolution : public SolutionBase<Func> {
 public:
  FloodFillSolution();

  std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image,
                                          int sr, int sc, int color);
};

}  // namespace leetcode::problem_733

#endif  // LEETCODE_PROBLEMS_FLOOD_FILL_H__
