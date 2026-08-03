#include "leetcode/problems/identify-the-largest-outlier-in-an-array.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_3371 {

namespace {

constexpr int kMinVal = -1000;
constexpr int kMaxVal = 1000;
constexpr int kRange = kMaxVal - kMinVal + 1;  // 2001

int getLargestOutlierImpl(std::vector<int>& nums) {
  int freq[kRange] = {0};
  int total = 0;

  for (int v : nums) {
    freq[v - kMinVal]++;
    total += v;
  }

  int best = kMinVal - 1;  // sentinel, smaller than any possible value

  for (int y : nums) {
    int x = total - 2 * y;
    // x must be within valid value range to exist in the array
    if (x < kMinVal || x > kMaxVal) {
      continue;
    }
    int idx = x - kMinVal;
    if (freq[idx] == 0) {
      continue;
    }
    // If x and y share the same value, we need at least two occurrences
    if (x == y && freq[idx] < 2) {
      continue;
    }
    if (x > best) {
      best = x;
    }
  }

  return best;
}

}  // namespace

IdentifyTheLargestOutlierInAnArraySolution::IdentifyTheLargestOutlierInAnArraySolution() {
  setMetaInfo({.id = 3371,
               .title = "Identify the Largest Outlier in an Array",
               .url = "https://leetcode.com/problems/identify-the-largest-outlier-in-an-array/"});

  registerStrategy(
      {.name = "FrequencyCounting",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table", "Counting", "Enumeration"}},
      getLargestOutlierImpl);
  setDefaultStrategy();
}

int IdentifyTheLargestOutlierInAnArraySolution::getLargestOutlier(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3371
}  // namespace leetcode
