#include "leetcode/problems/count-beautiful-splits-in-an-array.h"

namespace leetcode::problem_3388 {
namespace {

int beautifulSplitsImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  if (n < 3) {
    return 0;
  }

  // lcp[i][j]: length of longest common prefix starting at indices i and j.
  // lcp[i][j] = (nums[i] == nums[j]) ? 1 + lcp[i+1][j+1] : 0
  std::vector<std::vector<int>> lcp(n + 1, std::vector<int>(n + 1, 0));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (nums[i] == nums[j]) {
        lcp[i][j] = 1 + lcp[i + 1][j + 1];
      }
    }
  }

  int count = 0;
  for (int i = 1; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      const int len1 = i;           // nums1 = nums[0..i-1]
      const int len2 = j - i;       // nums2 = nums[i..j-1]
      const int len3 = n - j;       // nums3 = nums[j..n-1]

      bool cond1 = false;
      // nums1 is prefix of nums2: need len2 >= len1 and lcp[0][i] >= len1.
      if (len2 >= len1 && lcp[0][i] >= len1) {
        cond1 = true;
      }

      bool cond2 = false;
      // nums2 is prefix of nums3: need len3 >= len2 and lcp[i][j] >= len2.
      if (len3 >= len2 && lcp[i][j] >= len2) {
        cond2 = true;
      }

      if (cond1 || cond2) {
        ++count;
      }
    }
  }
  return count;
}

}  // namespace

CountBeautifulSplitsInAnArraySolution::CountBeautifulSplitsInAnArraySolution() {
  setMetaInfo({.id = 3388,
               .title = "Count Beautiful Splits in an Array",
               .url = "https://leetcode.com/problems/count-beautiful-splits-in-an-array/"});
  registerStrategy(
      {.name = "lcp-dp",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n^2)",
       .tags = {"Array", "Dynamic Programming"}},
      beautifulSplitsImpl);
}

int CountBeautifulSplitsInAnArraySolution::beautifulSplits(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3388
