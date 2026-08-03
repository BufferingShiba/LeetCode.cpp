#ifndef LEETCODE_PROBLEMS_CHECK_IF_MOVE_IS_LEGAL_H__
#define LEETCODE_PROBLEMS_CHECK_IF_MOVE_IS_LEGAL_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1958 {

using Func = std::function<bool(std::vector<std::vector<char>>&, int, int, char)>;

class CheckIfMoveIsLegalSolution : public SolutionBase<Func> {
 public:
  CheckIfMoveIsLegalSolution();

  bool checkMove(std::vector<std::vector<char>>& board, int rMove, int cMove,
                 char color);
};

}  // namespace problem_1958
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CHECK_IF_MOVE_IS_LEGAL_H__
