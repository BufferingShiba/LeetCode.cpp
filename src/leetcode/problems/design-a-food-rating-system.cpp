#include "leetcode/problems/design-a-food-rating-system.h"

namespace leetcode::problem_2353 {

FoodRatings::FoodRatings(std::vector<std::string>& foods,
                         std::vector<std::string>& cuisines,
                         std::vector<int>& ratings) {
  int n = static_cast<int>(foods.size());
  for (int i = 0; i < n; ++i) {
    const std::string& food = foods[i];
    const std::string& cuisine = cuisines[i];
    int rating = ratings[i];
    foodMap_[food] = {cuisine, rating};
    cuisineMap_[cuisine].insert({rating, food});
  }
}

void FoodRatings::changeRating(std::string food, int newRating) {
  auto it = foodMap_.find(food);
  const std::string& cuisine = it->second.first;
  int oldRating = it->second.second;

  // Remove old entry from the cuisine set
  auto& cset = cuisineMap_[cuisine];
  cset.erase({oldRating, food});

  // Update food map
  it->second.second = newRating;

  // Insert new entry
  cset.insert({newRating, food});
}

std::string FoodRatings::highestRated(std::string cuisine) {
  const auto& cset = cuisineMap_[cuisine];
  // The set is never empty for a valid cuisine (constraint guarantees at least one food).
  return cset.begin()->second;
}

}  // namespace leetcode::problem_2353
