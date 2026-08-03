#include "leetcode/problems/fruit-into-baskets.h"

#include <unordered_map>

namespace leetcode {
namespace problem_904 {

namespace {

int totalFruitImpl(std::vector<int>& fruits) {
  std::unordered_map<int, int> count;
  int left = 0;
  int best = 0;
  for (int right = 0; right < static_cast<int>(fruits.size()); ++right) {
    ++count[fruits[right]];
    while (static_cast<int>(count.size()) > 2) {
      if (--count[fruits[left]] == 0) {
        count.erase(fruits[left]);
      }
      ++left;
    }
    best = std::max(best, right - left + 1);
  }
  return best;
}

}  // namespace

FruitIntoBasketsSolution::FruitIntoBasketsSolution() {
  setMetaInfo({.id = 904,
               .title = "Fruit Into Baskets",
               .url = "https://leetcode.com/problems/fruit-into-baskets/"});
  registerStrategy(
      {"sliding-window", "Accepted", "O(n)", "O(n)",
       {"Array", "Hash Table", "Sliding Window"},
       "Sliding window keeping at most 2 distinct fruit types."},
      totalFruitImpl);
}

int FruitIntoBasketsSolution::totalFruit(std::vector<int>& fruits) {
  return getSolution()(fruits);
}

}  // namespace problem_904
}  // namespace leetcode
