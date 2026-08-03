#ifndef LEETCODE_PROBLEMS_NUMBER_OF_BURGERS_WITH_NO_WASTE_OF_INGREDIENTS_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_BURGERS_WITH_NO_WASTE_OF_INGREDIENTS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1276 {

using Func = std::function<std::vector<int>(int, int)>;

class NumberOfBurgersWithNoWasteOfIngredientsSolution
    : public SolutionBase<Func> {
 public:
  NumberOfBurgersWithNoWasteOfIngredientsSolution();

  std::vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices);
};

}  // namespace problem_1276
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_BURGERS_WITH_NO_WASTE_OF_INGREDIENTS_H__
