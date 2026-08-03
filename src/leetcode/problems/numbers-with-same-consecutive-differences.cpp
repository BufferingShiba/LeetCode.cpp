#include "leetcode/problems/numbers-with-same-consecutive-differences.h"

#include <cmath>
#include <vector>

namespace leetcode {
namespace problem_967 {

static void dfs(int n, int k, int pos, int num, std::vector<int>& res) {
  if (pos == n) {
    res.push_back(num);
    return;
  }
  int last = num % 10;
  if (k == 0) {
    dfs(n, k, pos + 1, num * 10 + last, res);
  } else {
    if (last - k >= 0) dfs(n, k, pos + 1, num * 10 + (last - k), res);
    if (last + k <= 9) dfs(n, k, pos + 1, num * 10 + (last + k), res);
  }
}

static vector<int> solution1(int n, int k) {
  std::vector<int> res;
  for (int d = 1; d <= 9; ++d) {
    dfs(n, k, 1, d, res);
  }
  return res;
}

NumbersWithSameConsecutiveDifferencesSolution::NumbersWithSameConsecutiveDifferencesSolution() {
  setMetaInfo({
      .id = 967,
      .title = "Numbers With Same Consecutive Differences",
      .url = "https://leetcode.com/problems/numbers-with-same-consecutive-differences"
  });
  registerStrategy({.name = "DFS", .time_complexity = "O(2^n)", .space_complexity = "O(n)", .tags = {"DFS", "Backtracking"}}, solution1);
}

vector<int> NumbersWithSameConsecutiveDifferencesSolution::numsSameConsecDiff(int n, int k) {
  return getSolution()(n, k);
}

}  // namespace problem_967
}  // namespace leetcode
