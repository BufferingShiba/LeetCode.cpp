#include "leetcode/problems/count-nice-pairs-in-an-array.h"

#include <unordered_map>

namespace leetcode {
namespace problem_1814 {
namespace {

constexpr long long kMod = 1000000007LL;

long long rev(long long x) {
  long long r = 0;
  while (x > 0) {
    r = r * 10 + x % 10;
    x /= 10;
  }
  return r;
}

int countNicePairsImpl(std::vector<int>& nums) {
  std::unordered_map<long long, long long> count;
  long long ans = 0;
  const long long mod = kMod;
  for (int num : nums) {
    long long key = static_cast<long long>(num) - rev(num);
    ans = (ans + count[key]) % mod;
    ++count[key];
  }
  return static_cast<int>(ans);
}

}  // namespace

CountNicePairsInAnArraySolution::CountNicePairsInAnArraySolution() {
  setMetaInfo({.id = 1814,
               .title = "Count Nice Pairs in an Array",
               .url = "https://leetcode.com/problems/count-nice-pairs-in-an-array/"});
  registerStrategy({.name = "hash-key-transform",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Hash Table", "Math", "Counting"}},
                   countNicePairsImpl);
}

int CountNicePairsInAnArraySolution::countNicePairs(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_1814
}  // namespace leetcode
