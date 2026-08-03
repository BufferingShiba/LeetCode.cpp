#pragma once
#include "leetcode/core.h"

namespace leetcode::problem_1333 {

using Func =
    std::function<std::vector<int>(std::vector<std::vector<int>>&, int, int, int)>;

class FilterRestaurantsByVeganFriendlyPriceAndDistanceSolution
    : public SolutionBase<Func> {
 public:
  FilterRestaurantsByVeganFriendlyPriceAndDistanceSolution();

  std::vector<int> filterRestaurants(std::vector<std::vector<int>>& restaurants,
                                     int veganFriendly, int maxPrice,
                                     int maxDistance);
};

}  // namespace leetcode::problem_1333
