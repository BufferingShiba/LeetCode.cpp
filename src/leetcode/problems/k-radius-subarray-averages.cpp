#include "leetcode/problems/k-radius-subarray-averages.h"

#include <vector>

namespace leetcode {
namespace problem_2090 {

namespace {

std::vector<int> getAveragesImpl(std::vector<int>& nums, int k) {
  const int n = static_cast<int>(nums.size());
  std::vector<int> avgs(n, -1);
  if (n < 2 * k + 1) {
    return avgs;
  }
  long long window = 0;
  const long long windowSize = 2LL * k + 1;
  for (int i = 0; i < 2 * k + 1; ++i) {
    window += nums[i];
  }
  avgs[k] = static_cast<int>(window / windowSize);
  for (int i = k + 1; i + k < n; ++i) {
    window += nums[i + k];
    window -= nums[i - k - 1];
    avgs[i] = static_cast<int>(window / windowSize);
  }
  return avgs;
}

}  // namespace

KRadiusSubarrayAveragesSolution::KRadiusSubarrayAveragesSolution() {
  setMetaInfo({.id = 2090,
               .title = "K Radius Subarray Averages",
               .url = "https://leetcode.com/problems/k-radius-subarray-averages/"});
  registerStrategy({.name = "SlidingWindow",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Sliding Window"}},
                   getAveragesImpl);
}

}  // namespace problem_2090
}  // namespace leetcode
