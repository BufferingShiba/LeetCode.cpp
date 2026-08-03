#include "leetcode/problems/find-the-largest-almost-missing-integer.h"

#include <unordered_map>
#include <unordered_set>

namespace leetcode {
namespace problem_3471 {

int largestIntegerStrategy(std::vector<int>& nums, int k) {
  const int n = static_cast<int>(nums.size());
  std::unordered_map<int, int> count;
  std::unordered_set<int> present;
  for (int start = 0; start + k <= n; ++start) {
    present.clear();
    for (int i = start; i < start + k; ++i) {
      present.insert(nums[i]);
    }
    for (int v : present) {
      count[v]++;
    }
  }
  int ans = -1;
  for (const auto& entry : count) {
    if (entry.second == 1 && entry.first > ans) {
      ans = entry.first;
    }
  }
  return ans;
}

}  // namespace problem_3471
}  // namespace leetcode
