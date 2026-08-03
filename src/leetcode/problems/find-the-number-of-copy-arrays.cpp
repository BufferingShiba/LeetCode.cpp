#include "leetcode/problems/find-the-number-of-copy-arrays.h"

#include <algorithm>
#include <climits>

namespace leetcode {
namespace problem_3468 {

namespace {

int countArraysImpl(std::vector<int>& original, std::vector<std::vector<int>>& bounds) {
  int d_min = INT_MIN;
  int d_max = INT_MAX;
  const int n = static_cast<int>(original.size());

  for (int i = 0; i < n; ++i) {
    long long low = static_cast<long long>(bounds[i][0]) - original[i];
    long long high = static_cast<long long>(bounds[i][1]) - original[i];

    if (low > d_min) {
      d_min = static_cast<int>(low);
    }
    if (high < d_max) {
      d_max = static_cast<int>(high);
    }

    if (d_min > d_max) {
      return 0;
    }
  }

  return d_max - d_min + 1;
}

}  // namespace

FindTheNumberOfCopyArraysSolution::FindTheNumberOfCopyArraysSolution() {
  setMetaInfo({.id = 3468,
               .title = "Find the Number of Copy Arrays",
               .url = "https://leetcode.com/problems/find-the-number-of-copy-arrays/"});

  registerStrategy(
      {.name = "Intersection of Offsets",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math"}},
      countArraysImpl);

  setDefaultStrategy();
}

int FindTheNumberOfCopyArraysSolution::countArrays(
    std::vector<int>& original,
    std::vector<std::vector<int>>& bounds) {
  return getSolution()(original, bounds);
}

}  // namespace problem_3468
}  // namespace leetcode
