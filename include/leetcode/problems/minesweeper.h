#ifndef LEETCODE_PROBLEMS_MINESWEEPER_H_
#define LEETCODE_PROBLEMS_MINESWEEPER_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_529 {

using Func = std::function<std::vector<std::vector<char>>(std::vector<std::vector<char>>&, std::vector<int>&)>;

class MinesweeperSolution : public SolutionBase<Func> {
 public:
  MinesweeperSolution();

  std::vector<std::vector<char>> updateBoard(std::vector<std::vector<char>>& board, std::vector<int>& click);
};

}  // namespace problem_529
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINESWEEPER_H_
