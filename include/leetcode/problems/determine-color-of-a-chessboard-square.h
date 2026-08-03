#ifndef LEETCODE_PROBLEMS_DETERMINE_COLOR_OF_A_CHESSBOARD_SQUARE_H__
#define LEETCODE_PROBLEMS_DETERMINE_COLOR_OF_A_CHESSBOARD_SQUARE_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1812 {

using Func = std::function<bool(std::string)>;

class DetermineColorOfAChessboardSquareSolution
    : public SolutionBase<Func> {
 public:
  DetermineColorOfAChessboardSquareSolution();

  bool squareIsWhite(std::string coordinates);
};

}  // namespace problem_1812
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DETERMINE_COLOR_OF_A_CHESSBOARD_SQUARE_H__
