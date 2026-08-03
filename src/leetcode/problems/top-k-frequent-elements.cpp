#include "leetcode/problems/top-k-frequent-elements.h"

#include <unordered_map>

namespace leetcode {
namespace problem_347 {

static vector<int> solution1(vector<int>& nums, int k) {
  // Count frequencies of each element.
  std::unordered_map<int, int> freq;
  for (int num : nums) {
    ++freq[num];
  }

  // Bucket sort: bucket[i] holds all numbers whose frequency is i.
  int n = nums.size();
  std::vector<std::vector<int>> buckets(n + 1);
  for (const auto& [num, count] : freq) {
    buckets[count].push_back(num);
  }

  // Collect the k most frequent elements by scanning buckets from high to low.
  std::vector<int> result;
  for (int i = n; i >= 1 && result.size() < static_cast<size_t>(k); --i) {
    for (int num : buckets[i]) {
      result.push_back(num);
      if (result.size() == static_cast<size_t>(k)) break;
    }
  }
  return result;
}

TopKFrequentElementsSolution::TopKFrequentElementsSolution() {
  setMetaInfo({
      .id = 347,
      .title = "Top K Frequent Elements",
      .url = "https://leetcode.com/problems/top-k-frequent-elements"
  });
  registerStrategy({.name = "Bucket Sort",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Hash Table", "Bucket Sort"}},
                   solution1);
}

vector<int> TopKFrequentElementsSolution::topKFrequent(vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_347
}  // namespace leetcode
