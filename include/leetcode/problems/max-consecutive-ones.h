#ifndef LEETCODE_PROBLEMS_MAX_CONSECUTIVE_ONES_H__
#define LEETCODE_PROBLEMS_MAX_CONSECUTIVE_ONES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_485 {

using Func = std::function<int(std::vector<int>&)>;

class MaxConsecutiveOnesSolution : public SolutionBase<Func> {
 public:
  MaxConsecutiveOnesSolution();

  int findMaxConsecutiveOnes(std::vector<int>& nums);
};

}  // namespace problem_485
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MAX_CONSECUTIVE_ONES_H__
