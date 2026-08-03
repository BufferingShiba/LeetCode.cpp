#ifndef LEETCODE_PROBLEMS_MAXIMUM_VALUE_OF_AN_ORDERED_TRIPLET_II_H_
#define LEETCODE_PROBLEMS_MAXIMUM_VALUE_OF_AN_ORDERED_TRIPLET_II_H_

#include <vector>
#include <functional>
#include "leetcode/core.h"

namespace leetcode {
namespace problem_2874 {

using Func = std::function<long long(std::vector<int>&)>;

class MaximumValueOfAnOrderedTripletIiSolution : public SolutionBase<Func> {
 public:
  MaximumValueOfAnOrderedTripletIiSolution();

  long long maximumTripletValue(std::vector<int>& nums);
};

}  // namespace problem_2874
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_VALUE_OF_AN_ORDERED_TRIPLET_II_H_
