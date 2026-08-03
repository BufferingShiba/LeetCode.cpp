#ifndef LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_COINS_FOR_FRUITS_H__
#define LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_COINS_FOR_FRUITS_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2944 {

using Func = std::function<int(std::vector<int>&)>;

class MinimumNumberOfCoinsForFruitsSolution : public SolutionBase<Func> {
 public:
  MinimumNumberOfCoinsForFruitsSolution();

  int minimumCoins(std::vector<int>& prices);
};

}  // namespace problem_2944
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_NUMBER_OF_COINS_FOR_FRUITS_H__
