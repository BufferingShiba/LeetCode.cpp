#ifndef LEETCODE_PROBLEMS_NUMBER_OF_UNEQUAL_TRIPLETS_IN_ARRAY_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_UNEQUAL_TRIPLETS_IN_ARRAY_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2475 {

using Func = std::function<int(std::vector<int>&)>;

class NumberOfUnequalTripletsInArraySolution
    : public SolutionBase<Func> {
 public:
  NumberOfUnequalTripletsInArraySolution();

  int unequalTriplets(std::vector<int>& nums);
};

}  // namespace problem_2475
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_UNEQUAL_TRIPLETS_IN_ARRAY_H__
