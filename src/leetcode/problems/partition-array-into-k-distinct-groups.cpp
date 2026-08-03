#include "leetcode/problems/partition-array-into-k-distinct-groups.h"

#include <algorithm>
#include <unordered_map>

namespace leetcode {
namespace problem_3659 {

static bool solution1(vector<int>& nums, int k) {
  const int n = static_cast<int>(nums.size());
  if (n % k != 0) return false;

  const int groups = n / k;

  // A value occurring f times must occupy a slot in f distinct groups,
  // so we need max(freq) <= groups. This condition (plus n % k == 0) is
  // necessary and sufficient: it also implies there are at least k distinct
  // values available (k*groups total slots, each value filling at most groups).
  std::unordered_map<int, int> freq;
  freq.reserve(nums.size() * 2);
  int maxFreq = 0;
  for (int x : nums) {
    maxFreq = std::max(maxFreq, ++freq[x]);
  }
  return maxFreq <= groups;
}

PartitionArrayIntoKDistinctGroupsSolution::PartitionArrayIntoKDistinctGroupsSolution() {
  setMetaInfo({
      .id = 3659,
      .title = "Partition Array Into K-Distinct Groups",
      .url = "https://leetcode.com/problems/partition-array-into-k-distinct-groups"
  });
  registerStrategy({.name = "Brute Force", .time_complexity = "O(n)", .space_complexity = "O(n)", .tags = {"Greedy", "Hash Table"}}, solution1);
}

bool PartitionArrayIntoKDistinctGroupsSolution::partitionArray(vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_3659
}  // namespace leetcode
