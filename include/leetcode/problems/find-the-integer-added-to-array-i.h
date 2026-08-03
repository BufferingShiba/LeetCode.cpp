#ifndef LEETCODE_PROBLEMS_FIND_THE_INTEGER_ADDED_TO_ARRAY_I_H__
#define LEETCODE_PROBLEMS_FIND_THE_INTEGER_ADDED_TO_ARRAY_I_H__

#include "leetcode/core.h"

#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3131 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class FindTheIntegerAddedToArrayISolution : public SolutionBase<Func> {
 public:
  FindTheIntegerAddedToArrayISolution();

  int addedInteger(std::vector<int>& nums1, std::vector<int>& nums2);
};

}  // namespace problem_3131
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_INTEGER_ADDED_TO_ARRAY_I_H__
