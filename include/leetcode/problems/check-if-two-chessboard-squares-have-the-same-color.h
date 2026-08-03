#ifndef LEETCODE_PROBLEMS_CHECK_IF_TWO_CHESSBOARD_SQUARES_HAVE_THE_SAME_COLOR_H__
#define LEETCODE_PROBLEMS_CHECK_IF_TWO_CHESSBOARD_SQUARES_HAVE_THE_SAME_COLOR_H__

#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3274 {

using CheckIfTwoChessboardSquaresHaveTheSameColorFunc =
    std::function<bool(std::string, std::string)>;

class CheckIfTwoChessboardSquaresHaveTheSameColorSolution
    : public SolutionBase<CheckIfTwoChessboardSquaresHaveTheSameColorFunc> {
 public:
  CheckIfTwoChessboardSquaresHaveTheSameColorSolution();

  bool checkTwoChessboards(std::string coordinate1, std::string coordinate2);

 private:
  void registerStrategies();
};

}  // namespace problem_3274
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_TWO_CHESSBOARD_SQUARES_HAVE_THE_SAME_COLOR_H__
