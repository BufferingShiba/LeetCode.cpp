#include "leetcode/problems/find-greatest-common-divisor-of-array.h"

#include <algorithm>

namespace leetcode {
namespace problem_1979 {
namespace {

int gcdImpl(int a, int b) {
  while (b != 0) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int findGCDImpl(std::vector<int>& nums) {
  int mn = *std::min_element(nums.begin(), nums.end());
  int mx = *std::max_element(nums.begin(), nums.end());
  return gcdImpl(mn, mx);
}

}  // namespace

FindGreatestCommonDivisorOfArraySolution::FindGreatestCommonDivisorOfArraySolution() {
  setMetaInfo({.id = 1979,
               .title = "Find Greatest Common Divisor of Array",
               .url = "https://leetcode.com/problems/find-greatest-common-divisor-of-array/"});
  registerStrategy(
      {.name = "MinMaxGCD",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math", "Number Theory"},
       .notes = "Scan for min and max, then Euclidean GCD"},
      findGCDImpl);
}

int FindGreatestCommonDivisorOfArraySolution::findGCD(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_1979
}  // namespace leetcode
