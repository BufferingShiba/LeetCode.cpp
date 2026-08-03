#include "leetcode/problems/minimum-time-to-activate-string.h"

namespace leetcode::problem_3639 {

static int minTimeImpl(std::string s, std::vector<int>& order, int k) {
  int n = static_cast<int>(s.size());
  long long total = static_cast<long long>(n) * (n + 1) / 2;

  // If even fully starred we can't reach k, impossible
  if (k > total) return -1;

  // pos_to_time[i] = the time step at which position i becomes '*'
  std::vector<int> pos_to_time(n);
  for (int i = 0; i < n; ++i) {
    pos_to_time[order[i]] = i;
  }

  // Check: at time t, are there >= k valid substrings?
  auto check = [&](int t) -> bool {
    long long invalid = 0;
    long long run = 0;  // current consecutive non-star length
    for (int i = 0; i < n; ++i) {
      if (pos_to_time[i] <= t) {
        // position i is a star -> end of a non-star segment
        invalid += run * (run + 1) / 2;
        run = 0;
      } else {
        ++run;
      }
    }
    // trailing segment
    invalid += run * (run + 1) / 2;
    long long valid = total - invalid;
    return valid >= k;
  };

  int lo = 0, hi = n - 1, ans = -1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (check(mid)) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return ans;
}

MinimumTimeToActivateStringSolution::MinimumTimeToActivateStringSolution() {
  setMetaInfo({.id = 3639,
               .title = "Minimum Time to Activate String",
               .url = "https://leetcode.com/problems/minimum-time-to-activate-string/"});
  registerStrategy(
      {.name = "Binary Search",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Binary Search"}},
      minTimeImpl);
}

int MinimumTimeToActivateStringSolution::minTime(std::string s,
                                                  std::vector<int>& order,
                                                  int k) {
  return getSolution()(s, order, k);
}

}  // namespace leetcode::problem_3639
