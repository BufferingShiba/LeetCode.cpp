#include "leetcode/problems/make-lexicographically-smallest-array-by-swapping-elements.h"

#include <algorithm>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_2948 {

namespace {

std::vector<int> lexicographicallySmallestArrayImpl(std::vector<int>& nums,
                                                    int limit) {
  const int n = static_cast<int>(nums.size());
  std::vector<std::pair<int, int>> indexed;  // (value, index)
  indexed.reserve(n);
  for (int i = 0; i < n; ++i) {
    indexed.emplace_back(nums[i], i);
  }
  std::sort(indexed.begin(), indexed.end());

  std::vector<int> result(nums);
  std::vector<int> groupIndices;

  int start = 0;
  for (int i = 0; i < n; ++i) {
    bool boundary = (i == n - 1) ||
                    (indexed[i + 1].first - indexed[i].first > limit);
    if (!boundary) {
      continue;
    }
    // Group is indexed[start..i] (inclusive) in sorted order.
    groupIndices.clear();
    groupIndices.reserve(i - start + 1);
    for (int k = start; k <= i; ++k) {
      groupIndices.push_back(indexed[k].second);
    }
    std::sort(groupIndices.begin(), groupIndices.end());
    // Values indexed[start..i] are already sorted ascending.
    for (size_t k = 0; k < groupIndices.size(); ++k) {
      result[groupIndices[k]] = indexed[start + static_cast<int>(k)].first;
    }
    start = i + 1;
  }

  return result;
}

}  // namespace

MakeLexicographicallySmallestArrayBySwappingElementsSolution::
    MakeLexicographicallySmallestArrayBySwappingElementsSolution() {
  setMetaInfo({.id = 2948,
               .title =
                   "Make Lexicographically Smallest Array by Swapping Elements",
               .url =
                   "https://leetcode.com/problems/make-"
                   "lexicographically-smallest-array-by-swapping-elements/"});
  registerStrategy(
      {.name = "sorting-pairing",
       .expected = "Accepted",
       .time_complexity = "O(n log n)",
       .space_complexity = "O(n)",
       .tags = {"Sorting", "Greedy"},
       .notes =
           "Sort values with their indices, partition into groups where "
           "adjacent sorted values differ by <= limit, then in each group "
           "assign ascending values to ascending indices."},
      lexicographicallySmallestArrayImpl);
}

std::vector<int>
MakeLexicographicallySmallestArrayBySwappingElementsSolution::
    lexicographicallySmallestArray(std::vector<int>& nums, int limit) {
  return getSolution()(nums, limit);
}

}  // namespace problem_2948
}  // namespace leetcode
