#include "leetcode/problems/reorganize-string.h"

#include <queue>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_767 {
namespace {

std::string reorganizeByHeap(std::string s) {
  std::vector<int> count(26, 0);
  for (char c : s) count[c - 'a']++;

  // 可行性判断：最多字符数不能超过 (n+1)/2
  int maxCount = 0;
  for (int c : count) maxCount = std::max(maxCount, c);
  int n = static_cast<int>(s.size());
  if (maxCount > (n + 1) / 2) return "";

  // 最大堆，按频次降序，其次按字符字母序
  std::priority_queue<std::pair<int, char>> pq;
  for (int i = 0; i < 26; ++i) {
    if (count[i] > 0) pq.push({count[i], static_cast<char>('a' + i)});
  }

  std::string result;
  result.reserve(n);
  while (!pq.empty()) {
    auto top = pq.top();
    pq.pop();
    if (result.empty() || result.back() != top.second) {
      result.push_back(top.second);
      if (--top.first > 0) pq.push(top);
    } else {
      // 需要换下一个字符
      if (pq.empty()) return "";  // 理论上不可达（可行性已保证），防御性
      auto second = pq.top();
      pq.pop();
      result.push_back(second.second);
      if (--second.first > 0) pq.push(second);
      pq.push(top);
    }
  }
  return result;
}

}  // namespace

ReorganizeStringSolution::ReorganizeStringSolution() {
  setMetaInfo({.id = 767,
               .title = "Reorganize String",
               .url = "https://leetcode.com/problems/reorganize-string/"});

  registerStrategy(
      {.name = "GreedyMaxHeap",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "Greedy", "Heap", "Counting"}},
      reorganizeByHeap);
}

}  // namespace problem_767
}  // namespace leetcode
