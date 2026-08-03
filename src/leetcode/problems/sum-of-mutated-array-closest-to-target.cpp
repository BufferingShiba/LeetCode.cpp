#include "leetcode/problems/sum-of-mutated-array-closest-to-target.h"

#include <algorithm>
#include <cstdlib>
#include <limits>

namespace leetcode {
namespace problem_1300 {
namespace {

int findBestValueImpl(std::vector<int>& arr, int target) {
  std::sort(arr.begin(), arr.end());
  int n = static_cast<int>(arr.size());

  // prefix sum
  std::vector<long long> prefix(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + arr[i];
  }

  // sum for a given value v
  auto sumFor = [&](int v) -> long long {
    int idx = static_cast<int>(
        std::upper_bound(arr.begin(), arr.end(), v) - arr.begin());
    return prefix[idx] + static_cast<long long>(v) * (n - idx);
  };

  int lo = 0;
  int hi = arr[n - 1];  // beyond max, every element becomes v

  int best = -1;
  long long bestDiff = std::numeric_limits<long long>::max();

  // Binary search the first v where sumFor(v) >= target
  int left = lo, right = hi;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    long long s = sumFor(mid);
    long long diff = std::llabs(s - target);
    if (diff < bestDiff ||
        (diff == bestDiff && (best == -1 || mid < best))) {
      bestDiff = diff;
      best = mid;
    }
    if (s < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return best;
}

}  // namespace

SumOfMutatedArrayClosestToTargetSolution::
    SumOfMutatedArrayClosestToTargetSolution() {
  setMetaInfo({.id = 1300,
               .title = "Sum of Mutated Array Closest to Target",
               .url = "https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/"});
  registerStrategy(
      {"SortAndBinarySearch", "Accepted", "O(n log n)", "O(n)",
       {"Array", "Binary Search", "Sorting"}},
      findBestValueImpl);
}

int SumOfMutatedArrayClosestToTargetSolution::findBestValue(
    std::vector<int>& arr, int target) {
  return getSolution()(arr, target);
}

}  // namespace problem_1300
}  // namespace leetcode
