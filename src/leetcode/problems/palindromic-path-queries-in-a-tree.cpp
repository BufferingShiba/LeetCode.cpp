#include "leetcode/problems/palindromic-path-queries-in-a-tree.h"

#include <functional>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

namespace leetcode::problem_3841 {

namespace {

// XOR Fenwick tree supporting range XOR update + single point query using the
// difference technique: add(pos, val) XORs val into the suffix starting at
// pos; query(pos) returns the prefix XOR which equals the point value.
class XorBIT {
 public:
  explicit XorBIT(int n) : bit_(n + 2, 0) {}

  // XOR val into every index >= pos (1-indexed).
  void add(int pos, int val) {
    for (int i = pos; i < static_cast<int>(bit_.size()); i += i & (-i))
      bit_[i] ^= val;
  }

  // Prefix XOR up to pos (1-indexed) = single point value at pos.
  int query(int pos) const {
    int res = 0;
    for (int i = pos; i > 0; i -= i & (-i)) res ^= bit_[i];
    return res;
  }

 private:
  std::vector<int> bit_;
};

static std::vector<bool> palindromePathImpl(
    int n, std::vector<std::vector<int>>& edges, std::string& s,
    std::vector<std::string>& queries) {
  std::vector<std::vector<int>> adj(n);
  for (auto& e : edges) {
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
  }

  int LOG = 1;
  while ((1 << LOG) <= n) ++LOG;

  std::vector<int> in(n), out(n), depth(n, 0);
  std::vector<std::vector<int>> up(n, std::vector<int>(LOG, 0));
  for (int k = 0; k < LOG; ++k) up[0][k] = 0;

  int timer = 0;
  std::function<void(int, int)> dfs = [&](int u, int parent) {
    in[u] = ++timer;
    if (parent != -1) {
      depth[u] = depth[parent] + 1;
      up[u][0] = parent;
      for (int k = 1; k < LOG; ++k) up[u][k] = up[up[u][k - 1]][k - 1];
    }
    for (int v : adj[u]) {
      if (v == parent) continue;
      dfs(v, u);
    }
    out[u] = timer;
  };
  dfs(0, -1);

  std::vector<int> charMaskVec(n);
  for (int i = 0; i < n; ++i) charMaskVec[i] = 1 << (s[i] - 'a');

  // base[x] = initial parity mask of chars on path root -> x.
  std::vector<int> base(n, 0);
  {
    std::function<void(int, int)> dfs2 = [&](int u, int parent) {
      if (parent == -1)
        base[u] = charMaskVec[u];
      else
        base[u] = base[parent] ^ charMaskVec[u];
      for (int v : adj[u]) {
        if (v == parent) continue;
        dfs2(v, u);
      }
    };
    dfs2(0, -1);
  }

  auto lca = [&](int a, int b) {
    if (depth[a] < depth[b]) std::swap(a, b);
    int diff = depth[a] - depth[b];
    for (int k = 0; k < LOG; ++k)
      if (diff & (1 << k)) a = up[a][k];
    if (a == b) return a;
    for (int k = LOG - 1; k >= 0; --k) {
      if (up[a][k] != up[b][k]) {
        a = up[a][k];
        b = up[b][k];
      }
    }
    return up[a][0];
  };

  XorBIT bit(n);
  auto getRootMask = [&](int x) -> int { return base[x] ^ bit.query(in[x]); };

  std::vector<bool> ans;
  for (const std::string& q : queries) {
    std::istringstream iss(q);
    std::string typ;
    iss >> typ;
    if (typ == "update") {
      int u;
      char c;
      iss >> u >> c;
      int newMask = 1 << (c - 'a');
      if (newMask != charMaskVec[u]) {
        int delta = charMaskVec[u] ^ newMask;
        charMaskVec[u] = newMask;
        // XOR delta into every node in the subtree of u.
        bit.add(in[u], delta);
        bit.add(out[u] + 1, delta);
      }
    } else {  // query
      int u, v;
      iss >> u >> v;
      int l = lca(u, v);
      int pathMask = getRootMask(u) ^ getRootMask(v) ^ charMaskVec[l];
      ans.push_back(__builtin_popcount(pathMask) <= 1);
    }
  }
  return ans;
}

}  // namespace

PalindromicPathQueriesInATreeSolution::PalindromicPathQueriesInATreeSolution() {
  setMetaInfo({.id = 3841,
               .title = "Palindromic Path Queries in a Tree",
               .url = "https://leetcode.com/problems/palindromic-path-queries-in-a-tree/"});
  registerStrategy(
      {
          .name = "euler-tour-xor-segtree-lca",
          .expected = "Accepted",
          .time_complexity = "O((n+q) log n)",
          .space_complexity = "O(n log n)",
          .tags = {"Tree", "Depth-First Search", "Bit Manipulation",
                   "Segment Tree"},
          .notes = "Euler tour + XOR Fenwick (subtree range update / point "
                   "query) maintaining root-parity masks, plus binary-lifting "
                   "LCA. Path can be rearranged into a palindrome iff at most "
                   "one char occurs an odd number of times.",
      },
      palindromePathImpl);
}

std::vector<bool> PalindromicPathQueriesInATreeSolution::palindromePath(
    int n, std::vector<std::vector<int>>& edges, std::string& s,
    std::vector<std::string>& queries) {
  return getSolution()(n, edges, s, queries);
}

}  // namespace leetcode::problem_3841
