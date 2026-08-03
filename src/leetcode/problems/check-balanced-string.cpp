#include "leetcode/problems/check-balanced-string.h"

namespace leetcode {
namespace problem_3340 {

namespace {

bool isBalancedImpl(std::string num) {
  int evenSum = 0;
  int oddSum = 0;
  for (std::size_t i = 0; i < num.size(); ++i) {
    int digit = num[i] - '0';
    if (i % 2 == 0) {
      evenSum += digit;
    } else {
      oddSum += digit;
    }
  }
  return evenSum == oddSum;
}

}  // namespace

CheckBalancedStringSolution::CheckBalancedStringSolution() {
  setMetaInfo({.id = 3340,
               .title = "Check Balanced String",
               .url = "https://leetcode.com/problems/check-balanced-string/"});
  registerStrategy({.name = "single-pass",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"String", "Simulation"}},
                   isBalancedImpl);
}

bool CheckBalancedStringSolution::isBalanced(std::string num) {
  return getSolution()(num);
}

}  // namespace problem_3340
}  // namespace leetcode
