#include "leetcode/problems/construct-uniform-parity-array-ii.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3876 {
namespace {

bool uniformArrayImpl(std::vector<int>& nums1) {
  std::sort(nums1.begin(), nums1.end());
  const int n = static_cast<int>(nums1.size());

  std::vector<int> evenPrefix(n, 0), oddPrefix(n, 0);
  int even = 0, odd = 0;
  for (int i = 0; i < n; ++i) {
    evenPrefix[i] = even;
    oddPrefix[i] = odd;
    if (nums1[i] % 2 == 0) {
      ++even;
    } else {
      ++odd;
    }
  }

  for (int target = 0; target <= 1; ++target) {  // 0 = all even, 1 = all odd
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      const int p = nums1[i] % 2;
      if (p == target) continue;  // option A: nums2[i] = nums1[i]
      // Need a smaller element j<i with parity p ^ target.
      const int needed = p ^ target;
      const int available = (needed == 0) ? evenPrefix[i] : oddPrefix[i];
      if (available == 0) {
        ok = false;
        break;
      }
    }
    if (ok) return true;
  }
  return false;
}

}  // namespace

bool ConstructUniformParityArrayIiSolution::uniformArray(std::vector<int>& nums1) {
  return getSolution()(nums1);
}

ConstructUniformParityArrayIiSolution::ConstructUniformParityArrayIiSolution() {
  setMetaInfo({.id = 3876,
               .title = "Construct Uniform Parity Array II",
               .url = "https://leetcode.com/problems/construct-uniform-parity-array-ii/"});
  registerStrategy({.name = "prefix-parity-check",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Math"}},
                   uniformArrayImpl);
}

}  // namespace problem_3876
}  // namespace leetcode
