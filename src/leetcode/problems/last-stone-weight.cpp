#include "leetcode/problems/last-stone-weight.h"

#include <queue>

namespace leetcode {
namespace problem_1046 {

static int lastStoneWeightImpl(std::vector<int>& stones) {
  std::priority_queue<int> pq;
  for (int s : stones) {
    pq.push(s);
  }
  while (pq.size() > 1) {
    int y = pq.top();
    pq.pop();
    int x = pq.top();
    pq.pop();
    if (x != y) {
      pq.push(y - x);
    }
  }
  return pq.empty() ? 0 : pq.top();
}

LastStoneWeightSolution::LastStoneWeightSolution() {
  setMetaInfo({.id = 1046, .title = "Last Stone Weight",
               .url = "https://leetcode.com/problems/last-stone-weight/"});
  registerStrategy(
      {.name = "MaxHeap", .expected = "Accepted",
       .time_complexity = "O(n log n)", .space_complexity = "O(n)",
       .tags = {"Array", "Heap (Priority Queue)"}},
      lastStoneWeightImpl);
  setDefaultStrategy();
}

int LastStoneWeightSolution::lastStoneWeight(std::vector<int>& stones) {
  return getSolution()(stones);
}

}  // namespace problem_1046
}  // namespace leetcode
