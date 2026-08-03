#ifndef LEETCODE_PROBLEMS_FIND_THE_SMALLEST_BALANCED_INDEX_H__
#define LEETCODE_PROBLEMS_FIND_THE_SMALLEST_BALANCED_INDEX_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3862 {

using Func = std::function<int(std::vector<int>&)>;

class FindTheSmallestBalancedIndexSolution
    : public SolutionBase<Func> {
 public:
  FindTheSmallestBalancedIndexSolution();

  int smallestBalancedIndex(std::vector<int>& nums);
};

}  // namespace problem_3862
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_SMALLEST_BALANCED_INDEX_H__
