#include "leetcode/problems/can-place-flowers.h"

namespace leetcode {
namespace problem_605 {

static bool canPlaceFlowersImpl(std::vector<int>& flowerbed, int n) {
  int cnt = 0;
  const int m = static_cast<int>(flowerbed.size());
  for (int i = 0; i < m; ++i) {
    if (flowerbed[i] == 0) {
      bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
      bool rightEmpty = (i == m - 1) || (flowerbed[i + 1] == 0);
      if (leftEmpty && rightEmpty) {
        flowerbed[i] = 1;
        ++cnt;
        if (cnt >= n) {
          return true;
        }
      }
    }
  }
  return cnt >= n;
}

CanPlaceFlowersSolution::CanPlaceFlowersSolution() {
  setMetaInfo({.id = 605,
               .title = "Can Place Flowers",
               .url = "https://leetcode.com/problems/can-place-flowers/"});
  registerStrategy(
      {.name = "Greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy"}},
      canPlaceFlowersImpl);
}

bool CanPlaceFlowersSolution::canPlaceFlowers(std::vector<int>& flowerbed,
                                              int n) {
  return getSolution()(flowerbed, n);
}

}  // namespace problem_605
}  // namespace leetcode
