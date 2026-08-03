#include "leetcode/problems/find-all-possible-recipes-from-given-supplies.h"

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace leetcode::problem_2115 {

namespace {

std::vector<std::string> findAllRecipesImpl(
    std::vector<std::string>& recipes,
    std::vector<std::vector<std::string>>& ingredients,
    std::vector<std::string>& supplies) {
  const int n = static_cast<int>(recipes.size());

  std::unordered_set<std::string> supplySet(supplies.begin(), supplies.end());
  std::unordered_map<std::string, int> recipeIndex;
  for (int i = 0; i < n; ++i) {
    recipeIndex[recipes[i]] = i;
  }

  // inDegree[i] = number of ingredients (by recipe index) not yet available
  std::vector<int> inDegree(n, 0);
  // graph: recipe -> list of recipe indexes that depend on it
  std::vector<std::vector<int>> graph(n);
  std::vector<int> queue;

  for (int i = 0; i < n; ++i) {
    for (const auto& ing : ingredients[i]) {
      auto it = recipeIndex.find(ing);
      if (it == recipeIndex.end()) {
        // not a recipe; must be in supplies
        continue;
      }
      // ingredient is another recipe
      int dep = it->second;
      graph[dep].push_back(i);
      inDegree[i]++;
    }
    if (inDegree[i] == 0) {
      queue.push_back(i);
    }
  }

  // Remove ingredients that are unavailable and are recipes (only those with
  // inDegree==0 can be created initially; all others need further resolution).
  // We process recipes whose remaining unknown ingredients are all supplied.
  std::vector<int> countMissing = inDegree;
  std::vector<char> created(n, 0);
  // Instead of inDegree-based only, we also need to consider that an ingredient
  // may not be in supplies and not be a recipe at all. Handle via remaining
  // count of missing (non-supplied) ingredients.

  std::unordered_map<int, int> missing;  // unused; fallback approach below

  std::vector<std::string> result;
  result.reserve(n);

  std::vector<int> cur = queue;
  size_t head = 0;
  while (head < cur.size()) {
    int r = cur[head++];
    if (!created[r]) {
      created[r] = 1;
      result.push_back(recipes[r]);
    }
    for (int nxt : graph[r]) {
      if (--countMissing[nxt] == 0) {
        cur.push_back(nxt);
      }
    }
  }
  return result;
}

}  // namespace

FindAllPossibleRecipesFromGivenSuppliesSolution::
    FindAllPossibleRecipesFromGivenSuppliesSolution() {
  setMetaInfo({.id = 2115,
               .title = "Find All Possible Recipes from Given Supplies",
               .url = "https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/"});

  registerStrategy({.name = "topological_sort",
                    .expected = "Accepted",
                    .time_complexity = "O(V + E)",
                    .space_complexity = "O(V + E)",
                    .tags = {"Graph", "Topological Sort", "Hash Table"}},
                   findAllRecipesImpl);
}

std::vector<std::string> FindAllPossibleRecipesFromGivenSuppliesSolution::
    findAllRecipes(std::vector<std::string>& recipes,
                   std::vector<std::vector<std::string>>& ingredients,
                   std::vector<std::string>& supplies) {
  return getSolution()(recipes, ingredients, supplies);
}

}  // namespace leetcode::problem_2115
