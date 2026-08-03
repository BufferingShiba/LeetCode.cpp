#ifndef LEETCODE_PROBLEMS_RICHEST_CUSTOMER_WEALTH_H__
#define LEETCODE_PROBLEMS_RICHEST_CUSTOMER_WEALTH_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1672 {

using Func = std::function<int(std::vector<std::vector<int>>&)>;

class RichestCustomerWealthSolution : public SolutionBase<Func> {
 public:
  RichestCustomerWealthSolution();

  int maximumWealth(std::vector<std::vector<int>>& accounts);
};

}  // namespace problem_1672
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_RICHEST_CUSTOMER_WEALTH_H__
