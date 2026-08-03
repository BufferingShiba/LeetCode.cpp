#include "leetcode/problems/valid-palindrome.h"

#include <cctype>

namespace leetcode {
namespace problem_125 {

namespace {

bool isPalindromeImpl(std::string s) {
  if (s.empty()) {
    return true;
  }

  int left = 0;
  int right = static_cast<int>(s.size()) - 1;

  while (left < right) {
    // 跳过左侧非字母数字字符
    while (left < right && !std::isalnum(static_cast<unsigned char>(s[left]))) {
      ++left;
    }
    // 跳过右侧非字母数字字符
    while (left < right && !std::isalnum(static_cast<unsigned char>(s[right]))) {
      --right;
    }

    // 统一转小写比较
    if (std::tolower(static_cast<unsigned char>(s[left])) !=
        std::tolower(static_cast<unsigned char>(s[right]))) {
      return false;
    }

    ++left;
    --right;
  }

  return true;
}

}  // namespace

ValidPalindromeSolution::ValidPalindromeSolution() {
  setMetaInfo({.id = 125,
               .title = "Valid Palindrome",
               .url = "https://leetcode.com/problems/valid-palindrome/"});
  registerStrategy(
      {.name = "Two Pointers",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Two Pointers", "String"}},
      isPalindromeImpl);
}

bool ValidPalindromeSolution::isPalindrome(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_125
}  // namespace leetcode
