#ifndef LEETCODE_PROBLEMS_SPLIT_ARRAY_BY_PRIME_INDICES_H
#define LEETCODE_PROBLEMS_SPLIT_ARRAY_BY_PRIME_INDICES_H

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3618 {

using Func = std::function<long long(std::vector<int>&)>;

class SplitArrayByPrimeIndicesSolution : public SolutionBase<Func> {
 public:
  SplitArrayByPrimeIndicesSolution();

  long long splitArray(std::vector<int>& nums);
};

}  // namespace problem_3618
}  // namespace leetcode

#endif
