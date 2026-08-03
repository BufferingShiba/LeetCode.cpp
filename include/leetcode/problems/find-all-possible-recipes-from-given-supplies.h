#ifndef LEETCODE_PROBLEMS_FIND_ALL_POSSIBLE_RECIPES_FROM_GIVEN_SUPPLIES_H__
#define LEETCODE_PROBLEMS_FIND_ALL_POSSIBLE_RECIPES_FROM_GIVEN_SUPPLIES_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_2115 {

using Func = std::function<std::vector<std::string>(
    std::vector<std::string>&, std::vector<std::vector<std::string>>&,
    std::vector<std::string>&)>;

class FindAllPossibleRecipesFromGivenSuppliesSolution
    : public SolutionBase<Func> {
 public:
  FindAllPossibleRecipesFromGivenSuppliesSolution();

  std::vector<std::string> findAllRecipes(
      std::vector<std::string>& recipes,
      std::vector<std::vector<std::string>>& ingredients,
      std::vector<std::string>& supplies);
};

}  // namespace leetcode::problem_2115

#endif  // LEETCODE_PROBLEMS_FIND_ALL_POSSIBLE_RECIPES_FROM_GIVEN_SUPPLIES_H__
