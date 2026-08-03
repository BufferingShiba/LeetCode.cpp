#ifndef LEETCODE_PROBLEMS_CALCULATE_MONEY_IN_LEETCODE_BANK_H_
#define LEETCODE_PROBLEMS_CALCULATE_MONEY_IN_LEETCODE_BANK_H_

#include <functional>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1716 {

using Func = std::function<int(int)>;

class CalculateMoneyInLeetcodeBankSolution
    : public SolutionBase<Func> {
 public:
  CalculateMoneyInLeetcodeBankSolution();

  int totalMoney(int n);
};

}  // namespace problem_1716
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CALCULATE_MONEY_IN_LEETCODE_BANK_H_
