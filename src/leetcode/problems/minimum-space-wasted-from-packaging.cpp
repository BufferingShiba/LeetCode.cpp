#include "leetcode/problems/minimum-space-wasted-from-packaging.h"

#include <algorithm>
#include <cstdint>

namespace leetcode {
namespace problem_1889 {
namespace {

constexpr long long kMod = 1000000007LL;

int minWastedSpaceImpl(std::vector<int>& packages,
                       std::vector<std::vector<int>>& boxes) {
  std::sort(packages.begin(), packages.end());
  const int n = static_cast<int>(packages.size());

  std::vector<long long> prefix(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + packages[i];
  }

  long long totalWaste = -1;
  long long totalSize = prefix[n];

  for (std::vector<int>& supplierBoxes : boxes) {
    std::sort(supplierBoxes.begin(), supplierBoxes.end());

    // This supplier's largest box must cover the largest package.
    if (supplierBoxes.back() < packages.back()) {
      continue;
    }

    long long waste = 0;
    int prevIndex = 0;  // packages [0, prevIndex) already assigned
    for (int boxSize : supplierBoxes) {
      // Find first package with size > boxSize.
      int nextIndex = static_cast<int>(
          std::upper_bound(packages.begin(), packages.end(), boxSize) -
          packages.begin());
      int count = nextIndex - prevIndex;
      if (count <= 0) {
        continue;
      }
      long long packageSum = prefix[nextIndex] - prefix[prevIndex];
      waste += static_cast<long long>(boxSize) * count - packageSum;
      prevIndex = nextIndex;
    }
    // prevIndex must reach n for a valid supplier.
    if (prevIndex == n && (totalWaste == -1 || waste < totalWaste)) {
      totalWaste = waste;
    }
  }

  if (totalWaste == -1) {
    return -1;
  }
  return static_cast<int>(totalWaste % kMod);
}

}  // namespace

MinimumSpaceWastedFromPackagingSolution::MinimumSpaceWastedFromPackagingSolution() {
  setMetaInfo({.id = 1889,
               .title = "Minimum Space Wasted From Packaging",
               .url = "https://leetcode.com/problems/minimum-space-wasted-from-packaging/"});

  registerStrategy({.name = "sorting_binary_search_prefix_sum",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n + sum(boxes[j].length) log n)",
                    .space_complexity = "O(n)",
                    .tags = {"Binary Search", "Sorting", "Prefix Sum"}},
                   minWastedSpaceImpl);
}

int MinimumSpaceWastedFromPackagingSolution::minWastedSpace(
    std::vector<int>& packages, std::vector<std::vector<int>>& boxes) {
  return getSolution()(packages, boxes);
}

}  // namespace problem_1889
}  // namespace leetcode
