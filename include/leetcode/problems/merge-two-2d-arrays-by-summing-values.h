#ifndef LEETCODE_PROBLEMS_MERGE_TWO_2D_ARRAYS_BY_SUMMING_VALUES_H_
#define LEETCODE_PROBLEMS_MERGE_TWO_2D_ARRAYS_BY_SUMMING_VALUES_H_

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2570 {

using Func =
    std::function<std::vector<std::vector<int>>(
        std::vector<std::vector<int>>&, std::vector<std::vector<int>>&)>;

class MergeTwo2dArraysBySummingValuesSolution
    : public SolutionBase<Func> {
 public:
  MergeTwo2dArraysBySummingValuesSolution();

  std::vector<std::vector<int>> mergeArrays(
      std::vector<std::vector<int>>& nums1,
      std::vector<std::vector<int>>& nums2);
};

}  // namespace problem_2570
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MERGE_TWO_2D_ARRAYS_BY_SUMMING_VALUES_H_
