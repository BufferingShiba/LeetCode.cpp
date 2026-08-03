#ifndef LEETCODE_PROBLEMS_NUMBER_OF_SUBARRAYS_THAT_MATCH_A_PATTERN_I_H__
#define LEETCODE_PROBLEMS_NUMBER_OF_SUBARRAYS_THAT_MATCH_A_PATTERN_I_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3034 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class NumberOfSubarraysThatMatchAPatternISolution
    : public SolutionBase<Func> {
 public:
  NumberOfSubarraysThatMatchAPatternISolution() {
    setMetaInfo({.id = 3034,
                 .title = "Number of Subarrays That Match a Pattern I",
                 .url =
                     "https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-i/"});

    registerStrategy(
        {.name = "KMP matching on relation array",
         .expected = "Accepted",
         .time_complexity = "O(n + m)",
         .space_complexity = "O(m)",
         .tags = {"String Matching", "KMP", "Rolling Hash"}},
        countMatchingSubarraysKmp);
  }

  int countMatchingSubarrays(std::vector<int>& nums,
                             std::vector<int>& pattern) {
    return getSolution()(nums, pattern);
  }

 private:
  static int countMatchingSubarraysKmp(std::vector<int>& nums,
                                       std::vector<int>& pattern);
};

}  // namespace problem_3034
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_NUMBER_OF_SUBARRAYS_THAT_MATCH_A_PATTERN_I_H__
