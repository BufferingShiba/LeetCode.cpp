#ifndef LEETCODE_PROBLEMS_FIND_THE_LARGEST_ALMOST_MISSING_INTEGER_H__
#define LEETCODE_PROBLEMS_FIND_THE_LARGEST_ALMOST_MISSING_INTEGER_H__

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3471 {

using Func = std::function<int(std::vector<int>&, int)>;

// Strategy free function, defined in the source file.
int largestIntegerStrategy(std::vector<int>& nums, int k);

class FindTheLargestAlmostMissingIntegerSolution
    : public SolutionBase<Func> {
 public:
  FindTheLargestAlmostMissingIntegerSolution() {
    setMetaInfo({.id = 3471,
                 .title = "Find the Largest Almost Missing Integer",
                 .url = "https://leetcode.com/problems/find-the-largest-almost-missing-integer/"});
    registerStrategy(
        {.name = "hashmap-count-subarrays",
         .expected = "Accepted",
         .time_complexity = "O(n*k)",
         .space_complexity = "O(n)",
         .tags = {"Array", "Hash Table"}},
        largestIntegerStrategy);
  }

  int largestInteger(std::vector<int>& nums, int k) {
    return getSolution()(nums, k);
  }
};

}  // namespace problem_3471
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIND_THE_LARGEST_ALMOST_MISSING_INTEGER_H__
