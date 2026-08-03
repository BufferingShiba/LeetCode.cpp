#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "leetcode/problems/restore-the-array-from-adjacent-pairs.h"

namespace leetcode {
namespace problem_1743 {

namespace {

std::vector<int> restoreArrayImpl(std::vector<std::vector<int>>& adjacentPairs) {
  std::unordered_map<int, std::vector<int>> adj;
  for (const auto& p : adjacentPairs) {
    adj[p[0]].push_back(p[1]);
    adj[p[1]].push_back(p[0]);
  }

  // 找一个度数为 1 的端点作为起点
  int start = 0;
  for (const auto& kv : adj) {
    if (kv.second.size() == 1) {
      start = kv.first;
      break;
    }
  }

  std::vector<int> result;
  std::unordered_set<int> seen;
  result.reserve(adj.size());

  int cur = start;
  seen.insert(cur);
  result.push_back(cur);

  while (result.size() < adj.size()) {
    int next = -1;
    for (int nb : adj[cur]) {
      if (seen.find(nb) == seen.end()) {
        next = nb;
        break;
      }
    }
    cur = next;
    seen.insert(cur);
    result.push_back(cur);
  }

  return result;
}

}  // namespace

RestoreTheArrayFromAdjacentPairsSolution::RestoreTheArrayFromAdjacentPairsSolution() {
  this->setMetaInfo({.id = 1743,
                     .title = "Restore the Array From Adjacent Pairs",
                     .url = "https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/"});

  this->registerStrategy(
      {.name = "graph-traversal",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Depth-First Search"}},
      restoreArrayImpl);
}

std::vector<int> RestoreTheArrayFromAdjacentPairsSolution::restoreArray(
    std::vector<std::vector<int>>& adjacentPairs) {
  return this->getSolution()(adjacentPairs);
}

}  // namespace problem_1743
}  // namespace leetcode
