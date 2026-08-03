#include "leetcode/problems/minimum-xor-path-in-a-grid.h"
#include <array>
#include <cstdint>

namespace leetcode::problem_3882 {

namespace {

constexpr int kMaxXor = 1024;  // grid values < 2^10, so XOR stays < 2^10.
// A cell's reachable XOR set is a 1024-bit bitmap stored as BW words.
constexpr int kBits = 1024;
constexpr int kWordBits = 32;
constexpr int kW = kBits / kWordBits;  // 32 words per cell

int minCostImpl(std::vector<std::vector<int>>& grid) {
  int m = static_cast<int>(grid.size());
  int n = static_cast<int>(grid[0].size());

  // reachable as a flat bit array: cell id = i*n + j, each cell uses kW words.
  std::vector<uint32_t> bits(static_cast<size_t>(m) * n * kW, 0u);

  auto cellPtr = [&](int i, int j) {
    return bits.data() + static_cast<size_t>(i) * n * kW + static_cast<size_t>(j) * kW;
  };

  auto setBit = [&](int i, int j, int x) {
    uint32_t* p = cellPtr(i, j);
    p[x >> 5] |= (1u << (x & 31));
  };
  auto hasBit = [&](const uint32_t* p, int x) {
    return (p[x >> 5] >> (x & 31)) & 1u;
  };

  setBit(0, 0, grid[0][0]);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == 0 && j == 0) continue;
      int val = grid[i][j];
      uint32_t* cur = cellPtr(i, j);
      auto absorbFrom = [&](const uint32_t* src) {
        for (int b = 0; b < kBits; ++b) {
          if (hasBit(src, b)) cur[(b ^ val) >> 5] |= (1u << ((b ^ val) & 31));
        }
      };
      if (i > 0) absorbFrom(cellPtr(i - 1, j));
      if (j > 0) absorbFrom(cellPtr(i, j - 1));
    }
  }

  const uint32_t* last = cellPtr(m - 1, n - 1);
  for (int x = 0; x < kMaxXor; ++x) {
    if (hasBit(last, x)) return x;
  }
  return -1;  // Unreachable for a valid grid.
}

}  // namespace

MinimumXorPathInAGridSolution::MinimumXorPathInAGridSolution() {
  setMetaInfo({.id = 3882,
               .title = "Minimum XOR Path in a Grid",
               .url = "https://leetcode.com/problems/minimum-xor-path-in-a-grid/"});
  registerStrategy(
      {.name = "dp-bitset",
       .expected = "Accepted",
       .time_complexity = "O(m * n * 1024)",
       .space_complexity = "O(m * n * 1024)",
       .tags = {"Dynamic Programming", "Bit Manipulation", "Matrix"}},
      minCostImpl);
}

int MinimumXorPathInAGridSolution::minCost(std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace leetcode::problem_3882
