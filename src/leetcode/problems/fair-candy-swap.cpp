#include "leetcode/problems/fair-candy-swap.h"

#include <numeric>
#include <unordered_set>

namespace leetcode {
namespace problem_888 {
namespace {

std::vector<int> fairCandySwapImpl(std::vector<int>& aliceSizes,
                                   std::vector<int>& bobSizes) {
  int sumA = std::accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
  int sumB = std::accumulate(bobSizes.begin(), bobSizes.end(), 0);
  int delta = (sumB - sumA) / 2;

  std::unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());
  for (int a : aliceSizes) {
    int b = a + delta;
    if (bobSet.count(b)) {
      return {a, b};
    }
  }
  return {};
}

}  // namespace

FairCandySwapSolution::FairCandySwapSolution() {
  setMetaInfo({.id = 888,
               .title = "Fair Candy Swap",
               .url = "https://leetcode.com/problems/fair-candy-swap/"});
  registerStrategy(
      {.name = "HashSet", .expected = "Accepted", .time_complexity = "O(n+m)",
       .space_complexity = "O(m)", .tags = {"Hash Table"}},
      fairCandySwapImpl);
}

std::vector<int> FairCandySwapSolution::fairCandySwap(
    std::vector<int>& aliceSizes, std::vector<int>& bobSizes) {
  return getSolution()(aliceSizes, bobSizes);
}

}  // namespace problem_888
}  // namespace leetcode
