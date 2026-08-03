#include "leetcode/problems/k-divisible-elements-subarrays.h"

#include <unordered_set>

namespace leetcode {
namespace problem_2261 {
namespace {

struct VectorHash {
  std::size_t operator()(const std::vector<int>& v) const {
    std::size_t h = 0;
    for (int x : v) {
      h ^= static_cast<std::size_t>(x) + 0x9e3779b9 + (h << 6) + (h >> 2);
    }
    return h;
  }
};

int countDistinctImpl(std::vector<int>& nums, int k, int p) {
  const int n = static_cast<int>(nums.size());
  std::unordered_set<std::vector<int>, VectorHash> seen;
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    std::vector<int> sub;
    for (int j = i; j < n; ++j) {
      sub.push_back(nums[j]);
      if (nums[j] % p == 0) {
        ++cnt;
      }
      if (cnt > k) {
        break;
      }
      seen.insert(sub);
    }
  }
  return static_cast<int>(seen.size());
}

}  // namespace

KDivisibleElementsSubarraysSolution::KDivisibleElementsSubarraysSolution() {
  setMetaInfo({.id = 2261,
               .title = "K Divisible Elements Subarrays",
               .url = "https://leetcode.com/problems/k-divisible-elements-subarrays/"});
  registerStrategy(
      {.name = "enumerate-subarrays-set",
       .expected = "Accepted",
       .time_complexity = "O(n^3)",
       .space_complexity = "O(n^2)",
       .tags = {"Hash Table", "Enumeration"}},
      [](std::vector<int>& nums, int k, int p) -> int {
        return countDistinctImpl(nums, k, p);
      });
}

int KDivisibleElementsSubarraysSolution::countDistinct(std::vector<int>& nums, int k, int p) {
  return getSolution()(nums, k, p);
}

}  // namespace problem_2261
}  // namespace leetcode
