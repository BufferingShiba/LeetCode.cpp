#ifndef LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_SQUARE_FREE_SUBSETS_H__
#define LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_SQUARE_FREE_SUBSETS_H__

#include "leetcode/core.h"
#include <functional>
#include <vector>

namespace leetcode {
namespace problem_2572 {

using Func = std::function<int(std::vector<int>&)>;

class CountTheNumberOfSquareFreeSubsetsSolution : public SolutionBase<Func> {
 public:
  CountTheNumberOfSquareFreeSubsetsSolution();
  int squareFreeSubsets(std::vector<int>& nums);
};

}  // namespace problem_2572
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_SQUARE_FREE_SUBSETS_H__
