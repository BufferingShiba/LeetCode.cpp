#ifndef LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_ITEMS_FROM_SALE_I_H__
#define LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_ITEMS_FROM_SALE_I_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode::problem_3946 {

using Func = std::function<int(std::vector<std::vector<int>>&, int)>;

class MaximumNumberOfItemsFromSaleISolution : public SolutionBase<Func> {
 public:
  MaximumNumberOfItemsFromSaleISolution();

  int maximumSaleItems(std::vector<std::vector<int>>& items, int budget);
};

}  // namespace leetcode::problem_3946

#endif  // LEETCODE_PROBLEMS_MAXIMUM_NUMBER_OF_ITEMS_FROM_SALE_I_H__
