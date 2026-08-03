#include "leetcode/problems/candy.h"

namespace leetcode::problem_135 {

namespace {

int candyImpl(std::vector<int>& ratings) {
  const int n = static_cast<int>(ratings.size());
  std::vector<int> candies(n, 1);

  // Left to right: child with higher rating than left neighbor gets more.
  for (int i = 1; i < n; ++i) {
    if (ratings[i] > ratings[i - 1]) {
      candies[i] = candies[i - 1] + 1;
    }
  }

  // Right to left: child with higher rating than right neighbor gets more.
  for (int i = n - 2; i >= 0; --i) {
    if (ratings[i] > ratings[i + 1]) {
      candies[i] = std::max(candies[i], candies[i + 1] + 1);
    }
  }

  int total = 0;
  for (int c : candies) {
    total += c;
  }
  return total;
}

}  // namespace

CandySolution::CandySolution() {
  setMetaInfo({.id = 135,
               .title = "Candy",
               .url = "https://leetcode.com/problems/candy/"});
  registerStrategy({.name = "TwoPassGreedy",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Greedy"}},
                   candyImpl);
}

int CandySolution::candy(std::vector<int>& ratings) {
  return getSolution()(ratings);
}

}  // namespace leetcode::problem_135
