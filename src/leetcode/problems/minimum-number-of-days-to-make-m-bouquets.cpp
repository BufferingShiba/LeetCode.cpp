#include "leetcode/problems/minimum-number-of-days-to-make-m-bouquets.h"

#include <algorithm>
#include <cstdint>

namespace leetcode {
namespace problem_1482 {
namespace {

// Feasibility check: can we make at least m bouquets of k adjacent flowers
// by day d? A flower i is available iff bloomDay[i] <= d. Count the max
// number of bouquets by scanning contiguous bloomed segments: each segment
// of length len contributes len / k bouquets.
bool CanMakeBouquets(const std::vector<int>& bloomDay, int d, long long m,
                     int k) {
  long long bouquets = 0;
  int run = 0;
  for (int day : bloomDay) {
    if (day <= d) {
      ++run;
      if (run == k) {
        ++bouquets;
        run = 0;
        if (bouquets >= m) return true;
      }
    } else {
      run = 0;
    }
  }
  return bouquets >= m;
}

int MinDaysImpl(std::vector<int>& bloomDay, int m, int k) {
  const long long n = static_cast<long long>(bloomDay.size());
  const long long mk = static_cast<long long>(m) * k;
  if (mk > n) return -1;

  const int lo = 1;
  const int hi = *std::max_element(bloomDay.begin(), bloomDay.end());
  int left = lo, right = hi;
  while (left < right) {
    const int mid = left + (right - left) / 2;
    if (CanMakeBouquets(bloomDay, mid, m, k)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

}  // namespace

MinimumNumberOfDaysToMakeMBouquetsSolution::MinimumNumberOfDaysToMakeMBouquetsSolution() {
  setMetaInfo({1482,
               "Minimum Number of Days to Make m Bouquets",
               "https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/"});
  registerStrategy(
      {"BinarySearch", "Accepted", "O(n log(maxDay))", "O(1)",
       {"Array", "Binary Search"}},
      MinDaysImpl);
}

int MinimumNumberOfDaysToMakeMBouquetsSolution::minDays(std::vector<int>& bloomDay,
                                                       int m, int k) {
  return getSolution()(bloomDay, m, k);
}

}  // namespace problem_1482
}  // namespace leetcode
