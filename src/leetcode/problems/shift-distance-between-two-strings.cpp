#include "leetcode/problems/shift-distance-between-two-strings.h"

#include <algorithm>

namespace leetcode {
namespace problem_3361 {

static long long shiftDistanceImpl(std::string s, std::string t,
                                   std::vector<int>& nextCost,
                                   std::vector<int>& previousCost) {
  const long long LINF = 1e18;
  long long dist[26][26];

  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      dist[i][j] = (i == j) ? 0 : LINF;
    }
  }

  for (int i = 0; i < 26; ++i) {
    int nxt = (i + 1) % 26;
    int prv = (i - 1 + 26) % 26;
    dist[i][nxt] = std::min(dist[i][nxt], static_cast<long long>(nextCost[i]));
    dist[i][prv] = std::min(dist[i][prv], static_cast<long long>(previousCost[i]));
  }

  // Floyd-Warshall
  for (int k = 0; k < 26; ++k) {
    for (int i = 0; i < 26; ++i) {
      if (dist[i][k] == LINF) continue;
      for (int j = 0; j < 26; ++j) {
        if (dist[k][j] == LINF) continue;
        long long nd = dist[i][k] + dist[k][j];
        if (nd < dist[i][j]) {
          dist[i][j] = nd;
        }
      }
    }
  }

  long long ans = 0;
  int n = static_cast<int>(s.size());
  for (int i = 0; i < n; ++i) {
    int a = s[i] - 'a';
    int b = t[i] - 'a';
    ans += dist[a][b];
  }
  return ans;
}

ShiftDistanceBetweenTwoStringsSolution::ShiftDistanceBetweenTwoStringsSolution() {
  setMetaInfo({.id = 3361,
               .title = "Shift Distance Between Two Strings",
               .url = "https://leetcode.com/problems/shift-distance-between-two-strings/"});
  registerStrategy(
      {.name = "floyd_warshall",
       .expected = "Accepted",
       .time_complexity = "O(26^3 + n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "String", "Graph", "Shortest Path"}},
      shiftDistanceImpl);
}

long long ShiftDistanceBetweenTwoStringsSolution::shiftDistance(
    std::string s, std::string t, std::vector<int>& nextCost,
    std::vector<int>& previousCost) {
  return getSolution()(s, t, nextCost, previousCost);
}

}  // namespace problem_3361
}  // namespace leetcode
