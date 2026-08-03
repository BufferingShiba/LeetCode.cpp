#ifndef LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_INCREMOVABLE_SUBARRAYS_II_H_
#define LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_INCREMOVABLE_SUBARRAYS_II_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2972 {

using Func = std::function<long long(std::vector<int>&)>;

class CountTheNumberOfIncremovableSubarraysIiSolution
    : public SolutionBase<Func> {
 public:
  CountTheNumberOfIncremovableSubarraysIiSolution() {
    setMetaInfo(
        {.id = 2972,
         .title = "Count the Number of Incremovable Subarrays II",
         .url = "https://leetcode.com/problems/count-the-number-of-"
                "incremovable-subarrays-ii/"});

    registerStrategy(
        {.name = "TwoPointers",
         .time_complexity = "O(n)",
         .space_complexity = "O(1)",
         .tags = {"Array", "Two Pointers"}},  //
        SolveIncremovableSubarrayCount);
  }

  long long incremovableSubarrayCount(std::vector<int>& nums) {
    return getSolution()(nums);
  }

 private:
  static long long SolveIncremovableSubarrayCount(std::vector<int>& nums);
};

}  // namespace problem_2972
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_THE_NUMBER_OF_INCREMOVABLE_SUBARRAYS_II_H_
