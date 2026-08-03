#include "leetcode/problems/number-of-perfect-pairs.h"

#include <algorithm>
#include <cmath>

namespace leetcode {
namespace problem_3649 {

static long perfectPairsImpl(vector<int>& nums) {
  int n = (int)nums.size();
  // For any a, b: {|a-b|, |a+b|} == {|a|+|b|, ||a|-|b||} regardless of signs.
  // So min of the two = ||a|-|b|| and max = |a|+|b|.
  // The second condition |a|+|b| >= max(|a|,|b|) is always true.
  // The first condition becomes: ||a|-|b|| <= min(|a|,|b|)
  //   which (with x=min, y=max) is y-x <= x, i.e. max(|a|,|b|) <= 2*min(|a|,|b|).
  // Count pairs (i<j) satisfying max(abs_i, abs_j) <= 2*min(abs_i, abs_j).
  std::vector<long long> absVals;
  absVals.reserve(n);
  for (int v : nums) absVals.push_back(std::llabs((long long)v));
  std::sort(absVals.begin(), absVals.end());

  long long count = 0;
  for (int i = 0; i < n; ++i) {
    long long x = absVals[i];
    long long limit = 2 * x;
    // j > i such that absVals[j] <= 2*absVals[i]
    auto it = std::upper_bound(absVals.begin(), absVals.end(), limit);
    long long cnt = (long long)(it - absVals.begin()) - (i + 1);
    if (cnt > 0) count += cnt;
  }
  return (long)count;
}

static long solution1(vector<int>& nums) {
  return perfectPairsImpl(nums);
}

NumberOfPerfectPairsSolution::NumberOfPerfectPairsSolution() {
  setMetaInfo({
      .id = 3649,
      .title = "Number of Perfect Pairs",
      .url = "https://leetcode.com/problems/number-of-perfect-pairs/"
  });
  registerStrategy({.name = "Sort + Two Pointer / Binary Search",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(n)",
                    .tags = {"Math", "Sorting", "Binary Search"}},
                   solution1);
}

long NumberOfPerfectPairsSolution::perfectPairs(vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3649
}  // namespace leetcode
