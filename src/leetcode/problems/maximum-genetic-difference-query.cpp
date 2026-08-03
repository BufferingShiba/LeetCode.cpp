#include "leetcode/problems/maximum-genetic-difference-query.h"

#include <algorithm>
#include <array>
#include <vector>

namespace leetcode {
namespace problem_1938 {
namespace {

constexpr int kBit = 18;  // val <= 2*10^5 < 2^18

// Binary Trie with per-node child counts to support insert/erase and max-XOR query.
class BinaryTrie {
 public:
  struct Node {
    int child[2] = {-1, -1};
    int cnt = 0;
  };

  std::vector<Node> nodes;

  BinaryTrie() { nodes.push_back(Node{}); }

  int newNode() {
    nodes.push_back(Node{});
    return static_cast<int>(nodes.size()) - 1;
  }

  void insert(int x) {
    int cur = 0;
    nodes[cur].cnt++;
    for (int b = kBit - 1; b >= 0; --b) {
      int bit = (x >> b) & 1;
      if (nodes[cur].child[bit] == -1) nodes[cur].child[bit] = newNode();
      cur = nodes[cur].child[bit];
      nodes[cur].cnt++;
    }
  }

  void erase(int x) {
    int cur = 0;
    nodes[cur].cnt--;
    for (int b = kBit - 1; b >= 0; --b) {
      int bit = (x >> b) & 1;
      cur = nodes[cur].child[bit];
      nodes[cur].cnt--;
    }
  }

  // Max of x XOR value over all values in the trie.
  int maxXor(int x) const {
    int cur = 0;
    int result = 0;
    for (int b = kBit - 1; b >= 0; --b) {
      int bit = (x >> b) & 1;
      int want = 1 - bit;
      if (nodes[cur].child[want] != -1 && nodes[nodes[cur].child[want]].cnt > 0) {
        result |= (1 << b);
        cur = nodes[cur].child[want];
      } else {
        cur = nodes[cur].child[bit];
      }
    }
    return result;
  }
};

std::vector<int> solveByTrieBacktrack(std::vector<int>& parents,
                                      std::vector<std::vector<int>>& queries) {
  int n = static_cast<int>(parents.size());
  int root = -1;
  std::vector<std::vector<int>> children(n);
  for (int i = 0; i < n; ++i) {
    if (parents[i] == -1) {
      root = i;
    } else {
      children[parents[i]].push_back(i);
    }
  }

  int q = static_cast<int>(queries.size());
  // Group queries by node.
  std::vector<std::vector<std::pair<int, int>>> byNode(n);  // (val, queryIndex)
  for (int i = 0; i < q; ++i) {
    byNode[queries[i][0]].push_back({queries[i][1], i});
  }

  std::vector<int> ans(q, 0);
  BinaryTrie trie;

  std::function<void(int)> dfs = [&](int node) {
    trie.insert(node);
    for (const auto& pr : byNode[node]) {
      ans[pr.second] = trie.maxXor(pr.first);
    }
    for (int child : children[node]) {
      dfs(child);
    }
    trie.erase(node);
  };

  dfs(root);
  return ans;
}

}  // namespace

MaximumGeneticDifferenceQuerySolution::MaximumGeneticDifferenceQuerySolution() {
  setMetaInfo({
      .id = 1938,
      .title = "Maximum Genetic Difference Query",
      .url = "https://leetcode.com/problems/maximum-genetic-difference-query/",
  });
  registerStrategy(
      {
          .name = "TrieBacktrack",
          .expected = "Accepted",
          .time_complexity = "O((n+q) * B)",
          .space_complexity = "O(n * B + q)",
          .tags = {"Trie", "Depth-First Search", "Bit Manipulation"},
          .notes = "DFS + binary trie with backtracking to answer max-XOR on root-to-node path",
      },
      solveByTrieBacktrack);
}

}  // namespace problem_1938
}  // namespace leetcode
