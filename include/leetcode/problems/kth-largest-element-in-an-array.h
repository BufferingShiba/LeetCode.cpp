#ifndef LEETCODE_PROBLEMS_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_H__
#define LEETCODE_PROBLEMS_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_215 {

using Func = std::function<int(std::vector<int>&, int)>;

class KthLargestElementInAnArraySolution
    : public SolutionBase<Func> {
 public:
  KthLargestElementInAnArraySolution();
  int findKthLargest(std::vector<int>& nums, int k);
};

}  // namespace problem_215
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_KTH_LARGEST_ELEMENT_IN_AN_ARRAY_H__
