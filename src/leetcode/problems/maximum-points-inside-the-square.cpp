#include "leetcode/problems/maximum-points-inside-the-square.h"

#include <algorithm>
#include <cstdlib>
#include <climits>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3143 {

namespace {

int maxPointsInsideSquareImpl(std::vector<std::vector<int>>& points, std::string& s) {
  const int n = static_cast<int>(points.size());
  // For each tag, track min half-side d1 and second-min half-side d2.
  const int INF = INT_MAX;
  std::vector<int> d1(26, INF);
  std::vector<int> d2(26, INF);

  for (int i = 0; i < n; ++i) {
    long long x = points[i][0];
    long long y = points[i][1];
    long long d = std::max(std::llabs(x), std::llabs(y));
    int idx = s[i] - 'a';
    if (d < d1[idx]) {
      d2[idx] = d1[idx];
      d1[idx] = static_cast<int>(d);
    } else if (d < d2[idx]) {
      d2[idx] = static_cast<int>(d);
    }
  }

  int cutoff = INF;
  for (int t = 0; t < 26; ++t) {
    cutoff = std::min(cutoff, d2[t]);
  }

  int ans = 0;
  for (int t = 0; t < 26; ++t) {
    if (d1[t] < cutoff) {
      ++ans;
    }
  }
  return ans;
}

}  // namespace

MaximumPointsInsideTheSquareSolution::MaximumPointsInsideTheSquareSolution() {
  setMetaInfo({.id = 3143,
               .title = "Maximum Points Inside the Square",
               .url = "https://leetcode.com/problems/maximum-points-inside-the-square/"});
  registerStrategy(
      {.name = "greedy-min-secondmin",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table", "String"}},
      maxPointsInsideSquareImpl);
}

int MaximumPointsInsideTheSquareSolution::maxPointsInsideSquare(
    std::vector<std::vector<int>>& points, std::string s) {
  return getSolution()(points, s);
}

}  // namespace problem_3143
}  // namespace leetcode
