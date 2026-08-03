#include "leetcode/problems/contains-duplicate-ii.h"

#include <unordered_set>

namespace leetcode::problem_219 {

namespace {

bool containsNearbyDuplicateImpl(std::vector<int>& nums, int k) {
  std::unordered_set<int> window;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    if (i > k) {
      window.erase(nums[i - k - 1]);
    }
    if (window.find(nums[i]) != window.end()) {
      return true;
    }
    window.insert(nums[i]);
  }
  return false;
}

}  // namespace

ContainsDuplicateIiSolution::ContainsDuplicateIiSolution() {
  setMetaInfo({.id = 219,
               .title = "Contains Duplicate II",
               .url = "https://leetcode.com/problems/contains-duplicate-ii/"});
  registerStrategy({.name = "SlidingWindowHashSet",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(min(n, k))",
                    .tags = {"Array", "Hash Table", "Sliding Window"}},
                   containsNearbyDuplicateImpl);
}

bool ContainsDuplicateIiSolution::containsNearbyDuplicate(std::vector<int>& nums,
                                                          int k) {
  return getSolution()(nums, k);
}

}  // namespace leetcode::problem_219
