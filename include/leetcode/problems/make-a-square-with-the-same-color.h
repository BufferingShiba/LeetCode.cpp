#ifndef LEETCODE_PROBLEMS_MAKE_A_SQUARE_WITH_THE_SAME_COLOR_H_
#define LEETCODE_PROBLEMS_MAKE_A_SQUARE_WITH_THE_SAME_COLOR_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3127 {

using Func = std::function<bool(std::vector<std::vector<char>>&)>;

class MakeASquareWithTheSameColorSolution
    : public SolutionBase<Func> {
 public:
  MakeASquareWithTheSameColorSolution();

  bool canMakeSquare(std::vector<std::vector<char>>& grid);
};

}  // namespace problem_3127
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAKE_A_SQUARE_WITH_THE_SAME_COLOR_H_
