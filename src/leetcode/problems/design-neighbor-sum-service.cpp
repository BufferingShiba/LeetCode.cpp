#include "leetcode/problems/design-neighbor-sum-service.h"

namespace leetcode::problem_3242 {

NeighborSum::NeighborSum(std::vector<std::vector<int>>& grid) : grid_(grid) {
  int n = static_cast<int>(grid.size());
  pos_.resize(n * n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      pos_[grid[i][j]] = {i, j};
    }
  }
}

int NeighborSum::adjacentSum(int value) {
  auto [r, c] = pos_[value];
  int n = static_cast<int>(grid_.size());
  int sum = 0;
  if (r > 0) sum += grid_[r - 1][c];
  if (r + 1 < n) sum += grid_[r + 1][c];
  if (c > 0) sum += grid_[r][c - 1];
  if (c + 1 < n) sum += grid_[r][c + 1];
  return sum;
}

int NeighborSum::diagonalSum(int value) {
  auto [r, c] = pos_[value];
  int n = static_cast<int>(grid_.size());
  int sum = 0;
  if (r > 0 && c > 0) sum += grid_[r - 1][c - 1];
  if (r > 0 && c + 1 < n) sum += grid_[r - 1][c + 1];
  if (r + 1 < n && c > 0) sum += grid_[r + 1][c - 1];
  if (r + 1 < n && c + 1 < n) sum += grid_[r + 1][c + 1];
  return sum;
}

}  // namespace leetcode::problem_3242
