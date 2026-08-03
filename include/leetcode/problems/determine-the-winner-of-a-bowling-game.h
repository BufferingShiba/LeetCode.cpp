#ifndef LEETCODE_PROBLEMS_DETERMINE_THE_WINNER_OF_A_BOWLING_GAME_H_
#define LEETCODE_PROBLEMS_DETERMINE_THE_WINNER_OF_A_BOWLING_GAME_H_

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2660 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class DetermineTheWinnerOfABowlingGameSolution
    : public SolutionBase<Func> {
public:
    DetermineTheWinnerOfABowlingGameSolution();

    int isWinner(std::vector<int>& player1, std::vector<int>& player2);
};

}  // namespace problem_2660
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DETERMINE_THE_WINNER_OF_A_BOWLING_GAME_H_
