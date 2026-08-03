#include "leetcode/problems/max-pair-sum-in-an-array.h"

#include <algorithm>

namespace leetcode {
namespace problem_2815 {

namespace {

int maxDigit(int x) {
  int d = 0;
  while (x > 0) {
    d = std::max(d, x % 10);
    x /= 10;
  }
  return d;
}

int maxSumImpl(std::vector<int>& nums) {
  int top[10] = {0};
  int second[10] = {0};
  for (int x : nums) {
    int d = maxDigit(x);
    if (x > top[d]) {
      second[d] = top[d];
      top[d] = x;
    } else if (x > second[d]) {
      second[d] = x;
    }
  }
  int best = -1;
  for (int d = 0; d < 10; ++d) {
    if (second[d] > 0) {
      best = std::max(best, top[d] + second[d]);
    }
  }
  return best;
}

}  // namespace

MaxPairSumInAnArraySolution::MaxPairSumInAnArraySolution() {
  setMetaInfo({.id = 2815, .title = "Max Pair Sum in an Array", .url = "https://leetcode.com/problems/max-pair-sum-in-an-array/"});
  registerStrategy(
      {.name = "hash-by-max-digit", .expected = "Accepted",
       .time_complexity = "O(n)", .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table"}},
      maxSumImpl);
}

int MaxPairSumInAnArraySolution::maxSum(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2815
}  // namespace leetcode
