#include <vector>

#include "leetcode/problems/number-of-burgers-with-no-waste-of-ingredients.h"

namespace leetcode {
namespace problem_1276 {

namespace {

std::vector<int> numOfBurgersImpl(int tomatoSlices, int cheeseSlices) {
  // Let x = jumbo, y = small.
  // x + y = cheeseSlices
  // 4x + 2y = tomatoSlices
  // -> x = (tomatoSlices - 2 * cheeseSlices) / 2
  // -> y = cheeseSlices - x
  const int diff = tomatoSlices - 2 * cheeseSlices;
  if (diff < 0 || diff % 2 != 0) {
    return {};
  }
  const int jumbo = diff / 2;
  const int small = cheeseSlices - jumbo;
  if (jumbo < 0 || small < 0) {
    return {};
  }
  return {jumbo, small};
}

}  // namespace

NumberOfBurgersWithNoWasteOfIngredientsSolution::NumberOfBurgersWithNoWasteOfIngredientsSolution() {
  setMetaInfo({.id = 1276,
               .title = "Number of Burgers with No Waste of Ingredients",
               .url = "https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/"});

  registerStrategy(
      {.name = "linear-system",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math"}},
      numOfBurgersImpl);
}

std::vector<int> NumberOfBurgersWithNoWasteOfIngredientsSolution::numOfBurgers(
    int tomatoSlices, int cheeseSlices) {
  return getSolution()(tomatoSlices, cheeseSlices);
}

}  // namespace problem_1276
}  // namespace leetcode
