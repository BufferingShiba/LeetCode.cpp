// LeetCode 1996: The Number of Weak Characters in the Game
#include "leetcode/problems/the-number-of-weak-characters-in-the-game.h"

#include <algorithm>

namespace leetcode::problem_1996 {

namespace {

// Sort by attack descending; within equal attack, sort by defense ascending.
// Iterate once, tracking the max defense seen among strictly greater attack
// characters. A character is weak if its defense < that max. Equal-attack
// characters are ordered by ascending defense so the max from the previous
// (higher attack) group is used before any of them can consume it, while within
// the group no weak relationship exists (attack not strictly greater).
int numberOfWeakCharactersImpl(std::vector<std::vector<int>>& properties) {
  std::sort(properties.begin(), properties.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) {
              if (a[0] != b[0]) return a[0] > b[0];  // attack descending
              return a[1] < b[1];                    // defense ascending
            });

  int weakCount = 0;
  int maxDefense = 0;
  for (const auto& prop : properties) {
    if (prop[1] < maxDefense) {
      ++weakCount;
    } else {
      maxDefense = prop[1];
    }
  }
  return weakCount;
}

}  // namespace

namespace {
// Re-export as a callable matching Func for the SolutionBase. Since the helper is
// a free function, bind it directly.
}

int TheNumberOfWeakCharactersInTheGameSolution::numberOfWeakCharacters(
    std::vector<std::vector<int>>& properties) {
  return numberOfWeakCharactersImpl(properties);
}

TheNumberOfWeakCharactersInTheGameSolution::
    TheNumberOfWeakCharactersInTheGameSolution() {
  setMetaInfo({.id = 1996,
               .title = "The Number of Weak Characters in the Game",
               .url =
                   "https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/"});
  registerStrategy({.name = "sortAndGreedy",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(log n)",
                    .tags = {"Sorting", "Greedy"}},
                   static_cast<Func>(numberOfWeakCharactersImpl));
}

}  // namespace leetcode::problem_1996
