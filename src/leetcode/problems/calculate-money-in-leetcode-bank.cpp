#include "leetcode/problems/calculate-money-in-leetcode-bank.h"

namespace leetcode {
namespace problem_1716 {

namespace {

int totalMoneyImpl(int n) {
  const int weeks = n / 7;
  const int days = n % 7;
  // Complete weeks: week k contributes 7*k + 28.
  // Sum_{k=0}^{weeks-1} (7k + 28) = weeks*28 + 7*weeks*(weeks-1)/2.
  int total = weeks * 28 + 7 * weeks * (weeks - 1) / 2;
  // Remainder days in week `weeks`: (weeks+1) + ... + (weeks+days).
  total += days * weeks + days * (days + 1) / 2;
  return total;
}

}  // namespace

CalculateMoneyInLeetcodeBankSolution::CalculateMoneyInLeetcodeBankSolution() {
  setMetaInfo({.id = 1716,
               .title = "Calculate Money in Leetcode Bank",
               .url = "https://leetcode.com/problems/calculate-money-in-leetcode-bank/"});
  registerStrategy(
      {.name = "MathFormula",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math"}},
      totalMoneyImpl);
}

int CalculateMoneyInLeetcodeBankSolution::totalMoney(int n) {
  return getSolution()(n);
}

}  // namespace problem_1716
}  // namespace leetcode
