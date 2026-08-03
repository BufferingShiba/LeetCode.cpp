#include "leetcode/problems/find-the-k-th-character-in-string-game-ii.h"

namespace leetcode {
namespace problem_3307 {
namespace {

char kthCharacterImpl(long long k, std::vector<int>& operations) {
  // 第 k 个字符（1-indexed）对应下标 pos = k-1。
  long long pos = k - 1;
  int m = static_cast<int>(operations.size());
  long long shifts = 0;  // 累计需要 +1 的次数
  for (int i = m - 1; i >= 0; --i) {
    // 当 i >= 63 时 2^i 超出 long long 范围，而 pos <= k <= 1e14 < 2^47，
    // 因此 pos 必位于前半，绝不会进入后半分支，直接跳过。
    if (i >= 63) continue;
    long long half = 1LL << i;  // 前半长度 2^i
    if (pos >= half) {
      pos -= half;
      if (operations[i] == 1) ++shifts;
    }
  }
  return static_cast<char>('a' + shifts % 26);
}

}  // namespace

FindTheKThCharacterInStringGameIiSolution::
    FindTheKThCharacterInStringGameIiSolution() {
  setMetaInfo({.id = 3307,
               .title = "Find the K-th Character in String Game II",
               .url =
                   "https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/"});
  registerStrategy(
      {.name = "iterative-bit-backtrack",
       .expected = "Accepted",
       .time_complexity = "O(m)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Bit Manipulation"},
       .notes =
           "Each operation doubles length; walk from the last operation back, "
           "decrementing position into the previous half and accumulating +1 "
           "increments for op==1 steps where the position sits in the upper half."},
      kthCharacterImpl);
}

char FindTheKThCharacterInStringGameIiSolution::kthCharacter(
    long long k, std::vector<int>& operations) {
  return getSolution()(k, operations);
}

}  // namespace problem_3307
}  // namespace leetcode
