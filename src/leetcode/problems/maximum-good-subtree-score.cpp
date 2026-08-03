#include "leetcode/problems/maximum-good-subtree-score.h"

#include <array>
#include <cstdint>
#include <functional>

namespace leetcode {
namespace problem_3575 {
namespace {

constexpr long long kNEG = -(1LL << 60);
constexpr long long kMod = 1000000007LL;
constexpr int kMaskCount = 1 << 10;

// 返回值的十进制 digit bitmask；若内部 digit 有重复则返回 -1（该节点永不可被选）。
int DigitMask(int v) {
  int mask = 0;
  while (v > 0) {
    int d = v % 10;
    if ((mask >> d) & 1) {
      return -1;
    }
    mask |= (1 << d);
    v /= 10;
  }
  return mask;
}

int Solve(std::vector<int>& vals, std::vector<int>& par) {
  const int n = static_cast<int>(vals.size());
  std::vector<std::vector<int>> children(n);
  for (int i = 1; i < n; ++i) {
    children[par[i]].push_back(i);
  }

  using DpArr = std::array<long long, kMaskCount>;
  std::vector<DpArr> dp(n);

  std::function<void(int)> dfs = [&](int u) {
    for (int m = 0; m < kMaskCount; ++m) {
      dp[u][m] = kNEG;
    }
    dp[u][0] = 0;  // 空集：u 子树中一个都不选。
    int own = DigitMask(vals[u]);
    if (own >= 0) {
      dp[u][own] = vals[u];
    }

    for (int c : children[u]) {
      dfs(c);
      DpArr nd;
      for (int m = 0; m < kMaskCount; ++m) {
        nd[m] = dp[u][m];
      }
      // 合并孩子 c：仅当两个 mask 不相交才可组合（digit 不重复）。
      for (int a = 0; a < kMaskCount; ++a) {
        if (dp[u][a] == kNEG) {
          continue;
        }
        int comp = (~a) & (kMaskCount - 1);
        for (int b = comp;; b = (b - 1) & comp) {
          if (dp[c][b] != kNEG) {
            long long val = dp[u][a] + dp[c][b];
            if (val > nd[a | b]) {
              nd[a | b] = val;
            }
          }
          if (b == 0) {
            break;
          }
        }
      }
      dp[u] = nd;
    }
  };

  dfs(0);

  long long ans = 0;
  for (int u = 0; u < n; ++u) {
    long long best = 0;
    for (int m = 0; m < kMaskCount; ++m) {
      if (dp[u][m] > best) {
        best = dp[u][m];
      }
    }
    ans = (ans + best) % kMod;
  }
  return static_cast<int>(ans);
}

}  // namespace

MaximumGoodSubtreeScoreSolution::MaximumGoodSubtreeScoreSolution() {
  setMetaInfo({.id = 3575,
               .title = "Maximum Good Subtree Score",
               .url = "https://leetcode.com/problems/maximum-good-subtree-score/"});
  registerStrategy(
      {.name = "tree-dp-bitmask",
       .expected = "Accepted",
       .time_complexity = "O(n * 3^10)",
       .space_complexity = "O(n * 2^10)",
       .tags = {"Tree", "Dynamic Programming", "Bit Manipulation"},
       .notes = "dp[u][mask] = max good subset score in u-subtree achieving digit mask; merge children with disjoint masks"},
      Solve);
}

}  // namespace problem_3575
}  // namespace leetcode
