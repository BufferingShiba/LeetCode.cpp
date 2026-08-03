#include "leetcode/problems/contains-duplicate-iii.h"

#include <algorithm>
#include <cmath>
#include <unordered_map>

namespace leetcode {
namespace problem_220 {

namespace {

// Bucket Sort + Sliding Window: O(n) time, O(k) space
bool containsNearbyAlmostDuplicateImpl(std::vector<int>& nums, int indexDiff,
                                       int valueDiff) {
  if (nums.size() < 2 || indexDiff <= 0) return false;

  // bucket width = valueDiff + 1, use long long to avoid overflow
  long long w = static_cast<long long>(valueDiff) + 1;
  std::unordered_map<long long, long long> bucket;

  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    long long x = static_cast<long long>(nums[i]);

    // compute bucket id (handle negative numbers correctly)
    long long id = (x >= 0) ? (x / w) : ((x + 1) / w - 1);

    // check current bucket
    auto it = bucket.find(id);
    if (it != bucket.end()) {
      return true;  // same bucket => difference <= valueDiff
    }

    // check left neighbor bucket
    it = bucket.find(id - 1);
    if (it != bucket.end() && std::llabs(x - it->second) <= valueDiff) {
      return true;
    }

    // check right neighbor bucket
    it = bucket.find(id + 1);
    if (it != bucket.end() && std::llabs(x - it->second) <= valueDiff) {
      return true;
    }

    // put current element into bucket
    bucket[id] = x;

    // remove element that slides out of the window
    if (i >= indexDiff) {
      long long oldX = static_cast<long long>(nums[i - indexDiff]);
      long long oldId =
          (oldX >= 0) ? (oldX / w) : ((oldX + 1) / w - 1);
      bucket.erase(oldId);
    }
  }

  return false;
}

}  // namespace

ContainsDuplicateIiiSolution::ContainsDuplicateIiiSolution() {
  setMetaInfo({.id = 220,
               .title = "Contains Duplicate III",
               .url = "https://leetcode.com/problems/contains-duplicate-iii/"});

  registerStrategy(
      {.name = "Bucket Sort + Sliding Window",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(k)",
       .tags = {"Array", "Sliding Window", "Bucket Sort"}},
      containsNearbyAlmostDuplicateImpl);
}

bool ContainsDuplicateIiiSolution::containsNearbyAlmostDuplicate(
    std::vector<int>& nums, int indexDiff, int valueDiff) {
  return getSolution()(nums, indexDiff, valueDiff);
}

}  // namespace problem_220
}  // namespace leetcode
