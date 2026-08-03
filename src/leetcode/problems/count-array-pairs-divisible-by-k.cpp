#include "leetcode/problems/count-array-pairs-divisible-by-k.h"

#include <numeric>
#include <unordered_map>
#include <vector>

namespace leetcode {
namespace problem_2183 {

static long long countPairsImpl(std::vector<int>& nums, int k) {
  // 1. 收集 k 的所有约数
  std::vector<int> divisors;
  for (int d = 1; d * d <= k; ++d) {
    if (k % d == 0) {
      divisors.push_back(d);
      if (d * d != k) {
        divisors.push_back(k / d);
      }
    }
  }

  // 2. 初始化每个约数的计数为 0
  std::unordered_map<int, long long> cnt;
  for (int d : divisors) {
    cnt[d] = 0;
  }

  // 3. 遍历数组，统计答案并更新计数
  long long ans = 0;
  for (int y : nums) {
    int g = std::gcd(y, k);
    int need = k / g;
    ans += cnt[need];

    // 对所有约数 d，若 y 是 d 的倍数则计数+1
    for (int d : divisors) {
      if (y % d == 0) {
        cnt[d]++;
      }
    }
  }

  return ans;
}

CountArrayPairsDivisibleByKSolution::CountArrayPairsDivisibleByKSolution() {
  setMetaInfo({.id = 2183,
               .title = "Count Array Pairs Divisible by K",
               .url = "https://leetcode.com/problems/count-array-pairs-divisible-by-k/"});
  registerStrategy(
      {.name = "gcd_and_divisors",
       .expected = "Accepted",
       .time_complexity = "O(n * d(k))",
       .space_complexity = "O(d(k))",
       .tags = {"Array", "Hash Table", "Math", "Counting", "Number Theory"}},
      countPairsImpl);
}

long long CountArrayPairsDivisibleByKSolution::countPairs(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_2183
}  // namespace leetcode
