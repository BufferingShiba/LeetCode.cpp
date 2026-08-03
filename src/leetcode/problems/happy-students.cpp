#include "leetcode/problems/happy-students.h"

#include <algorithm>

namespace leetcode {
namespace problem_2860 {

namespace {

// For a chosen group of size k, every selected student needs nums[i] < k and
// every unselected student needs nums[i] > k. Hence a feasible selection for a
// fixed k (if it exists) is uniquely: select exactly all students with
// nums[i] < k. This requires k == cnt(<k) and no student with nums[i] == k.
int countWaysByEnumeration(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  std::sort(nums.begin(), nums.end());
  int ways = 0;
  for (int k = 0; k <= n; ++k) {
    // lower_bound gives first index with nums[idx] >= k.
    const int lb = static_cast<int>(
        std::lower_bound(nums.begin(), nums.end(), k) - nums.begin());
    // cnt(< k) == lb must equal k, and there must be no student with value == k.
    if (lb == k && (lb == n || nums[lb] != k)) {
      ++ways;
    }
  }
  return ways;
}

}  // namespace

HappyStudentsSolution::HappyStudentsSolution() {
  setMetaInfo({.id = 2860,
               .title = "Happy Students",
               .url = "https://leetcode.com/problems/happy-students/"});
  registerStrategy(
      {"SortAndEnumerate", "Accepted", "O(n log n)", "O(1)",
       {"Array", "Sorting", "Enumeration"}},
      countWaysByEnumeration);
}

int HappyStudentsSolution::countWays(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2860
}  // namespace leetcode
