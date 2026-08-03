#include "leetcode/problems/find-all-possible-recipes-from-given-supplies.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode::problem_2115 {

class FindAllPossibleRecipesFromGivenSuppliesTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  std::vector<std::string> run(
      std::vector<std::string> recipes,
      std::vector<std::vector<std::string>> ingredients,
      std::vector<std::string> supplies) {
    return solution_.findAllRecipes(recipes, ingredients, supplies);
  }

  FindAllPossibleRecipesFromGivenSuppliesSolution solution_;
};

TEST_P(FindAllPossibleRecipesFromGivenSuppliesTest, Example1) {
  std::vector<std::string> recipes = {"bread"};
  std::vector<std::vector<std::string>> ingredients = {{"yeast", "flour"}};
  std::vector<std::string> supplies = {"yeast", "flour", "corn"};
  EXPECT_EQ(run(recipes, ingredients, supplies),
            std::vector<std::string>({"bread"}));
}

TEST_P(FindAllPossibleRecipesFromGivenSuppliesTest, Example2) {
  std::vector<std::string> recipes = {"bread", "sandwich"};
  std::vector<std::vector<std::string>> ingredients = {
      {"yeast", "flour"}, {"bread", "meat"}};
  std::vector<std::string> supplies = {"yeast", "flour", "meat"};
  auto out = run(recipes, ingredients, supplies);
  std::vector<std::string> expected = {"bread", "sandwich"};
  EXPECT_EQ(std::set<std::string>(out.begin(), out.end()),
            std::set<std::string>(expected.begin(), expected.end()));
}

TEST_P(FindAllPossibleRecipesFromGivenSuppliesTest, Example3) {
  std::vector<std::string> recipes = {"bread", "sandwich", "burger"};
  std::vector<std::vector<std::string>> ingredients = {
      {"yeast", "flour"}, {"bread", "meat"}, {"sandwich", "meat", "bread"}};
  std::vector<std::string> supplies = {"yeast", "flour", "meat"};
  auto out = run(recipes, ingredients, supplies);
  std::vector<std::string> expected = {"bread", "sandwich", "burger"};
  EXPECT_EQ(std::set<std::string>(out.begin(), out.end()),
            std::set<std::string>(expected.begin(), expected.end()));
}

TEST_P(FindAllPossibleRecipesFromGivenSuppliesTest, SelfAuthoredCyclicDependencyNoCreation) {
  std::vector<std::string> recipes = {"a", "b"};
  std::vector<std::vector<std::string>> ingredients = {{"b"}, {"a"}};
  std::vector<std::string> supplies = {};
  EXPECT_TRUE(run(recipes, ingredients, supplies).empty());
}

INSTANTIATE_TEST_SUITE_P(
    FindAllPossibleRecipesFromGivenSuppliesTestSuite,
    FindAllPossibleRecipesFromGivenSuppliesTest,
    testing::ValuesIn(
        FindAllPossibleRecipesFromGivenSuppliesSolution().getStrategyNames()));

}  // namespace leetcode::problem_2115
