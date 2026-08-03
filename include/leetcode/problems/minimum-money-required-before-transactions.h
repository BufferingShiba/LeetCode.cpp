#ifndef LEETCODE_PROBLEMS_MINIMUM_MONEY_REQUIRED_BEFORE_TRANSACTIONS_H_
#define LEETCODE_PROBLEMS_MINIMUM_MONEY_REQUIRED_BEFORE_TRANSACTIONS_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2412 {

using Func = std::function<long long(std::vector<std::vector<int>>&)>;

class MinimumMoneyRequiredBeforeTransactionsSolution : public SolutionBase<Func> {
 public:
  MinimumMoneyRequiredBeforeTransactionsSolution();

  long long minimumMoney(std::vector<std::vector<int>>& transactions);
};

}  // namespace problem_2412
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MINIMUM_MONEY_REQUIRED_BEFORE_TRANSACTIONS_H_