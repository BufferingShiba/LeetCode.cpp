#ifndef LEETCODE_PROBLEMS_SINGLE_ELEMENT_IN_A_SORTED_ARRAY_H__
#define LEETCODE_PROBLEMS_SINGLE_ELEMENT_IN_A_SORTED_ARRAY_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_540 {

class SingleElementInASortedArraySolution : public SolutionBase<
    std::function<int(std::vector<int>&)>> {
 public:
  SingleElementInASortedArraySolution();

  int singleNonDuplicate(std::vector<int>& nums);
};

}  // namespace problem_540
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SINGLE_ELEMENT_IN_A_SORTED_ARRAY_H__
