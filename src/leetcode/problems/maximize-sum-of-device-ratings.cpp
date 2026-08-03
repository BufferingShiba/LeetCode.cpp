#include "leetcode/problems/maximize-sum-of-device-ratings.h"

#include <algorithm>
#include <climits>
#include <map>
#include <vector>

namespace leetcode {
namespace problem_3961 {

namespace {

long long maxRatingsImpl(std::vector<std::vector<int>>& units) {
  int m = units.size();
  long long initial_sum = 0;

  std::map<int, std::vector<long long>> groups;

  for (int i = 0; i < m; ++i) {
    const auto& device = units[i];
    int n = device.size();

    int min_val = INT_MAX;
    int min_count = 0;
    int second_min = INT_MAX;

    for (int val : device) {
      if (val < min_val) {
        second_min = min_val;
        min_val = val;
        min_count = 1;
      } else if (val == min_val) {
        min_count++;
      } else if (val < second_min) {
        second_min = val;
      }
    }

    initial_sum += min_val;

    long long gi = 0;
    if (n >= 2 && min_count == 1) {
      gi = second_min - min_val;
    }

    groups[min_val].push_back(gi);
  }

  std::vector<int> distinct_m;
  for (auto& kv : groups) {
    distinct_m.push_back(kv.first);
  }

  int k = distinct_m.size();
  std::vector<long long> suffix_g(k + 1, 0);

  for (int idx = k - 1; idx >= 0; --idx) {
    int mi = distinct_m[idx];
    long long total_g_for_mi = 0;
    for (long long g : groups[mi]) {
      total_g_for_mi += g;
    }
    suffix_g[idx] = suffix_g[idx + 1] + total_g_for_mi;
  }

  std::vector<long long> F_vals(k);
  for (int idx = 0; idx < k; ++idx) {
    int mi = distinct_m[idx];
    F_vals[idx] = suffix_g[idx] + mi;
  }

  std::vector<long long> prefix_max_F(k);
  long long cur_max = F_vals[0];
  for (int idx = 0; idx < k; ++idx) {
    cur_max = std::max(cur_max, F_vals[idx]);
    prefix_max_F[idx] = cur_max;
  }

  long long best_overall = 0;
  for (int idx = 0; idx < k; ++idx) {
    int L = distinct_m[idx];
    long long max_F = prefix_max_F[idx];

    long long min_g = LLONG_MAX;
    for (long long g : groups[L]) {
      if (g < min_g) min_g = g;
    }

    long long best_for_L = max_F - L - min_g;
    if (best_for_L > best_overall) {
      best_overall = best_for_L;
    }
  }

  return initial_sum + best_overall;
}

}  // namespace

MaximizeSumOfDeviceRatingsSolution::MaximizeSumOfDeviceRatingsSolution() {
  setMetaInfo({.id = 3961,
               .title = "Maximize Sum of Device Ratings",
               .url = "https://leetcode.com/problems/maximize-sum-of-device-ratings/"});
  registerStrategy(
      {.name = "greedy_single_sink",
       .expected = "Accepted",
       .time_complexity = "O(N log m)",
       .space_complexity = "O(m)",
       .tags = {"greedy", "sorting"}},
      maxRatingsImpl);
}

long long MaximizeSumOfDeviceRatingsSolution::maxRatings(
    std::vector<std::vector<int>>& units) {
  return getSolution()(units);
}

}  // namespace problem_3961
}  // namespace leetcode
