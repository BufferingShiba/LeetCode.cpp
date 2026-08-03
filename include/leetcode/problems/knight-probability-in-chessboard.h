#include "leetcode/core.h"

namespace leetcode {
namespace problem_688 {

using Func = std::function<double(int, int, int, int)>;

class KnightProbabilityInChessboardSolution : public SolutionBase<Func> {
 public:
  //! 688. Knight Probability in Chessboard
  //! https://leetcode.com/problems/knight-probability-in-chessboard/
  double knightProbability(int n, int k, int row, int column);

  KnightProbabilityInChessboardSolution();
};

}  // namespace problem_688
}  // namespace leetcode
