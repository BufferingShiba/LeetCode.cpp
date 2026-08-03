#ifndef LEETCODE_PROBLEMS_NUMBER_OF_VALID_MOVE_COMBINATIONS_ON_CHESSBOARD_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_VALID_MOVE_COMBINATIONS_ON_CHESSBOARD_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2056 {

using Func = std::function<int(std::vector<std::string>&,
                               std::vector<std::vector<int>>&)>;

class NumberOfValidMoveCombinationsOnChessboardSolution
    : public SolutionBase<Func> {
 public:
  NumberOfValidMoveCombinationsOnChessboardSolution();

  // Original problem entry point.
  int countCombinations(std::vector<std::string>& pieces,
                        std::vector<std::vector<int>>& positions);
};

}  // namespace problem_2056
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_VALID_MOVE_COMBINATIONS_ON_CHESSBOARD_H__
