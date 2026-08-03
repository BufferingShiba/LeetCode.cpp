#include "leetcode/problems/calculate-amount-paid-in-taxes.h"

#include <vector>

namespace leetcode::problem_2303 {

namespace {

double calculateTaxImpl(std::vector<std::vector<int>>& brackets,
                        int income) {
  double total = 0.0;
  int prev_upper = 0;
  for (const auto& bracket : brackets) {
    int upper = bracket[0];
    int percent = bracket[1];
    int taxable = std::min(income, upper) - prev_upper;
    if (taxable <= 0) break;
    total += static_cast<double>(taxable) * static_cast<double>(percent) / 100.0;
    prev_upper = upper;
  }
  return total;
}

}  // namespace

CalculateAmountPaidInTaxesSolution::CalculateAmountPaidInTaxesSolution() {
  setMetaInfo({.id = 2303,
               .title = "Calculate Amount Paid in Taxes",
               .url = "https://leetcode.com/problems/calculate-amount-paid-in-taxes/"});
  registerStrategy(
      {.name = "IterativeBracketSimulation",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Simulation"}},
      calculateTaxImpl);
}

double CalculateAmountPaidInTaxesSolution::calculateTax(
    std::vector<std::vector<int>>& brackets, int income) {
  return getSolution()(brackets, income);
}

}  // namespace leetcode::problem_2303
