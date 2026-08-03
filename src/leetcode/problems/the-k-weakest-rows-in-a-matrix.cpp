#include "leetcode/problems/the-k-weakest-rows-in-a-matrix.h"

#include <algorithm>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_1337 {

namespace {

std::vector<int> kWeakestRowsImpl(std::vector<std::vector<int>>& mat, int k) {
  const int m = static_cast<int>(mat.size());
  std::vector<std::pair<int, int>> rows;  // (soldierCount, rowIndex)
  rows.reserve(m);

  for (int i = 0; i < m; ++i) {
    int soldiers = 0;
    for (int val : mat[i]) {
      soldiers += val;
    }
    rows.emplace_back(soldiers, i);
  }

  std::sort(rows.begin(), rows.end());

  std::vector<int> result;
  result.reserve(k);
  for (int i = 0; i < k; ++i) {
    result.push_back(rows[i].second);
  }
  return result;
}

}  // namespace

TheKWeakestRowsInAMatrixSolution::TheKWeakestRowsInAMatrixSolution() {
  setMetaInfo({1337, "The K Weakest Rows in a Matrix",
               "https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/"});
  registerStrategy(
      {"SortBySoldiers", "Accepted", "O(m log m + m*n)", "O(m)",
       {"Array", "Matrix", "Sorting"}},
      kWeakestRowsImpl);
}

std::vector<int> TheKWeakestRowsInAMatrixSolution::kWeakestRows(
    std::vector<std::vector<int>>& mat, int k) {
  return getSolution()(mat, k);
}

}  // namespace problem_1337
}  // namespace leetcode
