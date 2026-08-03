#include "leetcode/problems/largest-palindromic-number.h"

#include <algorithm>
#include <array>
#include <string>

namespace leetcode {
namespace problem_2384 {

namespace {

// 策略：贪心构造最大回文。
// 统计每个数字频次，将能配对的数字从大到小放两侧（左半部分决定数值大小），
// 中间放最大的奇数频次数字。注意处理前导 0。
std::string largestPalindromicImpl(const std::string& num) {
  std::array<int, 10> cnt{};
  for (char c : num) {
    ++cnt[c - '0'];
  }

  std::string left;
  for (int d = 9; d >= 0; --d) {
    // 0 不能在左半部分开头，除非已有非零数字在左半（即 left 非空）
    if (d == 0 && left.empty()) continue;
    int pairs = cnt[d] / 2;
    left.append(pairs, static_cast<char>('0' + d));
  }

  // 中间数字：最大的奇数频次数字
  char middle = 0;
  for (int d = 9; d >= 0; --d) {
    if (cnt[d] % 2 == 1) {
      middle = static_cast<char>('0' + d);
      break;
    }
  }

  if (left.empty()) {
    // 只能用中间数字，保证至少用到一个数字
    return middle == 0 ? std::string("0") : std::string(1, middle);
  }

  std::string right = left;
  std::reverse(right.begin(), right.end());
  if (middle != 0) {
    return left + middle + right;
  }
  return left + right;
}

}  // namespace

LargestPalindromicNumberSolution::LargestPalindromicNumberSolution() {
  this->setMetaInfo({.id = 2384,
                     .title = "Largest Palindromic Number",
                     .url = "https://leetcode.com/problems/largest-palindromic-number/"});
  registerStrategy({.name = "greedy-counting",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Greedy", "Hash Table", "String", "Counting"},
                    .notes = "按数字从大到小放两侧，中间放最大奇数频次数字，处理前导0"},
                   largestPalindromicImpl);
}

std::string LargestPalindromicNumberSolution::largestPalindromic(std::string num) {
  return getSolution()(std::move(num));
}

}  // namespace problem_2384
}  // namespace leetcode
