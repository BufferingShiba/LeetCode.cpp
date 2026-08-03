#include "leetcode/problems/minimum-operations-to-maximize-last-elements-in-arrays.h"

namespace leetcode {
namespace problem_2934 {

namespace {

int minOperationsImpl(std::vector<int>& nums1, std::vector<int>& nums2) {
  int n = static_cast<int>(nums1.size());

  auto calc = [&](bool swap_last) -> int {
    int max1 = swap_last ? nums2.back() : nums1.back();
    int max2 = swap_last ? nums1.back() : nums2.back();
    int ops = swap_last ? 1 : 0;

    for (int i = 0; i < n - 1; ++i) {
      int a = nums1[i];
      int b = nums2[i];
      bool no_swap_ok = (a <= max1 && b <= max2);
      bool swap_ok = (b <= max1 && a <= max2);

      if (!no_swap_ok && !swap_ok) {
        return -1;
      }
      if (!no_swap_ok && swap_ok) {
        ops += 1;
      }
      // if both ok, prefer no swap (cost 0)
    }
    return ops;
  };

  int ans1 = calc(false);
  int ans2 = calc(true);

  if (ans1 == -1 && ans2 == -1) return -1;
  if (ans1 == -1) return ans2;
  if (ans2 == -1) return ans1;
  return std::min(ans1, ans2);
}

}  // namespace

MinimumOperationsToMaximizeLastElementsInArraysSolution::
    MinimumOperationsToMaximizeLastElementsInArraysSolution() {
  setMetaInfo({.id = 2934,
               .title = "Minimum Operations to Maximize Last Elements in Arrays",
               .url = "https://leetcode.com/problems/minimum-operations-to-maximize-last-elements-in-arrays/"});
  registerStrategy({.name = "Enumeration",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Enumeration"}},
                   minOperationsImpl);
}

int MinimumOperationsToMaximizeLastElementsInArraysSolution::minOperations(
    std::vector<int>& nums1, std::vector<int>& nums2) {
  return getSolution()(nums1, nums2);
}

}  // namespace problem_2934
}  // namespace leetcode
