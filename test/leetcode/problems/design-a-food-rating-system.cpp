#include <gtest/gtest.h>

#include "leetcode/problems/design-a-food-rating-system.h"

using namespace leetcode::problem_2353;

class DesignAFoodRatingSystemTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

TEST_P(DesignAFoodRatingSystemTest, Example1) {
  std::vector<std::string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
  std::vector<std::string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
  std::vector<int> ratings = {9, 12, 8, 15, 14, 7};

  FoodRatings fr(foods, cuisines, ratings);
  EXPECT_EQ(fr.highestRated("korean"), "kimchi");
  EXPECT_EQ(fr.highestRated("japanese"), "ramen");
  fr.changeRating("sushi", 16);
  EXPECT_EQ(fr.highestRated("japanese"), "sushi");
  fr.changeRating("ramen", 16);
  EXPECT_EQ(fr.highestRated("japanese"), "ramen");
}

TEST_P(DesignAFoodRatingSystemTest, SelfAuthoredSingleFood) {
  std::vector<std::string> foods = {"pizza"};
  std::vector<std::string> cuisines = {"italian"};
  std::vector<int> ratings = {10};

  FoodRatings fr(foods, cuisines, ratings);
  EXPECT_EQ(fr.highestRated("italian"), "pizza");
  fr.changeRating("pizza", 5);
  EXPECT_EQ(fr.highestRated("italian"), "pizza");
}

TEST_P(DesignAFoodRatingSystemTest, SelfAuthoredTieBreakLexicographical) {
  std::vector<std::string> foods = {"burger", "pizza", "sushi"};
  std::vector<std::string> cuisines = {"american", "italian", "japanese"};
  std::vector<int> ratings = {10, 10, 10};

  FoodRatings fr(foods, cuisines, ratings);
  // All same rating, but different cuisines, so no tie across cuisines.
  EXPECT_EQ(fr.highestRated("american"), "burger");
  EXPECT_EQ(fr.highestRated("italian"), "pizza");
  EXPECT_EQ(fr.highestRated("japanese"), "sushi");
}

INSTANTIATE_TEST_SUITE_P(All, DesignAFoodRatingSystemTest, ::testing::Values(0));
