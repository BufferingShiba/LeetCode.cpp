#ifndef LEETCODE_PROBLEMS_FIND_IF_ARRAY_CAN_BE_SORTED_H_
#define LEETCODE_PROBLEMS_FIND_IF_ARRAY_CAN_BE_SORTED_H_

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3011 {

using Func = std::function<bool(std::vector<int>&)>;

class FindIfArrayCanBeSortedSolution : public SolutionBase<Func> {
 public:
  FindIfArrayCanBeSortedSolution();

  bool canSortArray(std::vector<int>& nums);
};

}  // namespace problem_3011
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_IF_ARRAY_CAN_BE_SORTED_H_
