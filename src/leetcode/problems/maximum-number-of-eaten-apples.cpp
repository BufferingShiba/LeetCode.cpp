#include "leetcode/problems/maximum-number-of-eaten-apples.h"

#include <queue>
#include <utility>

namespace leetcode {
namespace problem_1705 {

static int solution1(vector<int>& apples, vector<int>& days) {
  int n = static_cast<int>(apples.size());
  // Min-heap of {expiryDay, count}. Always eat the apple that rots soonest.
  using Node = std::pair<int, int>;  // {expiry, count}
  std::priority_queue<Node, std::vector<Node>, std::greater<Node>> heap;

  int eaten = 0;
  int day = 0;
  while (day < n || !heap.empty()) {
    if (day < n && apples[day] > 0) {
      heap.emplace(day + days[day], apples[day]);
    }
    // Discard apples that have rotted (expiry <= current day).
    while (!heap.empty() && heap.top().first <= day) {
      heap.pop();
    }
    if (!heap.empty()) {
      eaten++;
      Node top = heap.top();
      heap.pop();
      if (top.second > 1) {
        top.second--;
        heap.push(top);
      }
    }
    day++;
  }
  return eaten;
}

MaximumNumberOfEatenApplesSolution::MaximumNumberOfEatenApplesSolution() {
  setMetaInfo({
      .id = 1705,
      .title = "Maximum Number of Eaten Apples",
      .url = "https://leetcode.com/problems/maximum-number-of-eaten-apples"
  });
  registerStrategy({
      .name = "Greedy Min-Heap",
      .expected = "Accepted",
      .time_complexity = "O(n log n)",
      .space_complexity = "O(n)",
      .tags = {"Greedy", "Heap", "Priority Queue"},
  }, solution1);
}

int MaximumNumberOfEatenApplesSolution::eatenApples(vector<int>& apples, vector<int>& days) {
  return getSolution()(apples, days);
}

}  // namespace problem_1705
}  // namespace leetcode
