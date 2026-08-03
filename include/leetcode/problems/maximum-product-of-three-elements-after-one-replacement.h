#ifndef LEETCODE_PROBLEM_3732_H
#define LEETCODE_PROBLEM_3732_H

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3732 {

using Func = std::function<long long(std::vector<int>&)>;

class MaximumProductOfThreeElementsAfterOneReplacementSolution : public SolutionBase<Func> {
 public:
  MaximumProductOfThreeElementsAfterOneReplacementSolution();
  long long maxProduct(std::vector<int>& nums);
};

}  // namespace problem_3732
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_3732_H
