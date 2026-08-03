#ifndef LEETCODE_PROBLEMS_MAXIMUM_VALUE_OF_AN_ORDERED_TRIPLET_I_H_
#define LEETCODE_PROBLEMS_MAXIMUM_VALUE_OF_AN_ORDERED_TRIPLET_I_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2873 {

using Func = std::function<long long(std::vector<int>&)>;

class MaximumValueOfAnOrderedTripletISolution : public SolutionBase<Func> {
 public:
  MaximumValueOfAnOrderedTripletISolution();

  long long maximumTripletValue(std::vector<int>& nums);
};

}  // namespace problem_2873
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_VALUE_OF_AN_ORDERED_TRIPLET_I_H_
