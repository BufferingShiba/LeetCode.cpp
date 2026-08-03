#include "leetcode/problems/count-prefix-and-suffix-pairs-ii.h"

#include <unordered_map>
#include <vector>

namespace leetcode::problem_3045 {

namespace {

long long countPrefixSuffixPairsImpl(std::vector<std::string>& words) {
  // count[i] = number of words ending exactly at trie node i
  std::vector<int> cnt(1, 0);
  // Single global map for all edges: key = (node << 10) | pair_code (0..675)
  std::unordered_map<long long, int> nxt;

  // Pre-compute total number of character pairs to reserve space
  long long total_pairs = 0;
  for (const auto& w : words) {
    total_pairs += static_cast<int>(w.size());
  }
  cnt.reserve(static_cast<std::size_t>(total_pairs) + 1);
  nxt.reserve(static_cast<std::size_t>(total_pairs));

  long long ans = 0;

  for (const auto& w : words) {
    const int n = static_cast<int>(w.size());

    // ---------- Query: count previous words that are prefix-suffix of w ----------
    int node = 0;
    for (int i = 0; i < n; ++i) {
      int front = w[i] - 'a';
      int back = w[n - 1 - i] - 'a';
      int code = front * 26 + back;  // 0 .. 675
      long long key = (static_cast<long long>(node) << 10) | code;
      auto it = nxt.find(key);
      if (it == nxt.end()) {
        break;
      }
      node = it->second;
      ans += cnt[node];
    }

    // ---------- Insert w into trie ----------
    node = 0;
    for (int i = 0; i < n; ++i) {
      int front = w[i] - 'a';
      int back = w[n - 1 - i] - 'a';
      int code = front * 26 + back;
      long long key = (static_cast<long long>(node) << 10) | code;
      auto it = nxt.find(key);
      if (it == nxt.end()) {
        int nxt_node = static_cast<int>(cnt.size());
        nxt[key] = nxt_node;
        cnt.push_back(0);
        node = nxt_node;
      } else {
        node = it->second;
      }
    }
    ++cnt[node];
  }

  return ans;
}

}  // namespace

CountPrefixAndSuffixPairsIiSolution::CountPrefixAndSuffixPairsIiSolution() {
  setMetaInfo({.id = 3045,
                .title = "Count Prefix and Suffix Pairs II",
                .url = "https://leetcode.com/problems/count-prefix-and-suffix-pairs-ii/"});
  registerStrategy(
      {.name = "Pair Encoding + Trie",
       .expected = "Accepted",
       .time_complexity = "O(Σ|words[i]|)",
       .space_complexity = "O(Σ|words[i]|)",
       .tags = {"Array", "String", "Trie", "Rolling Hash", "String Matching", "Hash Function"}},
      countPrefixSuffixPairsImpl);
}

long long CountPrefixAndSuffixPairsIiSolution::countPrefixSuffixPairs(
    std::vector<std::string>& words) {
  return getSolution()(words);
}

}  // namespace leetcode::problem_3045
