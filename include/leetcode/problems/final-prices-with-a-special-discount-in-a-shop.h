#ifndef LEETCODE_PROBLEMS_FINAL_PRICES_WITH_A_SPECIAL_DISCOUNT_IN_A_SHOP_H_
#define LEETCODE_PROBLEMS_FINAL_PRICES_WITH_A_SPECIAL_DISCOUNT_IN_A_SHOP_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode::problem_1475 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class FinalPricesWithASpecialDiscountInAShopSolution
    : public SolutionBase<Func> {
 public:
  FinalPricesWithASpecialDiscountInAShopSolution();

  std::vector<int> finalPrices(std::vector<int>& prices);
};

}  // namespace leetcode::problem_1475

#endif  // LEETCODE_PROBLEMS_FINAL_PRICES_WITH_A_SPECIAL_DISCOUNT_IN_A_SHOP_H_
