#ifndef LEETCODE_PROBLEMS_MAXIMUM_XOR_WITH_AN_ELEMENT_FROM_ARRAY_H__
#define LEETCODE_PROBLEMS_MAXIMUM_XOR_WITH_AN_ELEMENT_FROM_ARRAY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1707 {

using Func = std::function<std::vector<int>(std::vector<int>&,
                                             std::vector<std::vector<int>>&)>;

class MaximumXorWithAnElementFromArraySolution : public SolutionBase<Func> {
 public:
  MaximumXorWithAnElementFromArraySolution();

  std::vector<int> maximizeXor(std::vector<int>& nums,
                               std::vector<std::vector<int>>& queries);
};

}  // namespace problem_1707
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAXIMUM_XOR_WITH_AN_ELEMENT_FROM_ARRAY_H__
