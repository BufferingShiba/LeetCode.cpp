#include "leetcode/problems/most-frequent-number-following-key-in-an-array.h"

#include <unordered_map>

namespace leetcode {
namespace problem_2190 {

namespace {

int mostFrequentImpl(std::vector<int>& nums, int key) {
  std::unordered_map<int, int> count;
  for (int i = 0; i + 1 < static_cast<int>(nums.size()); ++i) {
    if (nums[i] == key) {
      ++count[nums[i + 1]];
    }
  }

  int bestTarget = 0;
  int bestCount = -1;
  for (const auto& [target, cnt] : count) {
    if (cnt > bestCount) {
      bestCount = cnt;
      bestTarget = target;
    }
  }
  return bestTarget;
}

}  // namespace

MostFrequentNumberFollowingKeyInAnArraySolution::
    MostFrequentNumberFollowingKeyInAnArraySolution() {
  setMetaInfo({.id = 2190,
               .title = "Most Frequent Number Following Key In an Array",
               .url = "https://leetcode.com/problems/most-frequent-number-"
                       "following-key-in-an-array/"});
  registerStrategy(
      {.name = "hash-count",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Counting"}},
      mostFrequentImpl);
}

int MostFrequentNumberFollowingKeyInAnArraySolution::mostFrequent(
    std::vector<int>& nums, int key) {
  return getSolution()(nums, key);
}

}  // namespace problem_2190
}  // namespace leetcode
