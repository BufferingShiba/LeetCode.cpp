#include "leetcode/problems/find-the-winner-of-the-circular-game.h"

namespace leetcode::problem_1823 {

namespace {

int findTheWinnerImpl(int n, int k) {
  // Josephus problem: 0-indexed recurrence f(1) = 0; f(i) = (f(i-1) + k) % i
  int ans = 0;  // base case: only 1 person, index 0 survives
  for (int i = 2; i <= n; ++i) {
    ans = (ans + k) % i;
  }
  // convert back to 1-indexed
  return ans + 1;
}

}  // namespace

int FindTheWinnerOfTheCircularGameSolution::findTheWinner(int n, int k) {
  return getSolution()(n, k);
}

FindTheWinnerOfTheCircularGameSolution::FindTheWinnerOfTheCircularGameSolution() {
  setMetaInfo({.id = 1823,
               .title = "Find the Winner of the Circular Game",
               .url = "https://leetcode.com/problems/find-the-winner-of-the-circular-game/"});

  registerStrategy({.name = "JosephusIterative",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "Recursion", "Simulation"}},
                   findTheWinnerImpl);
}

}  // namespace leetcode::problem_1823
