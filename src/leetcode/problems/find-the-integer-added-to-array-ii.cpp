#include "leetcode/problems/find-the-integer-added-to-array-ii.h"

#include <algorithm>
#include <climits>
#include <vector>

namespace leetcode {
namespace problem_3132 {

static int minimumAddedIntegerImpl(std::vector<int>& nums1,
                                   std::vector<int>& nums2) {
  std::sort(nums1.begin(), nums1.end());
  std::sort(nums2.begin(), nums2.end());

  const int n1 = static_cast<int>(nums1.size());
  const int n2 = static_cast<int>(nums2.size());

  auto check = [&](int x) -> bool {
    int i = 0, j = 0, removed = 0;
    while (j < n2) {
      if (i >= n1) return false;
      if (nums1[i] + x == nums2[j]) {
        ++i;
        ++j;
      } else {
        ++i;
        ++removed;
        if (removed > 2) return false;
      }
    }
    removed += n1 - i;  // 剩余元素也必须被移除
    return removed == 2;
  };

  int ans = INT_MAX;
  // b[0] 至多由 a[0], a[1], a[2] 产生
  for (int i = 0; i < 3 && i < n1; ++i) {
    int x = nums2[0] - nums1[i];
    if (check(x)) {
      ans = std::min(ans, x);
    }
  }

  return ans;
}

FindTheIntegerAddedToArrayIiSolution::FindTheIntegerAddedToArrayIiSolution() {
  setMetaInfo({.id = 3132,
               .title = "Find the Integer Added to Array II",
               .url = "https://leetcode.com/problems/find-the-integer-added-to-array-ii/"});
  registerStrategy(
      {.name = "SortAndTwoPointers",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers", "Sorting", "Enumeration"}},
      minimumAddedIntegerImpl);
}

int FindTheIntegerAddedToArrayIiSolution::minimumAddedInteger(
    std::vector<int>& nums1, std::vector<int>& nums2) {
  return getSolution()(nums1, nums2);
}

}  // namespace problem_3132
}  // namespace leetcode
