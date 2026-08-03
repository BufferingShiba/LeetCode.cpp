#include "leetcode/problems/top-k-frequent-words.h"

#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode {
namespace problem_692 {

namespace {

std::vector<std::string> topKFrequentImpl(std::vector<std::string>& words, int k) {
  // 统计频率
  std::unordered_map<std::string, int> freq;
  for (const auto& w : words) {
    ++freq[w];
  }

  // 自定义比较器：堆顶是"最差"的元素（频率最低，或频率相同时字典序最大）
  auto cmp = [](const std::pair<int, std::string>& a,
                const std::pair<int, std::string>& b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
  };

  std::priority_queue<std::pair<int, std::string>,
                      std::vector<std::pair<int, std::string>>,
                      decltype(cmp)>
      pq(cmp);

  for (const auto& [word, count] : freq) {
    if (static_cast<int>(pq.size()) < k) {
      pq.emplace(count, word);
    } else {
      const auto& top = pq.top();
      // 当前词比堆顶更好：频率更高，或频率相同但字典序更小
      if (count > top.first || (count == top.first && word < top.second)) {
        pq.pop();
        pq.emplace(count, word);
      }
    }
  }

  // 弹出顺序是从最差到最好，反转得到题目要求的顺序
  std::vector<std::string> result;
  result.reserve(k);
  while (!pq.empty()) {
    result.push_back(pq.top().second);
    pq.pop();
  }
  std::reverse(result.begin(), result.end());
  return result;
}

}  // namespace

TopKFrequentWordsSolution::TopKFrequentWordsSolution() {
  setMetaInfo({.id = 692,
               .title = "Top K Frequent Words",
               .url = "https://leetcode.com/problems/top-k-frequent-words/"});
  registerStrategy(
      {.name = "MinHeap",
       .expected = "Accepted",
       .time_complexity = "O(n log k)",
       .space_complexity = "O(n)",
       .tags = {"Hash Table", "Heap", "Priority Queue", "Counting"}},
      topKFrequentImpl);
}

std::vector<std::string> TopKFrequentWordsSolution::topKFrequent(
    std::vector<std::string>& words, int k) {
  return getSolution()(words, k);
}

}  // namespace problem_692
}  // namespace leetcode
