#include "leetcode/problems/count-servers-that-communicate.h"

namespace leetcode {
namespace problem_1267 {
namespace {

int countServersImpl(std::vector<std::vector<int>>& grid) {
  const int m = static_cast<int>(grid.size());
  const int n = static_cast<int>(grid[0].size());

  std::vector<int> rowCnt(m, 0);
  std::vector<int> colCnt(n, 0);

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 1) {
        ++rowCnt[i];
        ++colCnt[j];
      }
    }
  }

  int result = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == 1 && (rowCnt[i] > 1 || colCnt[j] > 1)) {
        ++result;
      }
    }
  }
  return result;
}

}  // namespace

CountServersThatCommunicateSolution::CountServersThatCommunicateSolution() {
  setMetaInfo({.id = 1267,
               .title = "Count Servers that Communicate",
               .url = "https://leetcode.com/problems/count-servers-that-communicate/"});
  registerStrategy({.name = "counting",
                    .expected = "Accepted",
                    .time_complexity = "O(m*n)",
                    .space_complexity = "O(m+n)",
                    .tags = {"Array", "Matrix", "Counting"}},
                   countServersImpl);
}

int CountServersThatCommunicateSolution::countServers(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_1267
}  // namespace leetcode
