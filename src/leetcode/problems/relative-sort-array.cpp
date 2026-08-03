#include "leetcode/problems/relative-sort-array.h"

#include <array>
#include <vector>

namespace leetcode {
namespace problem_1122 {

namespace {

// Counting sort based approach: count occurrences in arr1, then emit in
// arr2 order first, followed by remaining values in ascending order.
std::vector<int> relativeSortArrayImpl(std::vector<int>& arr1,
                                       std::vector<int>& arr2) {
  std::array<int, 1001> count{};
  int maxVal = 0;
  for (int v : arr1) {
    ++count[v];
    if (v > maxVal) maxVal = v;
  }

  std::vector<int> result;
  result.reserve(arr1.size());

  // Emit elements that appear in arr2, in arr2's relative order.
  for (int v : arr2) {
    for (int i = 0; i < count[v]; ++i) {
      result.push_back(v);
    }
    count[v] = 0;
  }

  // Emit remaining elements in ascending order.
  for (int v = 0; v <= maxVal; ++v) {
    for (int i = 0; i < count[v]; ++i) {
      result.push_back(v);
    }
  }

  return result;
}

}  // namespace

RelativeSortArraySolution::RelativeSortArraySolution() {
  setMetaInfo({.id = 1122,
               .title = "Relative Sort Array",
               .url = "https://leetcode.com/problems/relative-sort-array/"});
  registerStrategy(
      {.name = "CountingSort",
       .expected = "Accepted",
       .time_complexity = "O(n + m + maxVal)",
       .space_complexity = "O(maxVal)",
       .tags = {"Array", "Hash Table", "Sorting", "Counting Sort"}},
      relativeSortArrayImpl);
}

std::vector<int> RelativeSortArraySolution::relativeSortArray(
    std::vector<int>& arr1, std::vector<int>& arr2) {
  return getSolution()(arr1, arr2);
}

}  // namespace problem_1122
}  // namespace leetcode
