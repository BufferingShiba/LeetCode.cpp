#include "leetcode/problems/determine-the-winner-of-a-bowling-game.h"

namespace leetcode {
namespace problem_2660 {

namespace {

int isWinnerImpl(std::vector<int>& player1, std::vector<int>& player2) {
    auto computeScore = [](const std::vector<int>& pins) {
        int score = 0;
        for (int i = 0; i < (int)pins.size(); ++i) {
            bool doubleTurn = (i >= 1 && pins[i - 1] == 10) ||
                              (i >= 2 && pins[i - 2] == 10);
            score += doubleTurn ? 2 * pins[i] : pins[i];
        }
        return score;
    };

    int s1 = computeScore(player1);
    int s2 = computeScore(player2);
    if (s1 > s2) return 1;
    if (s2 > s1) return 2;
    return 0;
}

}  // namespace

DetermineTheWinnerOfABowlingGameSolution::DetermineTheWinnerOfABowlingGameSolution() {
    setMetaInfo({.id = 2660,
                 .title = "Determine the Winner of a Bowling Game",
                 .url = "https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/"});
    registerStrategy(
        {.name = "simulation",
         .expected = "Accepted",
         .time_complexity = "O(n)",
         .space_complexity = "O(1)",
         .tags = {"Array", "Simulation"}},
        isWinnerImpl);
}

int DetermineTheWinnerOfABowlingGameSolution::isWinner(std::vector<int>& player1,
                                                       std::vector<int>& player2) {
    return getSolution()(player1, player2);
}

}  // namespace problem_2660
}  // namespace leetcode
