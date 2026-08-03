
#include "leetcode/problems/decoded-string-at-index.h"

namespace leetcode {
namespace problem_880 {

using std::string;

// 逆向归约 + 求模：先正向求出达到 k 所需的长度，再逆向用 k %= len 归约定位字符
// 时间复杂度: O(n), 空间复杂度: O(1)
static string solution1(string s, int k) {
  long long len = 0;
  const int n = s.size();

  // 第一遍：正向扫描，计算达到/超过 k 时的解码长度，并记录停止位置
  int i = 0;
  for (; i < n; ++i) {
    char c = s[i];
    if (c >= 'a' && c <= 'z') {
      ++len;
    } else {
      len *= (c - '0');
    }
    if (len >= k) break;
  }

  // 第二遍：从停止位置逆向归约
  for (; i >= 0; --i) {
    char c = s[i];
    if (c >= 'a' && c <= 'z') {
      if (k % len == 0) {
        return string(1, c);
      }
      k %= len;
      --len;
    } else {
      len /= (c - '0');
      k %= len;
    }
  }
  return "";  // 题目保证 k 有效，不会到达这里
}

DecodedStringAtIndexSolution::DecodedStringAtIndexSolution() {
  setMetaInfo({.id = 880,
               .title = "Decoded String at Index",
               .url = "https://leetcode.com/problems/decoded-string-at-index"});
  registerStrategy(
      {.name = "Reverse Reduction + Modulo",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Stack"},
       .notes = "Fast-forward to reach k, then rewind using modulo to locate the k-th char"},
      solution1);
}

std::string DecodedStringAtIndexSolution::decodeAtIndex(std::string s, int k) {
  return getSolution()(s, k);
}

}  // namespace problem_880
}  // namespace leetcode
