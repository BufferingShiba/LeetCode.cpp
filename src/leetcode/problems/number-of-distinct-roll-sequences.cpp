#include "leetcode/problems/number-of-distinct-roll-sequences.h"

#include <vector>

namespace leetcode::problem_2318 {

namespace {

constexpr int kMod = 1'000'000'007;

int gcd(int a, int b) {
  while (b != 0) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int distinctSequencesImpl(int n) {
  if (n == 1) return 6;

  // dp[a][b] = number of sequences of current length ending with (a, b)
  // a = second-to-last roll, b = last roll; a, b in [1..6]
  int dp[7][7] = {};

  // Base: length 2
  for (int a = 1; a <= 6; ++a) {
    for (int b = 1; b <= 6; ++b) {
      if (a != b && gcd(a, b) == 1) {
        dp[a][b] = 1;
      }
    }
  }

  // Extend to longer lengths
  for (int len = 3; len <= n; ++len) {
    int next[7][7] = {};
    for (int a = 1; a <= 6; ++a) {
      for (int b = 1; b <= 6; ++b) {
        int cur = dp[a][b];
        if (cur == 0) continue;
        for (int c = 1; c <= 6; ++c) {
          // Condition 1: gcd(adjacent) = 1
          // Condition 2: c != b (distance 1) and c != a (distance 2)
          if (c != b && c != a && gcd(b, c) == 1) {
            next[b][c] = (next[b][c] + cur) % kMod;
          }
        }
      }
    }
    // Copy next back to dp
    for (int a = 1; a <= 6; ++a)
      for (int b = 1; b <= 6; ++b)
        dp[a][b] = next[a][b];
  }

  int total = 0;
  for (int a = 1; a <= 6; ++a)
    for (int b = 1; b <= 6; ++b)
      total = (total + dp[a][b]) % kMod;
  return total;
}

}  // namespace

NumberOfDistinctRollSequencesSolution::NumberOfDistinctRollSequencesSolution() {
  setMetaInfo({.id = 2318,
               .title = "Number of Distinct Roll Sequences",
               .url = "https://leetcode.com/problems/number-of-distinct-roll-sequences/"});
  registerStrategy({.name = "DP",
                    .expected = "Accepted",
                    .time_complexity = "O(n * 6^3)",
                    .space_complexity = "O(1)",
                    .tags = {"Dynamic Programming", "Memoization"}},
                   distinctSequencesImpl);
}

int NumberOfDistinctRollSequencesSolution::distinctSequences(int n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_2318
