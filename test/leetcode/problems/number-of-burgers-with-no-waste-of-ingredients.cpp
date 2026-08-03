#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/number-of-burgers-with-no-waste-of-ingredients.h"

namespace leetcode {
namespace problem_1276 {

class NumberOfBurgersWithNoWasteOfIngredientsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  NumberOfBurgersWithNoWasteOfIngredientsSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(NumberOfBurgersWithNoWasteOfIngredientsTest, Example1) {
  std::vector<int> result = solution.numOfBurgers(16, 7);
  EXPECT_EQ(result, std::vector<int>({1, 6}));
}

TEST_P(NumberOfBurgersWithNoWasteOfIngredientsTest, Example2) {
  std::vector<int> result = solution.numOfBurgers(17, 4);
  EXPECT_TRUE(result.empty());
}

TEST_P(NumberOfBurgersWithNoWasteOfIngredientsTest, Example3) {
  std::vector<int> result = solution.numOfBurgers(4, 17);
  EXPECT_TRUE(result.empty());
}

TEST_P(NumberOfBurgersWithNoWasteOfIngredientsTest, SelfAuthoredZeroSlices) {
  std::vector<int> result = solution.numOfBurgers(0, 0);
  EXPECT_EQ(result, std::vector<int>({0, 0}));
}

TEST_P(NumberOfBurgersWithNoWasteOfIngredientsTest, SelfAuthoredOnlyTomatoOdd) {
  std::vector<int> result = solution.numOfBurgers(4, 1);
  EXPECT_EQ(result, std::vector<int>({1, 0}));
}

TEST_P(NumberOfBurgersWithNoWasteOfIngredientsTest, SelfAuthoredOnlyCheeseNoTomato) {
  std::vector<int> result = solution.numOfBurgers(0, 1);
  EXPECT_TRUE(result.empty());
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfBurgersWithNoWasteOfIngredientsTestInstance,
    NumberOfBurgersWithNoWasteOfIngredientsTest,
    ::testing::ValuesIn(
        NumberOfBurgersWithNoWasteOfIngredientsSolution().getStrategyNames()));

}  // namespace problem_1276
}  // namespace leetcode
