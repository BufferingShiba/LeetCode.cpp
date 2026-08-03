#ifndef LEETCODE_PROBLEMS_MAXIMUM_PRIME_DIFFERENCE_H__
#define LEETCODE_PROBLEMS_MAXIMUM_PRIME_DIFFERENCE_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3115 {

using Func = std::function<int(std::vector<int>&)>;

class MaximumPrimeDifferenceSolution : public SolutionBase<Func> {
 public:
  MaximumPrimeDifferenceSolution();

  int maximumPrimeDifference(std::vector<int>& nums) {
    return getSolution()(nums);
  }
};

}  // namespace problem_3115
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_PRIME_DIFFERENCE_H__
