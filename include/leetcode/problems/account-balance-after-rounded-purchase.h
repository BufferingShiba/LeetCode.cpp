#ifndef LEETCODE_PROBLEMS_ACCOUNT_BALANCE_AFTER_ROUNDED_PURCHASE_H__
#define LEETCODE_PROBLEMS_ACCOUNT_BALANCE_AFTER_ROUNDED_PURCHASE_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2806 {

using Func = std::function<int(int)>;

class AccountBalanceAfterRoundedPurchaseSolution : public SolutionBase<Func> {
 public:
  AccountBalanceAfterRoundedPurchaseSolution();

  int accountBalanceAfterPurchase(int purchaseAmount);
};

}  // namespace problem_2806
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_ACCOUNT_BALANCE_AFTER_ROUNDED_PURCHASE_H__
