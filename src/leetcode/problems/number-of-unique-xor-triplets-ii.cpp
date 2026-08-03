#include "leetcode/problems/number-of-unique-xor-triplets-ii.h"

#include <algorithm>
#include <vector>

namespace leetcode::problem_3514 {

namespace {

int uniqueXorTripletsImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  if (n == 0) return 0;

  // 找出最大值，确定需要的位数
  int max_val = 0;
  for (int x : nums) {
    if (x > max_val) max_val = x;
  }

  // 计算大于 max_val 的最小 2 的幂，作为数组大小
  int bits = 0;
  while ((1 << bits) <= max_val) ++bits;
  const int size = 1 << bits;  // e.g. 2048 for max_val <= 1500

  // has[x] = true 表示 x 在 nums 中出现过
  std::vector<bool> has(size, false);
  for (int x : nums) {
    has[x] = true;
  }

  // pair_xor[p] = true 表示存在两个元素（可相同）XOR 得到 p
  std::vector<bool> pair_xor(size, false);
  for (int x = 0; x < size; ++x) {
    if (!has[x]) continue;
    for (int y = 0; y < size; ++y) {
      if (!has[y]) continue;
      pair_xor[x ^ y] = true;
    }
  }

  // triple_xor[t] = true 表示存在三个元素 XOR 得到 t
  std::vector<bool> triple_xor(size, false);
  for (int p = 0; p < size; ++p) {
    if (!pair_xor[p]) continue;
    for (int z = 0; z < size; ++z) {
      if (!has[z]) continue;
      triple_xor[p ^ z] = true;
    }
  }

  // 统计不同值数量
  int result = 0;
  for (int t = 0; t < size; ++t) {
    if (triple_xor[t]) ++result;
  }
  return result;
}

}  // namespace

NumberOfUniqueXorTripletsIiSolution::NumberOfUniqueXorTripletsIiSolution() {
  setMetaInfo({.id = 3514,
               .title = "Number of Unique XOR Triplets II",
               .url = "https://leetcode.com/problems/number-of-unique-xor-triplets-ii/"});

  registerStrategy(
      {.name = "XOR Convolution with Boolean Array",
       .expected = "Accepted",
       .time_complexity = "O(V^2)",
       .space_complexity = "O(V)",
       .tags = {"Array", "Math", "Bit Manipulation", "Enumeration"}},
      uniqueXorTripletsImpl);
}

int NumberOfUniqueXorTripletsIiSolution::uniqueXorTriplets(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_3514
