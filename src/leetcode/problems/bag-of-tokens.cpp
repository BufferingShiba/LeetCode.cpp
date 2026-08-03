#include "leetcode/problems/bag-of-tokens.h"

#include <algorithm>

namespace leetcode {
namespace problem_948 {

// Greedy with two pointers:
// - Sort tokens ascending.
// - Play the smallest affordable token face-up to gain score.
// - When no token is affordable, if score > 0, play the largest
//   token face-down to gain power (best trade: lose 1 score for max power).
// - Track the maximum score ever achieved.
static int solution1(vector<int>& tokens, int power) {
  std::sort(tokens.begin(), tokens.end());
  int score = 0;
  int max_score = 0;
  int left = 0;
  int right = static_cast<int>(tokens.size()) - 1;

  while (left <= right) {
    // Buy the cheapest affordable token face-up.
    if (power >= tokens[left]) {
      power -= tokens[left];
      ++left;
      ++score;
      max_score = std::max(max_score, score);
    } else if (score > 0) {
      // Sell the most valuable token face-down for power.
      power += tokens[right];
      --right;
      --score;
    } else {
      break;
    }
  }

  return max_score;
}

BagOfTokensSolution::BagOfTokensSolution() {
  setMetaInfo({
      .id = 948,
      .title = "Bag of Tokens",
      .url = "https://leetcode.com/problems/bag-of-tokens"
  });
  registerStrategy({.name = "Greedy (Sort + Two Pointers)",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(1)",
                    .tags = {"Greedy", "Two Pointers", "Sorting"}},
                   solution1);
}

int BagOfTokensSolution::bagOfTokensScore(vector<int>& tokens, int power) {
  return getSolution()(tokens, power);
}

}  // namespace problem_948
}  // namespace leetcode
