#include "leetcode/problems/shortest-unsorted-continuous-subarray.h"

#include <algorithm>

namespace leetcode {
namespace problem_581 {

static int solution1(vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  int begin = 0, end = -1;
  int max_v = nums[0];
  for (int i = 1; i < n; ++i) {
    if (nums[i] < max_v) {
      end = i;
    } else {
      max_v = nums[i];
    }
  }
  int min_v = nums[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    if (nums[i] > min_v) {
      begin = i;
    } else {
      min_v = nums[i];
    }
  }
  return (begin > end) ? 0 : (end - begin + 1);
}

ShortestUnsortedContinuousSubarraySolution::ShortestUnsortedContinuousSubarraySolution() {
  setMetaInfo({
      .id = 581,
      .title = "Shortest Unsorted Continuous Subarray",
      .url = "https://leetcode.com/problems/shortest-unsorted-continuous-subarray"
  });
  registerStrategy({
      .name = "Two-pass O(n)",
      .expected = "Accepted",
      .time_complexity = "O(n)",
      .space_complexity = "O(1)",
      .tags = {"Array"}
  }, solution1);
}

int ShortestUnsortedContinuousSubarraySolution::findUnsortedSubarray(vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_581
}  // namespace leetcode
