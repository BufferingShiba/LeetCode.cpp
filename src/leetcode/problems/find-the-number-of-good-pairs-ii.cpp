#include "leetcode/problems/find-the-number-of-good-pairs-ii.h"

#include <unordered_map>

namespace leetcode::problem_3164 {

namespace {

long long numberOfPairsImpl(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
  std::unordered_map<int, int> cnt2;
  cnt2.reserve(nums2.size() * 2);
  for (int v : nums2) {
    ++cnt2[v];
  }

  long long ans = 0;
  for (int v : nums1) {
    // enumerate divisors f of v; candidate d = f / k when f % k == 0.
    int i = 1;
    for (; i * i <= v; ++i) {
      if (v % i != 0) {
        continue;
      }
      if (i % k == 0) {
        auto it = cnt2.find(i / k);
        if (it != cnt2.end()) {
          ans += it->second;
        }
      }
      int other = v / i;
      if (other != i && other % k == 0) {
        auto it = cnt2.find(other / k);
        if (it != cnt2.end()) {
          ans += it->second;
        }
      }
    }
  }
  return ans;
}

}  // namespace

FindTheNumberOfGoodPairsIiSolution::FindTheNumberOfGoodPairsIiSolution() {
  setMetaInfo({.id = 3164,
               .title = "Find the Number of Good Pairs II",
               .url = "https://leetcode.com/problems/find-the-number-of-good-pairs-ii/"});

  registerStrategy(
      {.name = "DivisorHash",
       .expected = "Accepted",
       .time_complexity = "O(n * sqrt(maxV) + m)",
       .space_complexity = "O(m)",
       .tags = {"Array", "Hash Table", "Math"},
       .notes = "Enumerate divisors of each nums1[i]; if divisor is a multiple of k, "
                "the candidate nums2 value is divisor/k; count via hash map."},
      [](std::vector<int>& a, std::vector<int>& b, int k) {
        return numberOfPairsImpl(a, b, k);
      });
}

long long FindTheNumberOfGoodPairsIiSolution::numberOfPairs(std::vector<int>& nums1,
                                                            std::vector<int>& nums2,
                                                            int k) {
  return getSolution()(nums1, nums2, k);
}

}  // namespace leetcode::problem_3164
