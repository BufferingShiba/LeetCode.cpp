#include "leetcode/problems/digit-frequency-score.h"

namespace leetcode::problem_3945 {

namespace {

int digitFrequencyScoreImpl(int n) {
  int count[10] = {};
  while (n > 0) {
    ++count[n % 10];
    n /= 10;
  }
  int score = 0;
  for (int d = 0; d <= 9; ++d) {
    score += d * count[d];
  }
  return score;
}

}  // namespace

DigitFrequencyScoreSolution::DigitFrequencyScoreSolution() {
  setMetaInfo({.id = 3945,
               .title = "Digit Frequency Score",
               .url = "https://leetcode.com/problems/digit-frequency-score/"});
  registerStrategy({.name = "DigitCounting",
                    .expected = "Accepted",
                    .time_complexity = "O(k)",
                    .space_complexity = "O(1)",
                    .tags = {"Hash Table", "Math"}},
                   digitFrequencyScoreImpl);
}

int DigitFrequencyScoreSolution::digitFrequencyScore(int n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_3945
