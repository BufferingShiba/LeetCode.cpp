#include "leetcode/problems/minimum-number-of-operations-to-move-all-balls-to-each-box.h"

namespace leetcode {
namespace problem_1769 {

static vector<int> solution1(string boxes) {
  int n = static_cast<int>(boxes.size());
  vector<int> answer(n, 0);

  // Accumulate the contribution from the left and right independently.  When
  // moving one position to the right, every ball already seen adds one move.
  int balls = 0;
  int moves = 0;
  for (int i = 0; i < n; ++i) {
    answer[i] += moves;
    if (boxes[i] == '1') ++balls;
    moves += balls;
  }

  balls = 0;
  moves = 0;
  for (int i = n - 1; i >= 0; --i) {
    answer[i] += moves;
    if (boxes[i] == '1') ++balls;
    moves += balls;
  }
  return answer;
}

MinimumNumberOfOperationsToMoveAllBallsToEachBoxSolution::MinimumNumberOfOperationsToMoveAllBallsToEachBoxSolution() {
  setMetaInfo({
      .id = 1769,
      .title = "Minimum Number of Operations to Move All Balls to Each Box",
      .url = "https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box"
  });
  registerStrategy({.name = "Bidirectional Prefix Accumulation",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "String", "Prefix Sum"}},
                   solution1);
}

vector<int> MinimumNumberOfOperationsToMoveAllBallsToEachBoxSolution::minOperations(string boxes) {
  return getSolution()(boxes);
}

}  // namespace problem_1769
}  // namespace leetcode
