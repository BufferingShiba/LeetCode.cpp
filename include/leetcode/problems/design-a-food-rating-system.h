#ifndef LEETCODE_PROBLEM_2353_H
#define LEETCODE_PROBLEM_2353_H

#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <utility>

namespace leetcode::problem_2353 {

class FoodRatings {
 public:
  FoodRatings(std::vector<std::string>& foods,
              std::vector<std::string>& cuisines,
              std::vector<int>& ratings);

  void changeRating(std::string food, int newRating);

  std::string highestRated(std::string cuisine);

 private:
  // Compare: higher rating first; on tie, lexicographically smaller food name first.
  struct RatingCompare {
    bool operator()(const std::pair<int, std::string>& a,
                    const std::pair<int, std::string>& b) const {
      if (a.first != b.first) return a.first > b.first;
      return a.second < b.second;
    }
  };

  // food -> {cuisine, rating}
  std::unordered_map<std::string, std::pair<std::string, int>> foodMap_;

  // cuisine -> ordered set of {rating, food} sorted by RatingCompare
  std::unordered_map<std::string, std::set<std::pair<int, std::string>, RatingCompare>> cuisineMap_;
};

}  // namespace leetcode::problem_2353

#endif  // LEETCODE_PROBLEM_2353_H
