#include "leetcode/problems/minimum-cost-to-make-array-equalindromic.h"

#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2967 {

namespace {

// All palindromes < 1e9.
const std::vector<long long>& palindromes() {
  static const std::vector<long long> pals = [] {
    std::vector<long long> res;
    for (int len = 1; len <= 9; ++len) {
      int halfLen = (len + 1) / 2;
      long long start = 1;
      for (int i = 1; i < halfLen; ++i) start *= 10;
      long long limit = start * 10;
      for (long long front = start; front < limit; ++front) {
        std::string s = std::to_string(front);
        std::string pal = s;
        int from = static_cast<int>(s.size() - 1 - (len % 2));
        for (int i = from; i >= 0; --i) pal.push_back(s[i]);
        long long v = std::stoll(pal);
        if (v < 1000000000LL) res.push_back(v);
      }
    }
    std::sort(res.begin(), res.end());
    res.erase(std::unique(res.begin(), res.end()), res.end());
    return res;
  }();
  return pals;
}

long long costFor(const std::vector<int>& nums, long long p) {
  long long sum = 0;
  for (int v : nums) sum += std::llabs((long long)v - p);
  return sum;
}

long long minimumCostImpl(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  long long median = nums[nums.size() / 2];

  const auto& pals = palindromes();
  auto it = std::lower_bound(pals.begin(), pals.end(), median);

  long long best = -1;
  // smallest palindrome >= median
  if (it != pals.end()) best = costFor(nums, *it);
  // largest palindrome <= median
  if (it != pals.begin()) {
    long long c = costFor(nums, *(it - 1));
    best = (best == -1) ? c : std::min(best, c);
  }
  return best;
}

}  // namespace

MinimumCostToMakeArrayEqualindromicSolution::
    MinimumCostToMakeArrayEqualindromicSolution() {
  setMetaInfo({.id = 2967,
               .title = "Minimum Cost to Make Array Equalindromic",
               .url = "https://leetcode.com/problems/minimum-cost-to-make-"
                       "array-equalindromic/"});
  registerStrategy({.name = "NearestMedianPalindromes",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(1) excluding sort+palindrome list",
                    .tags = {"Array", "Math", "Greedy", "Sorting"}},
                   minimumCostImpl);
}

long long MinimumCostToMakeArrayEqualindromicSolution::minimumCost(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2967
}  // namespace leetcode
