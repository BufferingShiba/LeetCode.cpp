#ifndef LEETCODE_PROBLEMS_K_HIGHEST_RANKED_ITEMS_WITHIN_A_PRICE_RANGE_H__
#define LEETCODE_PROBLEMS_K_HIGHEST_RANKED_ITEMS_WITHIN_A_PRICE_RANGE_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2146 {

using Func = std::function<std::vector<std::vector<int>>(
    std::vector<std::vector<int>>&, std::vector<int>&, std::vector<int>&,
    int)>;

class KHighestRankedItemsWithinAPriceRangeSolution
    : public SolutionBase<Func> {
 public:
  KHighestRankedItemsWithinAPriceRangeSolution();

  std::vector<std::vector<int>> highestRankedKItems(
      std::vector<std::vector<int>>& grid, std::vector<int>& pricing,
      std::vector<int>& start, int k);
};

}  // namespace problem_2146
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_K_HIGHEST_RANKED_ITEMS_WITHIN_A_PRICE_RANGE_H__
