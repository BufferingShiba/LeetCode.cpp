#include "leetcode/problems/find-nth-smallest-integer-with-k-one-bits.h"

#include <array>

namespace leetcode::problem_3821 {
namespace {

// 组合数表。答案 <2^50，最高位 p 不会超过 49，但保险算到 61。
constexpr int kMaxBits = 61;
std::array<std::array<long long, kMaxBits + 1>, kMaxBits + 1> g_choose{};
bool g_init = false;

void InitCombinatorics() {
  if (g_init) return;
  for (int i = 0; i <= kMaxBits; ++i) {
    g_choose[i][0] = 1;
    g_choose[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      g_choose[i][j] = g_choose[i - 1][j - 1] + g_choose[i - 1][j];
    }
  }
  g_init = true;
}

long long nthSmallestImpl(long long n, int k) {
  if (k == 1) {
    // 恰好 1 个 1 的第 n 小的数就是 1 << (n - 1)。
    return 1LL << (n - 1);
  }
  InitCombinatorics();
  // 最高有效位为 p 时，低位 p 个位置任选 k-1 个放 1，
  // 共 C(p, k-1) 个。数字从小到大对应 p 从低到高累计。
  for (int p = k - 1; ; ++p) {
    long long count = g_choose[p][k - 1];
    if (n > count) {
      n -= count;
    } else {
      // 最高有效位在 p，低 p 位取第 n 个恰有 (k-1) 个 1 的数。
      return (1LL << p) | nthSmallestImpl(n, k - 1);
    }
  }
}

}  // namespace

FindNthSmallestIntegerWithKOneBitsSolution::FindNthSmallestIntegerWithKOneBitsSolution() {
  setMetaInfo({
      .id = 3821,
      .title = "Find Nth Smallest Integer With K One Bits",
      .url = "https://leetcode.com/problems/find-nth-smallest-integer-with-k-one-bits/",
  });
  registerStrategy({.name = "unranking_with_combinatorics",
                    .expected = "Accepted",
                    .time_complexity = "O(k * B) where B<=61, k<=50",
                    .space_complexity = "O(B^2)",
                    .tags = {"Math", "Bit Manipulation", "Combinatorics"}},
                   [](long long n, int k) { return nthSmallestImpl(n, k); });
}

long long FindNthSmallestIntegerWithKOneBitsSolution::nthSmallest(long long n, int k) {
  return getSolution()(n, k);
}

}  // namespace leetcode::problem_3821
