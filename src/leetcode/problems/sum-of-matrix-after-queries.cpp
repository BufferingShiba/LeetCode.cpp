#include "leetcode/problems/sum-of-matrix-after-queries.h"

#include <vector>

namespace leetcode::problem_2718 {

namespace {

long long matrixSumQueriesImpl(int n, std::vector<std::vector<int>>& queries) {
  std::vector<bool> row_seen(n, false);
  std::vector<bool> col_seen(n, false);
  int row_count = 0;
  int col_count = 0;
  long long total = 0;

  for (int i = static_cast<int>(queries.size()) - 1; i >= 0; --i) {
    int type = queries[i][0];
    int index = queries[i][1];
    int val = queries[i][2];

    if (type == 0) {  // row operation
      if (row_seen[index]) continue;
      total += static_cast<long long>(val) * (n - col_count);
      row_seen[index] = true;
      ++row_count;
    } else {  // column operation
      if (col_seen[index]) continue;
      total += static_cast<long long>(val) * (n - row_count);
      col_seen[index] = true;
      ++col_count;
    }
  }

  return total;
}

}  // namespace

SumOfMatrixAfterQueriesSolution::SumOfMatrixAfterQueriesSolution() {
  setMetaInfo({.id = 2718,
               .title = "Sum of Matrix After Queries",
               .url = "https://leetcode.com/problems/sum-of-matrix-after-queries/"});
  registerStrategy({.name = "reverse-traversal",
                    .expected = "Accepted",
                    .time_complexity = "O(n + q)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Hash Table", "Greedy"}},
                   matrixSumQueriesImpl);
  setDefaultStrategy();
}

long long SumOfMatrixAfterQueriesSolution::matrixSumQueries(
    int n, std::vector<std::vector<int>>& queries) {
  return getSolution()(n, queries);
}

}  // namespace leetcode::problem_2718
