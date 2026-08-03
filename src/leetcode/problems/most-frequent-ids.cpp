#include "leetcode/problems/most-frequent-ids.h"

#include <map>
#include <vector>

namespace leetcode {
namespace problem_3092 {

std::vector<long long> MostFrequentIdsSolution::mostFrequentIDsImpl(
    std::vector<int>& nums, std::vector<int>& freq) {
  const int n = static_cast<int>(nums.size());
  std::vector<long long> ans(n, 0);

  // countToNumIds: count -> number of IDs currently having that count.
  std::map<long long, long long> countToNumIds;
  // idToCount: id -> current count.
  std::map<int, long long> idToCount;

  for (int i = 0; i < n; ++i) {
    const int id = nums[i];
    const long long delta = freq[i];

    long long oldCount = 0;
    auto it = idToCount.find(id);
    if (it != idToCount.end()) {
      oldCount = it->second;
    }
    const long long newCount = oldCount + delta;
    idToCount[id] = newCount;

    // Remove old count (only if > 0).
    if (oldCount > 0) {
      auto cit = countToNumIds.find(oldCount);
      if (--cit->second == 0) {
        countToNumIds.erase(cit);
      }
    }
    // Add new count (only if > 0).
    if (newCount > 0) {
      ++countToNumIds[newCount];
    }

    // Answer is the max count that has at least one ID.
    if (countToNumIds.empty()) {
      ans[i] = 0;
    } else {
      ans[i] = countToNumIds.rbegin()->first;
    }
  }

  return ans;
}

}  // namespace problem_3092
}  // namespace leetcode
