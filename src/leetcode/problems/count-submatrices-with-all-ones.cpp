#include "leetcode/problems/count-submatrices-with-all-ones.h"

#include <stack>
#include <utility>

namespace leetcode {
namespace problem_1504 {
namespace {

// For each row treated as the bottom, compute a histogram h[] where h[j]
// is the number of consecutive 1s ending at (row, j) going upward.
// Then count the number of all-ones submatrices whose bottom row is `row`
// using a monotonic increasing stack over histogram heights.
int numSubmatImpl(std::vector<std::vector<int>>& mat) {
  const int m = static_cast<int>(mat.size());
  if (m == 0) return 0;
  const int n = static_cast<int>(mat[0].size());

  std::vector<int> h(n, 0);
  int total = 0;

  for (int i = 0; i < m; ++i) {
    // Update histogram heights for the current row.
    for (int j = 0; j < n; ++j) {
      h[j] = (mat[i][j] == 1) ? h[j] + 1 : 0;
    }

    // Monotonic increasing stack storing (height, count) pairs.
    // For a given height, `count` is the number of submatrices (within the
    // histogram) whose width ends at the current column being processed.
    std::stack<std::pair<int, int>> st;
    int cur = 0;  // running count for the current row
    for (int j = 0; j < n; ++j) {
      int count = 1;  // width = 1 for the new element
      while (!st.empty() && st.top().first >= h[j]) {
        cur -= st.top().second * st.top().first;  // remove contribution
        count += st.top().second;                 // extend width
        st.pop();
      }
      st.push({h[j], count});
      cur += h[j] * count;
      total += cur;
    }
  }

  return total;
}

}  // namespace

CountSubmatricesWithAllOnesSolution::CountSubmatricesWithAllOnesSolution() {
  setMetaInfo({.id = 1504,
               .title = "Count Submatrices With All Ones",
               .url = "https://leetcode.com/problems/count-submatrices-with-all-ones/"});
  registerStrategy({.name = "MonotonicStack",
                    .expected = "Accepted",
                    .time_complexity = "O(m * n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Dynamic Programming", "Monotonic Stack", "Matrix"}},
                   numSubmatImpl);
}

int CountSubmatricesWithAllOnesSolution::numSubmat(std::vector<std::vector<int>>& mat) {
  return getSolution()(mat);
}

}  // namespace problem_1504
}  // namespace leetcode
