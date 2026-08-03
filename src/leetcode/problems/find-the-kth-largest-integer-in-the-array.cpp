#include "leetcode/problems/find-the-kth-largest-integer-in-the-array.h"

#include <algorithm>

namespace leetcode {
namespace problem_1985 {

// Sort by numeric value using a custom comparator. Since every string has no
// leading zeros, a longer string is always greater numerically. When lengths
// are equal, lexicographic comparison matches numeric comparison.
static string solution1(vector<string>& nums, int k) {
  std::sort(nums.begin(), nums.end(),
            [](const string& a, const string& b) {
              if (a.size() != b.size()) {
                return a.size() > b.size();
              }
              return a > b;
            });
  return nums[k - 1];
}

FindTheKthLargestIntegerInTheArraySolution::FindTheKthLargestIntegerInTheArraySolution() {
  setMetaInfo({
      .id = 1985,
      .title = "Find the Kth Largest Integer in the Array",
      .url = "https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array"
  });
  registerStrategy({.name = "Sort by Length",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n * L)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Sorting", "String"}},
                   solution1);
}

string FindTheKthLargestIntegerInTheArraySolution::kthLargestNumber(vector<string>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_1985
}  // namespace leetcode
