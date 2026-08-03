#include "leetcode/problems/three-equal-parts.h"

namespace leetcode {
namespace problem_927 {

static std::vector<int> threeEqualPartsImpl(std::vector<int>& arr) {
  int n = static_cast<int>(arr.size());

  // Count total ones
  int total_ones = 0;
  for (int x : arr) {
    if (x == 1) ++total_ones;
  }

  // All zeros: any split works; return [0, 2] (n >= 3 guaranteed)
  if (total_ones == 0) {
    return {0, 2};
  }

  // Must be divisible by 3
  if (total_ones % 3 != 0) {
    return {-1, -1};
  }

  int k = total_ones / 3;

  // Locate the first 1 of each part
  int first1 = -1, start2 = -1, start3 = -1;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] == 1) {
      ++cnt;
      if (cnt == 1)        first1 = i;
      if (cnt == k + 1)    start2 = i;
      if (cnt == 2 * k + 1) start3 = i;
    }
  }

  // The pattern length is determined by the third part (from start3 to end)
  int len = n - start3;

  // Verify that the three patterns match
  for (int t = 0; t < len; ++t) {
    if (arr[first1 + t] != arr[start3 + t] ||
        arr[start2 + t] != arr[start3 + t]) {
      return {-1, -1};
    }
  }

  int i = first1 + len - 1;
  int j = start2 + len;

  // The problem requires i + 1 < j (non-empty second part)
  if (i + 1 >= j) {
    return {-1, -1};
  }

  return {i, j};
}

ThreeEqualPartsSolution::ThreeEqualPartsSolution() {
  setMetaInfo({.id = 927,
               .title = "Three Equal Parts",
               .url = "https://leetcode.com/problems/three-equal-parts/"});
  registerStrategy(
      {.name = "CountOnes",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math"}},
      threeEqualPartsImpl);
}

std::vector<int> ThreeEqualPartsSolution::threeEqualParts(std::vector<int>& arr) {
  return getSolution()(arr);
}

}  // namespace problem_927
}  // namespace leetcode
