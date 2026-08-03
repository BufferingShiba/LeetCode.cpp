#include "leetcode/problems/longest-harmonious-subsequence.h"

#include <unordered_map>

namespace leetcode {
namespace problem_594 {

namespace {

int findLHSImpl(std::vector<int>& nums) {
  std::unordered_map<int, int> count;
  for (int num : nums) {
    ++count[num];
  }

  int best = 0;
  for (const auto& [num, cnt] : count) {
    auto it = count.find(num + 1);
    if (it != count.end()) {
      best = std::max(best, cnt + it->second);
    }
  }
  return best;
}

}  // namespace

LongestHarmoniousSubsequenceSolution::LongestHarmoniousSubsequenceSolution() {
  setMetaInfo({.id = 594,
               .title = "Longest Harmonious Subsequence",
               .url = "https://leetcode.com/problems/longest-harmonious-subsequence/"});
  registerStrategy(
      {.name = "HashMapCount",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Counting"}},
      findLHSImpl);
}

int LongestHarmoniousSubsequenceSolution::findLHS(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_594
}  // namespace leetcode
