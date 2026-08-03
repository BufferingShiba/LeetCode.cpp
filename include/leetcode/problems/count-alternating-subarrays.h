#ifndef LEETCODE_PROBLEM_COUNT_ALTERNATING_SUBARRAYS_H
#define LEETCODE_PROBLEM_COUNT_ALTERNATING_SUBARRAYS_H

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_3101 {

using Func = std::function<long long(std::vector<int>&)>;

class CountAlternatingSubarraysSolution : public SolutionBase<Func> {
 public:
  CountAlternatingSubarraysSolution();
  long long countAlternatingSubarrays(std::vector<int>& nums);
};

}  // namespace problem_3101
}  // namespace leetcode

#endif
