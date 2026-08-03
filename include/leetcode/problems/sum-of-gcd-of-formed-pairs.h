#ifndef LEETCODE_PROBLEM_3867_H_
#define LEETCODE_PROBLEM_3867_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3867 {

using Func = std::function<long long(std::vector<int>&)>;

class SumOfGcdOfFormedPairsSolution : public SolutionBase<Func> {
 public:
  SumOfGcdOfFormedPairsSolution();

  long long gcdSum(std::vector<int>& nums);
};

}  // namespace problem_3867
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_3867_H_
