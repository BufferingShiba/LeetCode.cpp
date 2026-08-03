#include "leetcode/problems/account-balance-after-rounded-purchase.h"

namespace leetcode {
namespace problem_2806 {

namespace {

int accountBalanceAfterPurchaseImpl(int purchaseAmount) {
  int rounded = (purchaseAmount + 5) / 10 * 10;
  return 100 - rounded;
}

}  // namespace

AccountBalanceAfterRoundedPurchaseSolution::AccountBalanceAfterRoundedPurchaseSolution() {
  setMetaInfo({.id = 2806,
               .title = "Account Balance After Rounded Purchase",
               .url = "https://leetcode.com/problems/account-balance-after-rounded-purchase/"});

  registerStrategy(
      {.name = "Math",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math"},
       .notes = "Round purchaseAmount to nearest multiple of 10 (with 5 up), then subtract from 100."},
      accountBalanceAfterPurchaseImpl);
}

int AccountBalanceAfterRoundedPurchaseSolution::accountBalanceAfterPurchase(int purchaseAmount) {
  return getSolution()(purchaseAmount);
}

}  // namespace problem_2806
}  // namespace leetcode
