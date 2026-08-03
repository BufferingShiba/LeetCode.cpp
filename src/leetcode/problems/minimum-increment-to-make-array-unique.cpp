#include "leetcode/problems/minimum-increment-to-make-array-unique.h"

#include <algorithm>

namespace leetcode {
namespace problem_945 {

static int solution1(vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  int moves = 0;
  for (int i = 1; i < (int)nums.size(); ++i) {
    if (nums[i] <= nums[i - 1]) {
      moves += nums[i - 1] + 1 - nums[i];
      nums[i] = nums[i - 1] + 1;
    }
  }
  return moves;
}

MinimumIncrementToMakeArrayUniqueSolution::MinimumIncrementToMakeArrayUniqueSolution() {
  setMetaInfo({
      .id = 945,
      .title = "Minimum Increment to Make Array Unique",
      .url = "https://leetcode.com/problems/minimum-increment-to-make-array-unique"
  });
  registerStrategy({.name = "Greedy Sort", .time_complexity = "O(n log n)",
                     .space_complexity = "O(log n)",
                     .tags = {"Greedy", "Sorting", "Counting"}},
                    solution1);
}

int MinimumIncrementToMakeArrayUniqueSolution::minIncrementForUnique(vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_945
}  // namespace leetcode
