#ifndef LEETCODE_PROBLEMS_K_TH_SMALLEST_REMAINING_EVEN_INTEGER_IN_SUBARRAY_QUERIES_H__
#define LEETCODE_PROBLEMS_K_TH_SMALLEST_REMAINING_EVEN_INTEGER_IN_SUBARRAY_QUERIES_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3911 {

using Func = std::function<std::vector<int>(std::vector<int>&, std::vector<std::vector<int>>&)>;

class KThSmallestRemainingEvenIntegerInSubarrayQueriesSolution
    : public SolutionBase<Func> {
 public:
  KThSmallestRemainingEvenIntegerInSubarrayQueriesSolution();

  std::vector<int> kthRemainingInteger(std::vector<int>& nums,
                                       std::vector<std::vector<int>>& queries);
};

}  // namespace problem_3911
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_K_TH_SMALLEST_REMAINING_EVEN_INTEGER_IN_SUBARRAY_QUERIES_H__
