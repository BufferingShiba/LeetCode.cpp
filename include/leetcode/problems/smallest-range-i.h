#ifndef LEETCODE_PROBLEMS_SMALLEST_RANGE_I_H__
#define LEETCODE_PROBLEMS_SMALLEST_RANGE_I_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_908 {

using Func = std::function<int(std::vector<int>&, int)>;

class SmallestRangeISolution : public SolutionBase<Func> {
 public:
  SmallestRangeISolution();

  int smallestRangeI(std::vector<int>& nums, int k);
};

}  // namespace problem_908
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_SMALLEST_RANGE_I_H__
