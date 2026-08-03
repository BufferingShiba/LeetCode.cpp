#include "leetcode/problems/take-gifts-from-the-richest-pile.h"

#include <cmath>
#include <queue>

namespace leetcode {
namespace problem_2558 {

TakeGiftsFromTheRichestPileSolution::TakeGiftsFromTheRichestPileSolution() {
  setMetaInfo({2558, "Take Gifts From the Richest Pile",
               "https://leetcode.com/problems/take-gifts-from-the-"
               "richest-pile/"});

  SolutionBase<Func>::StrategyMetadata md;
  md.name = "max-heap-simulation";
  md.expected = "Accepted";
  md.time_complexity = "O(k log n)";
  md.space_complexity = "O(n)";
  md.tags = {"Array", "Heap (Priority Queue)", "Simulation"};
  registerStrategy(md, pickGiftsImpl);
}

long long TakeGiftsFromTheRichestPileSolution::pickGifts(
    std::vector<int>& gifts, int k) {
  return getSolution()(gifts, k);
}

long long TakeGiftsFromTheRichestPileSolution::pickGiftsImpl(
    std::vector<int>& gifts, int k) {
  std::priority_queue<int> pq(gifts.begin(), gifts.end());
  for (int i = 0; i < k; ++i) {
    int top = pq.top();
    pq.pop();
    pq.push(static_cast<int>(std::sqrt(static_cast<double>(top))));
  }
  long long total = 0;
  while (!pq.empty()) {
    total += pq.top();
    pq.pop();
  }
  return total;
}

}  // namespace problem_2558
}  // namespace leetcode
