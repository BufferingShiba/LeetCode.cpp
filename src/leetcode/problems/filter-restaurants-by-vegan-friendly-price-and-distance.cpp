#include "leetcode/problems/filter-restaurants-by-vegan-friendly-price-and-distance.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_1333 {

static std::vector<int> filterRestaurantsImpl(
    std::vector<std::vector<int>>& restaurants, int veganFriendly,
    int maxPrice, int maxDistance) {
  std::vector<std::pair<int, int>> filtered;  // (rating, id)
  for (const auto& r : restaurants) {
    if (veganFriendly == 1 && r[2] == 0) continue;
    if (r[3] > maxPrice) continue;
    if (r[4] > maxDistance) continue;
    filtered.emplace_back(r[1], r[0]);
  }
  std::sort(filtered.begin(), filtered.end(),
            [](const auto& a, const auto& b) {
              if (a.first != b.first) return a.first > b.first;
              return a.second > b.second;
            });
  std::vector<int> result;
  result.reserve(filtered.size());
  for (const auto& p : filtered) {
    result.push_back(p.second);
  }
  return result;
}

FilterRestaurantsByVeganFriendlyPriceAndDistanceSolution::
    FilterRestaurantsByVeganFriendlyPriceAndDistanceSolution() {
  setMetaInfo(
      {.id = 1333,
       .title = "Filter Restaurants by Vegan-Friendly, Price and Distance",
       .url =
           "https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/"});
  registerStrategy(
      {.name = "FilterAndSort",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Sorting"}},
      filterRestaurantsImpl);
}

std::vector<int>
FilterRestaurantsByVeganFriendlyPriceAndDistanceSolution::filterRestaurants(
    std::vector<std::vector<int>>& restaurants, int veganFriendly,
    int maxPrice, int maxDistance) {
  return getSolution()(restaurants, veganFriendly, maxPrice, maxDistance);
}

}  // namespace leetcode::problem_1333
