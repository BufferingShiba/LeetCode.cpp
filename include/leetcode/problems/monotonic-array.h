#ifndef LEETCODE_PROBLEMS_MONOTONIC_ARRAY_H__
#define LEETCODE_PROBLEMS_MONOTONIC_ARRAY_H__

#include <functional>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_896 {

using Func = std::function<bool(std::vector<int>&)>;

class MonotonicArraySolution : public SolutionBase<Func> {
 public:
  MonotonicArraySolution();
  bool isMonotonic(std::vector<int>& nums);
};

}  // namespace problem_896
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MONOTONIC_ARRAY_H__
