#include "leetcode/problems/first-completely-painted-row-or-column.h"

#include <unordered_map>
#include <vector>

namespace leetcode {
namespace problem_2661 {

namespace {

int firstCompleteIndexImpl(std::vector<int>& arr,
                           std::vector<std::vector<int>>& mat) {
  const int m = static_cast<int>(mat.size());
  const int n = static_cast<int>(mat[0].size());

  // Map each value in mat to its (row, col) position.
  std::unordered_map<int, std::pair<int, int>> pos;
  pos.reserve(static_cast<size_t>(m) * n);
  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      pos[mat[r][c]] = {r, c};
    }
  }

  std::vector<int> rowCount(m, 0);
  std::vector<int> colCount(n, 0);

  for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
    auto it = pos.find(arr[i]);
    const int r = it->second.first;
    const int c = it->second.second;
    if (++rowCount[r] == n || ++colCount[c] == m) {
      return i;
    }
  }

  return static_cast<int>(arr.size()) - 1;
}

}  // namespace

FirstCompletelyPaintedRowOrColumnSolution::
    FirstCompletelyPaintedRowOrColumnSolution() {
  setMetaInfo({.id = 2661,
               .title = "First Completely Painted Row or Column",
               .url =
                   "https://leetcode.com/problems/first-completely-painted-"
                   "row-or-column/"});
  registerStrategy(
      {.name = "hashmap-count",
       .expected = "Accepted",
       .time_complexity = "O(m*n)",
       .space_complexity = "O(m*n)",
       .tags = {"Array", "Hash Table", "Matrix"}},
      firstCompleteIndexImpl);
}

int FirstCompletelyPaintedRowOrColumnSolution::firstCompleteIndex(
    std::vector<int>& arr, std::vector<std::vector<int>>& mat) {
  return getSolution()(arr, mat);
}

}  // namespace problem_2661
}  // namespace leetcode
