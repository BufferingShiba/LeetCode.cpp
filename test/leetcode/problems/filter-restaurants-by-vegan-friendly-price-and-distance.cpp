#include <gtest/gtest.h>

#include "leetcode/problems/filter-restaurants-by-vegan-friendly-price-and-distance.h"

namespace leetcode::problem_1333 {

class FilterRestaurantsByVeganFriendlyPriceAndDistanceTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FilterRestaurantsByVeganFriendlyPriceAndDistanceSolution solution_;
};

TEST_P(FilterRestaurantsByVeganFriendlyPriceAndDistanceTest, Example1) {
  std::vector<std::vector<int>> restaurants = {
      {1, 4, 1, 40, 10},
      {2, 8, 0, 50, 5},
      {3, 8, 1, 30, 4},
      {4, 10, 0, 10, 3},
      {5, 1, 1, 15, 1}};
  int veganFriendly = 1, maxPrice = 50, maxDistance = 10;
  auto expected = std::vector<int>{3, 1, 5};
  EXPECT_EQ(solution_.filterRestaurants(restaurants, veganFriendly, maxPrice,
                                        maxDistance),
            expected);
}

TEST_P(FilterRestaurantsByVeganFriendlyPriceAndDistanceTest, Example2) {
  std::vector<std::vector<int>> restaurants = {
      {1, 4, 1, 40, 10},
      {2, 8, 0, 50, 5},
      {3, 8, 1, 30, 4},
      {4, 10, 0, 10, 3},
      {5, 1, 1, 15, 1}};
  int veganFriendly = 0, maxPrice = 50, maxDistance = 10;
  auto expected = std::vector<int>{4, 3, 2, 1, 5};
  EXPECT_EQ(solution_.filterRestaurants(restaurants, veganFriendly, maxPrice,
                                        maxDistance),
            expected);
}

TEST_P(FilterRestaurantsByVeganFriendlyPriceAndDistanceTest, Example3) {
  std::vector<std::vector<int>> restaurants = {
      {1, 4, 1, 40, 10},
      {2, 8, 0, 50, 5},
      {3, 8, 1, 30, 4},
      {4, 10, 0, 10, 3},
      {5, 1, 1, 15, 1}};
  int veganFriendly = 0, maxPrice = 30, maxDistance = 3;
  auto expected = std::vector<int>{4, 5};
  EXPECT_EQ(solution_.filterRestaurants(restaurants, veganFriendly, maxPrice,
                                        maxDistance),
            expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, FilterRestaurantsByVeganFriendlyPriceAndDistanceTest,
    ::testing::ValuesIn(
        FilterRestaurantsByVeganFriendlyPriceAndDistanceSolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_1333
