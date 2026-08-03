#include "leetcode/problems/minimum-index-of-a-valid-split.h"

namespace leetcode {
namespace problem_2780 {

static int solution1(vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  if (n < 2) return -1;

  // Boyer-Moore majority vote to find the (unique) dominant element.
  int candidate = nums[0];
  int count = 1;
  for (int i = 1; i < n; ++i) {
    if (count == 0) {
      candidate = nums[i];
      count = 1;
    } else if (nums[i] == candidate) {
      ++count;
    } else {
      --count;
    }
  }

  // Compute total frequency of the dominant element.
  int total = 0;
  for (int v : nums) {
    if (v == candidate) ++total;
  }

  int leftCount = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (nums[i] == candidate) ++leftCount;
    int leftLen = i + 1;
    int rightLen = n - leftLen;
    int rightCount = total - leftCount;
    if (leftCount * 2 > leftLen && rightCount * 2 > rightLen) {
      return i;
    }
  }
  return -1;
}

MinimumIndexOfAValidSplitSolution::MinimumIndexOfAValidSplitSolution() {
  setMetaInfo({
      .id = 2780,
      .title = "Minimum Index of a Valid Split",
      .url = "https://leetcode.com/problems/minimum-index-of-a-valid-split"
  });
  registerStrategy({.name = "Majority Vote",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "HashMap"}},
                   solution1);
}

int MinimumIndexOfAValidSplitSolution::minimumIndex(vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2780
}  // namespace leetcode
