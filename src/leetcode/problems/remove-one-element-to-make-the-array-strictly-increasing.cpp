#include "leetcode/problems/remove-one-element-to-make-the-array-strictly-increasing.h"

namespace leetcode {
namespace problem_1909 {

namespace {

bool canBeIncreasingImpl(std::vector<int>& nums) {
  bool removed = false;
  const int n = static_cast<int>(nums.size());
  for (int i = 0; i + 1 < n; ++i) {
    if (nums[i] < nums[i + 1]) {
      continue;
    }
    if (removed) {
      return false;
    }
    // nums[i] >= nums[i + 1], need to remove one of them.
    // Remove nums[i] if it keeps order with previous and next, else remove nums[i+1].
    const bool okRemoveLeft = (i == 0) || (nums[i - 1] < nums[i + 1]);
    const bool okRemoveRight = (i + 2 >= n) || (nums[i] < nums[i + 2]);
    if (!okRemoveLeft && !okRemoveRight) {
      return false;
    }
    removed = true;
    if (okRemoveLeft) {
      // Removing nums[i]; skip comparing i with i+1 again.
      // We should continue checking but i+1 becomes the new left boundary
      // relative to i+2. To model removal of nums[i], skip this index.
      if (i + 2 < n && nums[i + 1] >= nums[i + 2]) {
        return false;
      }
      ++i;
    } else {
      // Removing nums[i+1]; skip forward so next compare is i+1 vs i+2.
      if (i + 2 < n && nums[i] >= nums[i + 2]) {
        return false;
      }
      ++i;
    }
  }
  return true;
}

}  // namespace

RemoveOneElementToMakeTheArrayStrictlyIncreasingSolution::
    RemoveOneElementToMakeTheArrayStrictlyIncreasingSolution() {
  setMetaInfo({.id = 1909,
               .title = "Remove One Element to Make the Array Strictly Increasing",
               .url = "https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/"});
  registerStrategy({.name = "Greedy",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Greedy"}},
                   canBeIncreasingImpl);
}

bool RemoveOneElementToMakeTheArrayStrictlyIncreasingSolution::canBeIncreasing(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_1909
}  // namespace leetcode
