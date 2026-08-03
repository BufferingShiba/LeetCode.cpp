#ifndef LEETCODE_PROBLEMS_FREQUENCY_BALANCE_SUBARRAY_H_
#define LEETCODE_PROBLEMS_FREQUENCY_BALANCE_SUBARRAY_H_

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3960 {

using Func = std::function<int(std::vector<int>&)>;

class FrequencyBalanceSubarraySolution : public SolutionBase<Func> {
 public:
  FrequencyBalanceSubarraySolution();

  int getLength(std::vector<int>& nums);
};

}  // namespace problem_3960
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FREQUENCY_BALANCE_SUBARRAY_H_
