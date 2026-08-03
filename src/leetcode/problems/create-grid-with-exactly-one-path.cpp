#include "leetcode/problems/create-grid-with-exactly-one-path.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_3963 {

namespace {

// 构造唯一路径：第一列全为 '.'，最后一行（除第一列）全为 '.'，其余为 '#'。
// 这样任何路径都只能沿第一列向下，然后在 (m-1, 0) 处右转沿最后一行到底。
std::vector<std::string> createGridWithExactlyOnePathImpl(int m, int n) {
  std::vector<std::string> grid(m, std::string(n, '#'));
  for (int i = 0; i < m; ++i) {
    grid[i][0] = '.';  // 第一列自由
  }
  for (int j = 0; j < n; ++j) {
    grid[m - 1][j] = '.';  // 最后一行自由
  }
  return grid;
}

}  // namespace

CreateGridWithExactlyOnePathSolution::CreateGridWithExactlyOnePathSolution() {
  setMetaInfo({.id = 3963,
               .title = "Create Grid With Exactly One Path",
               .url = "https://leetcode.com/problems/create-grid-with-exactly-one-path/"});

  registerStrategy({.name = "SingleCorridor",
                    .expected = "Accepted",
                    .time_complexity = "O(m * n)",
                    .space_complexity = "O(m * n)",
                    .tags = {"Greedy", "Constructive"}},
                   createGridWithExactlyOnePathImpl);
}

std::vector<std::string> CreateGridWithExactlyOnePathSolution::createGrid(int m, int n) {
  return getSolution()(m, n);
}

}  // namespace problem_3963
}  // namespace leetcode
