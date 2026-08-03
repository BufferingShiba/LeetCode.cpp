#include "leetcode/problems/binary-trees-with-factors.h"

#include <unordered_map>

namespace leetcode {
namespace problem_823 {

static int solution1(vector<int>& arr) {
  const long long MOD = 1000000007LL;
  std::sort(arr.begin(), arr.end());
  std::unordered_map<int, long long> dp;
  long long total = 0;
  for (size_t i = 0; i < arr.size(); ++i) {
    long long ways = 1;  // the single-node tree [arr[i]]
    for (size_t j = 0; j < i; ++j) {
      int b = arr[j];
      if (arr[i] / (long long)b * b == (long long)arr[i]) {
        long long c = arr[i] / (long long)b;
        auto it = dp.find(static_cast<int>(c));
        if (it != dp.end()) {
          ways = (ways + dp[b] * it->second) % MOD;
        }
      }
    }
    dp[arr[i]] = ways;
    total = (total + ways) % MOD;
  }
  return static_cast<int>(total);
}

BinaryTreesWithFactorsSolution::BinaryTreesWithFactorsSolution() {
  setMetaInfo({
      .id = 823,
      .title = "Binary Trees With Factors",
      .url = "https://leetcode.com/problems/binary-trees-with-factors"
  });
  registerStrategy({.name = "Dynamic Programming (sorted + hashmap)",
                    .time_complexity = "O(n^2)",
                    .space_complexity = "O(n)",
                    .tags = {"Hash Table", "Dynamic Programming", "Sorting"}},
                   solution1);
}

int BinaryTreesWithFactorsSolution::numFactoredBinaryTrees(vector<int>& arr) {
  return getSolution()(arr);
}

}  // namespace problem_823
}  // namespace leetcode
