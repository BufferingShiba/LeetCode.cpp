#include "leetcode/problems/count-good-integers-on-a-grid-path.h"

#include <array>
#include <cstring>
#include <vector>

namespace leetcode::problem_3906 {

namespace {

long long countGoodIntegersOnPathImpl(long long l, long long r,
                                      std::string directions) {
  // Compute the 7 path cell row-major indices, starting from (0,0).
  std::vector<int> pathIdx;
  pathIdx.reserve(7);
  int row = 0, col = 0;
  pathIdx.push_back(0);
  for (char c : directions) {
    if (c == 'D') {
      ++row;
    } else {
      ++col;
    }
    pathIdx.push_back(row * 4 + col);
  }

  std::array<bool, 16> isPath{};
  for (int p : pathIdx) {
    isPath[p] = true;
  }

  // Digit DP counting good numbers <= n (n has a 16-digit zero-padded form).
  // State: position, tight, prev(0..9) or -1 for "no path digit placed yet".
  auto countLe = [&](long long n) -> long long {
    if (n < 0) {
      return 0;
    }
    std::array<int, 16> digits{};
    long long temp = n;
    for (int i = 15; i >= 0; --i) {
      digits[i] = static_cast<int>(temp % 10);
      temp /= 10;
    }

    std::array<std::array<std::array<long long, 11>, 2>, 17> memo;
    for (auto& a : memo) {
      for (auto& b : a) {
        b.fill(-1);
      }
    }

    std::function<long long(int, int, int)> dfs =
        [&](int idx, int tight, int prev) -> long long {
          if (idx == 16) {
            return 1;
          }
          int prevKey = prev + 1;  // -1 -> 0, 0..9 -> 1..10
          long long& cached = memo[idx][tight][prevKey];
          if (cached != -1) {
            return cached;
          }
          int limit = tight ? digits[idx] : 9;
          long long res = 0;
          bool isPathCell = isPath[idx];
          bool isFirstPath = (idx == pathIdx[0]);
          for (int d = 0; d <= limit; ++d) {
            if (isPathCell) {
              if (!isFirstPath && d < prev) {
                continue;
              }
              res += dfs(idx + 1, tight && (d == digits[idx]), d);
            } else {
              res += dfs(idx + 1, tight && (d == digits[idx]), prev);
            }
          }
          cached = res;
          return res;
        };

    return dfs(0, 1, -1);
  };

  return countLe(r) - countLe(l - 1);
}

}  // namespace

CountGoodIntegersOnAGridPathSolution::CountGoodIntegersOnAGridPathSolution() {
  setMetaInfo({.id = 3906,
               .title = "Count Good Integers on a Grid Path",
               .url =
                   "https://leetcode.com/problems/count-good-integers-on-a-grid-path/"});

  registerStrategy({.name = "digit-dp",
                    .expected = "Accepted",
                    .time_complexity = "O(16*2*11*10)",
                    .space_complexity = "O(16*2*11)",
                    .tags = {"Dynamic Programming"}},
                   countGoodIntegersOnPathImpl);
}

long long CountGoodIntegersOnAGridPathSolution::countGoodIntegersOnPath(
    long long l, long long r, std::string directions) {
  return getSolution()(l, r, std::move(directions));
}

}  // namespace leetcode::problem_3906
