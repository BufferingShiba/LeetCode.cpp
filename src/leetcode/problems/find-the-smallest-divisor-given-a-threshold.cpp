#include "leetcode/problems/find-the-smallest-divisor-given-a-threshold.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_1283 {

namespace {

int smallestDivisorImpl(std::vector<int>& nums, int threshold) {
  int left = 1;
  int right = *std::max_element(nums.begin(), nums.end());

  auto computeSum = [&](int divisor) -> long long {
    long long sum = 0;
    for (int x : nums) {
      sum += (x + divisor - 1LL) / divisor;
    }
    return sum;
  };

  while (left < right) {
    int mid = left + (right - left) / 2;
    if (computeSum(mid) <= threshold) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

}  // namespace

FindTheSmallestDivisorGivenAThresholdSolution::FindTheSmallestDivisorGivenAThresholdSolution() {
  setMetaInfo({.id = 1283,
               .title = "Find the Smallest Divisor Given a Threshold",
               .url = "https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/"});

  registerStrategy(
      {.name = "Binary Search",
       .expected = "Accepted",
       .time_complexity = "O(N log M)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Binary Search"}},
      smallestDivisorImpl);
}

int FindTheSmallestDivisorGivenAThresholdSolution::smallestDivisor(std::vector<int>& nums, int threshold) {
  return getSolution()(nums, threshold);
}

}  // namespace leetcode::problem_1283
