#ifndef LEETCODE_PROBLEMS_TRANSFORM_TO_CHESSBOARD_H__
#define LEETCODE_PROBLEMS_TRANSFORM_TO_CHESSBOARD_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_782 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class TransformToChessboardSolution : public SolutionBase<Func> {
 public:
  TransformToChessboardSolution();

  int movesToChessboard(std::vector<std::vector<int>>& board);
};

}  // namespace problem_782
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_TRANSFORM_TO_CHESSBOARD_H__
