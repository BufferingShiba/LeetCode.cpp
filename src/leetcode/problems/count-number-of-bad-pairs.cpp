#include "leetcode/problems/count-number-of-bad-pairs.h"

#include <unordered_map>
#include <vector>

namespace leetcode::problem_2364 {

namespace {

long long countBadPairsImpl(std::vector<int>& nums) {
  long long n = static_cast<long long>(nums.size());
  long long total = n * (n - 1) / 2;

  std::unordered_map<int, long long> freq;
  for (int i = 0; i < static_cast<int>(n); ++i) {
    int diff = i - nums[i];
    ++freq[diff];
  }

  long long good = 0;
  for (const auto& [_, k] : freq) {
    good += k * (k - 1) / 2;
  }

  return total - good;
}

}  // namespace

CountNumberOfBadPairsSolution::CountNumberOfBadPairsSolution() {
  setMetaInfo({.id = 2364,
               .title = "Count Number of Bad Pairs",
               .url = "https://leetcode.com/problems/count-number-of-bad-pairs/"});

  registerStrategy({.name = "HashTable",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Hash Table", "Math", "Counting"}},
                   countBadPairsImpl);

  setDefaultStrategy();
}

long long CountNumberOfBadPairsSolution::countBadPairs(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_2364
