#ifndef LEETCODE_PROBLEMS_DISTRIBUTE_ELEMENTS_INTO_TWO_ARRAYS_II_H_
#define LEETCODE_PROBLEMS_DISTRIBUTE_ELEMENTS_INTO_TWO_ARRAYS_II_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3072 {

using Func = std::function<std::vector<int>(std::vector<int>&)>;

class DistributeElementsIntoTwoArraysIiSolution
    : public SolutionBase<Func> {
 public:
  DistributeElementsIntoTwoArraysIiSolution();
  std::vector<int> resultArray(std::vector<int>& nums);
};

}  // namespace problem_3072
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_DISTRIBUTE_ELEMENTS_INTO_TWO_ARRAYS_II_H_
