#include "leetcode/problems/distant-barcodes.h"

#include <queue>
#include <unordered_map>
#include <utility>

namespace leetcode::problem_1054 {

namespace {

std::vector<int> rearrangeBarcodesImpl(std::vector<int>& barcodes) {
  std::unordered_map<int, int> count;
  for (int b : barcodes) {
    count[b]++;
  }

  // 最大堆：按频率降序排列
  auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
  };
  std::priority_queue<std::pair<int, int>,
                      std::vector<std::pair<int, int>>,
                      decltype(cmp)>
      pq(cmp);

  for (const auto& [val, cnt] : count) {
    pq.push({val, cnt});
  }

  std::vector<int> result;
  result.reserve(barcodes.size());

  while (pq.size() >= 2) {
    auto top1 = pq.top();
    pq.pop();
    auto top2 = pq.top();
    pq.pop();

    result.push_back(top1.first);
    result.push_back(top2.first);

    if (--top1.second > 0) pq.push(top1);
    if (--top2.second > 0) pq.push(top2);
  }

  if (!pq.empty()) {
    result.push_back(pq.top().first);
  }

  return result;
}

}  // namespace

DistantBarcodesSolution::DistantBarcodesSolution() {
  setMetaInfo({.id = 1054,
               .title = "Distant Barcodes",
               .url = "https://leetcode.com/problems/distant-barcodes/"});
  registerStrategy(
      {.name = "MaxHeap",
       .expected = "Accepted",
       .time_complexity = "O(n log k)",
       .space_complexity = "O(k)",
       .tags = {"Array", "Hash Table", "Greedy", "Heap (Priority Queue)",
                "Counting"}},
      rearrangeBarcodesImpl);
}

std::vector<int> DistantBarcodesSolution::rearrangeBarcodes(
    std::vector<int>& barcodes) {
  return getSolution()(barcodes);
}

}  // namespace leetcode::problem_1054
