#include "leetcode/problems/form-array-by-concatenating-subarrays-of-another-array.h"

namespace leetcode {
namespace problem_1764 {

static bool solution1(vector<vector<int>>& groups, vector<int>& nums) {
  int m = nums.size();
  int idx = 0;  // current scan start position in nums
  for (const auto& g : groups) {
    int len = g.size();
    bool found = false;
    // Try to find g starting at or after idx.
    for (int start = idx; start + len <= m; ++start) {
      bool match = true;
      for (int k = 0; k < len; ++k) {
        if (nums[start + k] != g[k]) {
          match = false;
          break;
        }
      }
      if (match) {
        idx = start + len;  // next group must start after this one (disjoint, ordered)
        found = true;
        break;
      }
    }
    if (!found) return false;
  }
  return true;
}

FormArrayByConcatenatingSubarraysOfAnotherArraySolution::FormArrayByConcatenatingSubarraysOfAnotherArraySolution() {
  setMetaInfo({
      .id = 1764,
      .title = "Form Array by Concatenating Subarrays of Another Array",
      .url = "https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array"
  });
  registerStrategy({.name = "Greedy Matching", .time_complexity = "O(n * sum(len(groups)))", .space_complexity = "O(1)", .tags = {"Two Pointers", "Greedy"}}, solution1);
}

bool FormArrayByConcatenatingSubarraysOfAnotherArraySolution::canChoose(vector<vector<int>>& groups, vector<int>& nums) {
  return getSolution()(groups, nums);
}

}  // namespace problem_1764
}  // namespace leetcode
