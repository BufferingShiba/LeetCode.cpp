#include "leetcode/problems/construct-product-matrix.h"

namespace leetcode {
namespace problem_2906 {

namespace {

constexpr int kMod = 12345;

// 前缀 + 后缀乘积：展平为一维，
// p[i] = (prefix_before * suffix_after) % MOD
std::vector<std::vector<int>> constructProductMatrixImpl(
    std::vector<std::vector<int>>& grid) {
  const int n = static_cast<int>(grid.size());
  const int m = static_cast<int>(grid[0].size());
  const int total = n * m;

  // 展平
  std::vector<int> flat;
  flat.reserve(total);
  for (const auto& row : grid) {
    for (int v : row) {
      flat.push_back(v);
    }
  }

  // prefix[k] = 索引 [0, k-1] 范围内元素的乘积 mod MOD
  std::vector<int> prefix(total + 1, 1);
  for (int k = 0; k < total; ++k) {
    prefix[k + 1] = static_cast<long long>(prefix[k]) * flat[k] % kMod;
  }

  std::vector<std::vector<int>> result(n, std::vector<int>(m, 1));
  long long suffix = 1;  // 已累积的后缀乘积 mod MOD
  for (int k = total - 1; k >= 0; --k) {
    long long val = static_cast<long long>(prefix[k]) * suffix % kMod;
    result[k / m][k % m] = static_cast<int>(val);
    suffix = suffix * flat[k] % kMod;
  }

  return result;
}

}  // namespace

ConstructProductMatrixSolution::ConstructProductMatrixSolution() {
  setMetaInfo({.id = 2906,
               .title = "Construct Product Matrix",
               .url =
                   "https://leetcode.com/problems/construct-product-matrix/"});
  registerStrategy(
      {.name = "prefix-suffix-product",
       .expected = "Accepted",
       .time_complexity = "O(n*m)",
       .space_complexity = "O(n*m)",
       .tags = {"Array", "Matrix", "Prefix Sum"}},
      constructProductMatrixImpl);
}

std::vector<std::vector<int>> ConstructProductMatrixSolution::
constructProductMatrix(std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_2906
}  // namespace leetcode
