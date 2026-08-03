#include "leetcode/problems/find-subarrays-with-equal-sum.h"

#include <unordered_set>

namespace leetcode::problem_2395 {

namespace {

bool findSubarraysImpl(std::vector<int>& nums) {
  std::unordered_set<int> seen;
  for (std::size_t i = 0; i + 1 < nums.size(); ++i) {
    int sum = nums[i] + nums[i + 1];
    if (seen.find(sum) != seen.end()) {
      return true;
    }
    seen.insert(sum);
  }
  return false;
}

}  // namespace

FindSubarraysWithEqualSumSolution::FindSubarraysWithEqualSumSolution() {
  setMetaInfo({.id = 2395, .title = "Find Subarrays With Equal Sum", .url = "https://leetcode.com/problems/find-subarrays-with-equal-sum/"});
  registerStrategy({.name = "HashSet", .expected = "Accepted", .time_complexity = "O(n)", .space_complexity = "O(n)", .tags = {"Array", "Hash Table"}}, findSubarraysImpl);
}

bool FindSubarraysWithEqualSumSolution::findSubarrays(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_2395
