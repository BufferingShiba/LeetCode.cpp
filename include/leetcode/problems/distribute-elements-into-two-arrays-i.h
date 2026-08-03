#ifndef LEETCODE_PROBLEMS_3069_DISTRIBUTE_ELEMENTS_INTO_TWO_ARRAYS_I_H_
#define LEETCODE_PROBLEMS_3069_DISTRIBUTE_ELEMENTS_INTO_TWO_ARRAYS_I_H_

#include "leetcode/core.h"
#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3069 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class DistributeElementsIntoTwoArraysISolution
    : public SolutionBase<Func> {
 public:
  std::vector<int> resultArray(std::vector<int>& nums);
  DistributeElementsIntoTwoArraysISolution();
};

}  // namespace problem_3069
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_3069_DISTRIBUTE_ELEMENTS_INTO_TWO_ARRAYS_I_H_
