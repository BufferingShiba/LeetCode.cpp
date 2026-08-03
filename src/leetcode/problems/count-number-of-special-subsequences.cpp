#include "leetcode/problems/count-number-of-special-subsequences.h"

namespace leetcode {
namespace problem_1955 {
namespace {

const long long kMod = 1000000007LL;

// DP 三个状态：
//   z   : 以正数个 0 结尾的子序列数量（尚未出现 1）
//   zo  : 以 [0..1] 结尾的子序列数量（尚未出现 2）
//   zot : 以 [0..1..2] 结尾的特殊子序列数量
int countSpecialSubsequencesImpl(std::vector<int>& nums) {
  long long z = 0, zo = 0, zot = 0;
  for (int x : nums) {
    if (x == 0) {
      // 已有的 0 序列可选/不选当前 0，再加上只含当前 0 的新序列。
      z = (z * 2 + 1) % kMod;
    } else if (x == 1) {
      // 已有的 01 序列可选/不选当前 1，或把当前 1 追加到任一 0 序列。
      zo = (zo * 2 + z) % kMod;
    } else {  // x == 2
      // 已有的特殊序列可选/不选当前 2，或把当前 2 追加到任一 01 序列。
      zot = (zot * 2 + zo) % kMod;
    }
  }
  return static_cast<int>(zot);
}

}  // namespace

CountNumberOfSpecialSubsequencesSolution::CountNumberOfSpecialSubsequencesSolution() {
  setMetaInfo({.id = 1955,
               .title = "Count Number of Special Subsequences",
               .url = "https://leetcode.com/problems/count-number-of-special-subsequences/"});
  registerStrategy({.name = "DP-3States",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Dynamic Programming"},
                    .notes = "三个状态 z/zo/zot 线性扫描统计特殊子序列数量。"},
                   countSpecialSubsequencesImpl);
}

int CountNumberOfSpecialSubsequencesSolution::countSpecialSubsequences(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_1955
}  // namespace leetcode
