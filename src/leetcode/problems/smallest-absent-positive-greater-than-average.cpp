#include "leetcode/problems/smallest-absent-positive-greater-than-average.h"

#include <unordered_set>

namespace leetcode {
namespace problem_3678 {
namespace {

int smallestAbsentImpl(std::vector<int>& nums) {
  std::unordered_set<int> present(nums.begin(), nums.end());
  long long sum = 0;
  int n = static_cast<int>(nums.size());
  for (int x : nums) {
    sum += x;
  }
  // Need smallest positive integer p such that p > avg = sum/n.
  // p > sum/n  <=>  p * n > sum  <=>  p > sum / n.
  int p = static_cast<int>(sum / n) + 1;  // strictly greater
  if (sum > 0 && sum % n == 0) {
    // If sum/n is an integer equal to s, then p = s+1 is correct; already handled.
    // No adjustment needed since +1 already gives strict greater.
  }
  while (p < 1 || present.count(p)) {
    ++p;
  }
  return p;
}

}  // namespace

SmallestAbsentPositiveGreaterThanAverageSolution::
    SmallestAbsentPositiveGreaterThanAverageSolution() {
  setMetaInfo({
      3678,
      "Smallest Absent Positive Greater Than Average",
      "https://leetcode.com/problems/smallest-absent-positive-greater-than-average/",
  });
  registerStrategy(
      {"HashSetLinearScan", "Accepted", "O(n)", "O(n)",
       {"Array", "Hash Table"}},
      smallestAbsentImpl);
}

int SmallestAbsentPositiveGreaterThanAverageSolution::smallestAbsent(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3678
}  // namespace leetcode
