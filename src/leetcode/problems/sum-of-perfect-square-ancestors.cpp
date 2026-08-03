#include "leetcode/problems/sum-of-perfect-square-ancestors.h"

#include <functional>
#include <vector>

namespace leetcode::problem_3715 {

// ---------- 预处理：平方自由部分 ----------

static constexpr int kMaxVal = 100000;
static std::vector<int> spf;   // smallest prime factor
static std::vector<int> core;  // square-free core

static void initSieve() {
  if (!spf.empty()) return;
  spf.resize(kMaxVal + 1);
  core.resize(kMaxVal + 1);

  // 埃氏筛求最小质因子
  for (int i = 2; i <= kMaxVal; ++i) {
    if (spf[i] == 0) {          // i 是质数
      spf[i] = i;
      if ((long long)i * i <= kMaxVal) {
        for (int j = i * i; j <= kMaxVal; j += i) {
          if (spf[j] == 0) spf[j] = i;
        }
      }
    }
  }

  // 计算每个数的 core（只保留奇数次幂的质因子）
  core[1] = 1;
  for (int i = 2; i <= kMaxVal; ++i) {
    int x = i;
    int res = 1;
    while (x > 1) {
      int p = spf[x];
      int cnt = 0;
      while (x % p == 0) {
        x /= p;
        cnt ^= 1;  // toggle parity
      }
      if (cnt) res *= p;
    }
    core[i] = res;
  }
}

// ---------- 策略实现 ----------

static long long sumOfAncestorsImpl(int n,
                                    std::vector<std::vector<int>>& edges,
                                    std::vector<int>& nums) {
  initSieve();

  // 构建邻接表
  std::vector<std::vector<int>> adj(n);
  for (auto& e : edges) {
    int u = e[0], v = e[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // cnt[core] 记录当前路径上各 core 的出现次数
  std::vector<int> cnt(kMaxVal + 1, 0);
  long long ans = 0;

  // 迭代 DFS（避免 n=1e5 链状递归爆栈）
  std::vector<std::pair<int, int>> stack;  // {node, parent}
  stack.reserve(n);
  stack.emplace_back(0, -1);
  std::vector<bool> visited(n, false);

  while (!stack.empty()) {
    auto [node, parent] = stack.back();
    if (!visited[node]) {
      // 进入节点
      visited[node] = true;
      int c = core[nums[node]];
      ans += cnt[c];          // 累加祖先中 core 相同的数量
      cnt[c]++;               // 当前节点加入路径
      // 子节点入栈
      for (int child : adj[node]) {
        if (child != parent) {
          stack.emplace_back(child, node);
        }
      }
    } else {
      // 离开节点（所有子节点已处理）
      int c = core[nums[node]];
      cnt[c]--;               // 当前节点离开路径
      stack.pop_back();
    }
  }

  return ans;
}

// ---------- 构造与注册 ----------

SumOfPerfectSquareAncestorsSolution::SumOfPerfectSquareAncestorsSolution() {
  setMetaInfo({.id = 3715,
               .title = "Sum of Perfect Square Ancestors",
               .url = "https://leetcode.com/problems/sum-of-perfect-square-ancestors/"});
  registerStrategy(
      {.name = "SquareFreeCore",
       .expected = "Accepted",
       .time_complexity = "O(n log M + M log log M)",
       .space_complexity = "O(n + M)",
       .tags = {"Array", "Hash Table", "Math", "Tree", "Depth-First Search",
                "Counting", "Number Theory"}},
      sumOfAncestorsImpl);
}

long long SumOfPerfectSquareAncestorsSolution::sumOfAncestors(
    int n, std::vector<std::vector<int>>& edges, std::vector<int>& nums) {
  return getSolution()(n, edges, nums);
}

}  // namespace leetcode::problem_3715
