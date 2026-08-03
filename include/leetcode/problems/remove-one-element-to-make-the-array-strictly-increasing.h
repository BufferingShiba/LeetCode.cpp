#ifndef LEETCODE_PROBLEMS_REMOVE_ONE_ELEMENT_TO_MAKE_THE_ARRAY_STRICTLY_INCREASING_H__
#define LEETCODE_PROBLEMS_REMOVE_ONE_ELEMENT_TO_MAKE_THE_ARRAY_STRICTLY_INCREASING_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1909 {

using Func = std::function<bool(std::vector<int>&)>;

class RemoveOneElementToMakeTheArrayStrictlyIncreasingSolution
    : public SolutionBase<Func> {
 public:
  RemoveOneElementToMakeTheArrayStrictlyIncreasingSolution();

  bool canBeIncreasing(std::vector<int>& nums);
};

}  // namespace problem_1909
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REMOVE_ONE_ELEMENT_TO_MAKE_THE_ARRAY_STRICTLY_INCREASING_H__
