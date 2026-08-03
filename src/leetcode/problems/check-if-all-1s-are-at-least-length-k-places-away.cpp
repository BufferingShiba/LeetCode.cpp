#include "leetcode/problems/check-if-all-1s-are-at-least-length-k-places-away.h"

namespace leetcode {
namespace problem_1437 {

static bool kLengthApartImpl(std::vector<int>& nums, int k) {
  int prev = -k - 1;  // 保证第一个 1 的距离检查必然通过
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    if (nums[i] == 1) {
      if (i - prev <= k) {
        return false;
      }
      prev = i;
    }
  }
  return true;
}

CheckIfAll1sAreAtLeastLengthKPlacesAwaySolution::CheckIfAll1sAreAtLeastLengthKPlacesAwaySolution() {
  setMetaInfo({.id = 1437,
               .title = "Check If All 1's Are at Least Length K Places Away",
               .url = "https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/"});
  registerStrategy({.name = "LinearScan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array"}},
                   kLengthApartImpl);
}

bool CheckIfAll1sAreAtLeastLengthKPlacesAwaySolution::kLengthApart(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_1437
}  // namespace leetcode
