#include "leetcode/problems/count-non-adjacent-subsets-in-a-rooted-tree.h"

namespace leetcode {
namespace problem_3939 {

namespace {
constexpr int MOD = 1'000'000'007;

int countValidSubsetsImpl(std::vector<int>& parent, std::vector<int>& nums, int k) {
  int n = static_cast<int>(parent.size());

  // Build children adjacency list
  std::vector<std::vector<int>> children(n);
  for (int i = 1; i < n; ++i) {
    children[parent[i]].push_back(i);
  }

  // dp_not[u][r]: number of valid subsets in subtree of u, NOT selecting u
  // dp_sel[u][r]: number of valid subsets in subtree of u, selecting u
  std::vector<std::vector<int>> dp_not(n, std::vector<int>(k, 0));
  std::vector<std::vector<int>> dp_sel(n, std::vector<int>(k, 0));

  // Process nodes bottom-up (parent[i] < i guarantees reverse order works)
  for (int u = n - 1; u >= 0; --u) {
    // Initialize: dp_not with empty subset, dp_sel with the node itself
    dp_not[u][0] = 1;
    int val_mod = static_cast<int>((static_cast<long long>(nums[u]) % k + k) % k);
    dp_sel[u][val_mod] = 1;

    for (int v : children[u]) {
      std::vector<int> new_not(k, 0);
      std::vector<int> new_sel(k, 0);

      // Merge dp_not[u] with (dp_not[v] + dp_sel[v]): child may be selected or not
      for (int r1 = 0; r1 < k; ++r1) {
        if (dp_not[u][r1] == 0) continue;
        for (int r2 = 0; r2 < k; ++r2) {
          int combined = dp_not[v][r2] + dp_sel[v][r2];
          if (combined >= MOD) combined -= MOD;
          if (combined == 0) continue;
          int nr = r1 + r2;
          if (nr >= k) nr -= k;
          new_not[nr] = (new_not[nr] + 1LL * dp_not[u][r1] * combined) % MOD;
        }
      }

      // Merge dp_sel[u] with dp_not[v]: child must NOT be selected
      for (int r1 = 0; r1 < k; ++r1) {
        if (dp_sel[u][r1] == 0) continue;
        for (int r2 = 0; r2 < k; ++r2) {
          if (dp_not[v][r2] == 0) continue;
          int nr = r1 + r2;
          if (nr >= k) nr -= k;
          new_sel[nr] = (new_sel[nr] + 1LL * dp_sel[u][r1] * dp_not[v][r2]) % MOD;
        }
      }

      dp_not[u] = std::move(new_not);
      dp_sel[u] = std::move(new_sel);
    }
  }

  int ans = dp_not[0][0] + dp_sel[0][0];
  if (ans >= MOD) ans -= MOD;
  ans = (ans - 1 + MOD) % MOD;  // exclude the empty subset
  return ans;
}
}  // namespace

CountNonAdjacentSubsetsInARootedTreeSolution::CountNonAdjacentSubsetsInARootedTreeSolution() {
  setMetaInfo({.id = 3939,
               .title = "Count Non Adjacent Subsets in a Rooted Tree",
               .url = "https://leetcode.com/problems/count-non-adjacent-subsets-in-a-rooted-tree/"});
  registerStrategy({.name = "tree_dp",
                     .expected = "Accepted",
                     .time_complexity = "O(n * k^2)",
                     .space_complexity = "O(n * k)",
                     .tags = {"Array", "Dynamic Programming", "Tree", "Depth-First Search"}},
                    countValidSubsetsImpl);
}

int CountNonAdjacentSubsetsInARootedTreeSolution::countValidSubsets(
    std::vector<int>& parent, std::vector<int>& nums, int k) {
  return getSolution()(parent, nums, k);
}

}  // namespace problem_3939
}  // namespace leetcode
