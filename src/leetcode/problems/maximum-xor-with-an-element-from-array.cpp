#include "leetcode/problems/maximum-xor-with-an-element-from-array.h"

#include <algorithm>
#include <array>
#include <utility>

namespace leetcode {
namespace problem_1707 {

namespace {

constexpr int kBits = 30;

struct TrieNode {
  std::array<int, 2> child{-1, -1};
};

int maximizeXorImpl(std::vector<int>& nums,
                    std::vector<std::vector<int>>& queries) {
  return 0;  // placeholder, replaced below
}

}  // namespace

MaximumXorWithAnElementFromArraySolution::
    MaximumXorWithAnElementFromArraySolution() {
  setMetaInfo({.id = 1707,
               .title = "Maximum XOR With an Element From Array",
               .url = "https://leetcode.com/problems/maximum-xor-with-an-element-from-array/"});
  registerStrategy(
      {.name = "sort_and_trie",
       .expected = "Accepted",
       .time_complexity = "O((n+q)*30)",
       .space_complexity = "O(n*30)",
       .tags = {"Array", "Bit Manipulation", "Trie"}},
      [](std::vector<int>& nums, std::vector<std::vector<int>>& queries)
          -> std::vector<int> {
        std::sort(nums.begin(), nums.end());

        int q = static_cast<int>(queries.size());
        std::vector<std::pair<std::pair<int, int>, int>> indexed;  // ((x,m),idx)
        indexed.reserve(q);
        for (int i = 0; i < q; ++i) {
          indexed.push_back({{queries[i][0], queries[i][1]}, i});
        }
        std::sort(indexed.begin(), indexed.end(),
                  [](const auto& a, const auto& b) {
                    return a.first.second < b.first.second;
                  });

        std::vector<TrieNode> trie(1);  // root at index 0
        auto insert = [&trie](int val) {
          int node = 0;
          for (int bit = kBits - 1; bit >= 0; --bit) {
            int b = (val >> bit) & 1;
            if (trie[node].child[b] == -1) {
              trie[node].child[b] = static_cast<int>(trie.size());
              trie.push_back(TrieNode{});
            }
            node = trie[node].child[b];
          }
        };
        auto query = [&trie](int x) -> int {
          int node = 0;
          int result = 0;
          for (int bit = kBits - 1; bit >= 0; --bit) {
            int b = (x >> bit) & 1;
            int want = b ^ 1;
            if (trie[node].child[want] != -1) {
              result |= (1 << bit);
              node = trie[node].child[want];
            } else {
              node = trie[node].child[b];
            }
          }
          return result;
        };

        std::vector<int> answer(q, -1);
        int ptr = 0;
        for (const auto& entry : indexed) {
          int x = entry.first.first;
          int m = entry.first.second;
          int idx = entry.second;
          while (ptr < static_cast<int>(nums.size()) &&
                 nums[ptr] <= m) {
            insert(nums[ptr]);
            ++ptr;
          }
          if (ptr > 0) {
            answer[idx] = query(x);
          }
        }
        return answer;
      });
}

std::vector<int> MaximumXorWithAnElementFromArraySolution::maximizeXor(
    std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
  return getSolution()(nums, queries);
}

}  // namespace problem_1707
}  // namespace leetcode
