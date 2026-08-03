#ifndef LEETCODE_PROBLEMS_FIND_THE_INTEGER_ADDED_TO_ARRAY_II_H
#define LEETCODE_PROBLEMS_FIND_THE_INTEGER_ADDED_TO_ARRAY_II_H

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3132 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class FindTheIntegerAddedToArrayIiSolution : public SolutionBase<Func> {
 public:
  FindTheIntegerAddedToArrayIiSolution();

  int minimumAddedInteger(std::vector<int>& nums1, std::vector<int>& nums2);
};

}  // namespace problem_3132
}  // namespace leetcode

#endif
