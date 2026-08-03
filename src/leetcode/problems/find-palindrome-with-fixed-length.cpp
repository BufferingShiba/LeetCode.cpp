#include "leetcode/problems/find-palindrome-with-fixed-length.h"

#include <cmath>

namespace leetcode {
namespace problem_2217 {

namespace {

std::vector<long long> kthPalindromeImpl(std::vector<int>& queries, int intLength) {
  const int half_len = (intLength + 1) / 2;
  const long long start = static_cast<long long>(std::pow(10, half_len - 1));
  const long long count = 9LL * static_cast<long long>(std::pow(10, half_len - 1));

  std::vector<long long> result;
  result.reserve(queries.size());

  for (int q : queries) {
    if (q > count) {
      result.push_back(-1);
      continue;
    }
    const long long left = start + q - 1;  // 前半部分（含中间位）
    std::string s = std::to_string(left);
    int len = static_cast<int>(s.size());
    // 拼上后半部分（如果总长是偶数，前半部分直接反转；奇数则去掉中间字符再反转）
    std::string palindrome = s;
    int mirror_start = (intLength % 2 == 0) ? len : len - 1;
    for (int i = mirror_start - 1; i >= 0; --i) {
      palindrome.push_back(s[i]);
    }
    result.push_back(std::stoll(palindrome));
  }

  return result;
}

}  // namespace

FindPalindromeWithFixedLengthSolution::FindPalindromeWithFixedLengthSolution() {
  setMetaInfo({.id = 2217,
               .title = "Find Palindrome With Fixed Length",
               .url =
                   "https://leetcode.com/problems/find-palindrome-with-fixed-length/"});
  registerStrategy({.name = "math-construction",
                    .expected = "Accepted",
                    .time_complexity = "O(N * intLength)",
                    .space_complexity = "O(1) (excluding output)",
                    .tags = {"Array", "Math"}},
                   kthPalindromeImpl);
}

std::vector<long long> FindPalindromeWithFixedLengthSolution::kthPalindrome(
    std::vector<int>& queries, int intLength) {
  return getSolution()(queries, intLength);
}

}  // namespace problem_2217
}  // namespace leetcode
