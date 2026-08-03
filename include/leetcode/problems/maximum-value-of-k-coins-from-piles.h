#ifndef LEETCODE_PROBLEMS_MAXIMUM_VALUE_OF_K_COINS_FROM_PILES_H_
#define LEETCODE_PROBLEMS_MAXIMUM_VALUE_OF_K_COINS_FROM_PILES_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2218 {

using Func = std::function<int(std::vector<std::vector<int>>&, int)>;

class MaximumValueOfKCoinsFromPilesSolution : public SolutionBase<Func> {
 public:
  MaximumValueOfKCoinsFromPilesSolution();
  int maxValueOfCoins(std::vector<std::vector<int>>& piles, int k);
};

}  // namespace problem_2218
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_VALUE_OF_K_COINS_FROM_PILES_H_
