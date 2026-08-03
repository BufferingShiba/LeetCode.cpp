#include "leetcode/problems/monotone-increasing-digits.h"

namespace leetcode {
namespace problem_738 {

namespace {

int greedy(int n) {
  if (n < 10) return n;
  std::string digits = std::to_string(n);
  int len = static_cast<int>(digits.size());
  int mark = len;  // 第一个递减破坏点的位置（记录最左递减位）
  // 从左到右找到最早且需要修正的递减点
  for (int i = 0; i + 1 < len; ++i) {
    if (digits[i] > digits[i + 1]) {
      mark = i;
      // 向左回溯，处理减1后仍大于前位的情况
      while (mark > 0 && digits[mark] <= digits[mark - 1]) {
        --mark;
      }
      break;
    }
  }
  if (mark == len) return n;  // 本身已满足单调递增
  // digits[mark]--，mark 之后全部置为 '9'
  --digits[mark];
  for (int j = mark + 1; j < len; ++j) {
    digits[j] = '9';
  }
  return std::stoi(digits);
}

}  // namespace

MonotoneIncreasingDigitsSolution::MonotoneIncreasingDigitsSolution() {
  setMetaInfo({.id = 738,
               .title = "Monotone Increasing Digits",
               .url = "https://leetcode.com/problems/monotone-increasing-digits/"});
  registerStrategy(
      {.name = "greedy_scan",
       .expected = "Accepted",
       .time_complexity = "O(d)",  // d 为十进制位数，d <= 10
       .space_complexity = "O(d)",
       .tags = {"Math", "Greedy"},
       .notes = "从左到右找到第一个递减破坏点，将其减1，其后全部置9。"},
      greedy);
}

int MonotoneIncreasingDigitsSolution::monotoneIncreasingDigits(int n) {
  return getSolution()(n);
}

}  // namespace problem_738
}  // namespace leetcode
