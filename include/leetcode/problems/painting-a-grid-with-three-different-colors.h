#ifndef LEETCODE_PROBLEMS_PAINTING_A_GRID_WITH_THREE_DIFFERENT_COLORS_H__
#define LEETCODE_PROBLEMS_PAINTING_A_GRID_WITH_THREE_DIFFERENT_COLORS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1931 {

using Func = std::function<int(int, int)>;

class PaintingAGridWithThreeDifferentColorsSolution
    : public SolutionBase<Func> {
 public:
  PaintingAGridWithThreeDifferentColorsSolution();

  int colorTheGrid(int m, int n);
};

}  // namespace problem_1931
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_PAINTING_A_GRID_WITH_THREE_DIFFERENT_COLORS_H__
