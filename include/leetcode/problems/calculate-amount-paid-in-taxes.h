#ifndef LEETCODE_PROBLEMS_CALCULATE_AMOUNT_PAID_IN_TAXES_H
#define LEETCODE_PROBLEMS_CALCULATE_AMOUNT_PAID_IN_TAXES_H

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode::problem_2303 {

using Func = std::function<double(std::vector<std::vector<int>>&, int)>;

class CalculateAmountPaidInTaxesSolution
    : public SolutionBase<Func> {
 public:
  CalculateAmountPaidInTaxesSolution();

  double calculateTax(std::vector<std::vector<int>>& brackets,
                      int income);
};

}  // namespace leetcode::problem_2303

#endif  // LEETCODE_PROBLEMS_CALCULATE_AMOUNT_PAID_IN_TAXES_H
