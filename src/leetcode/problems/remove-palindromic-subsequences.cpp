#include "leetcode/problems/remove-palindromic-subsequences.h"

namespace leetcode::problem_1332 {

int removePalindromeSubImpl(const std::string& s) {
  const int n = static_cast<int>(s.size());
  if (n == 0) {
    return 0;
  }
  bool is_palindrome = true;
  for (int i = 0, j = n - 1; i < j; ++i, --j) {
    if (s[i] != s[j]) {
      is_palindrome = false;
      break;
    }
  }
  return is_palindrome ? 1 : 2;
}

RemovePalindromicSubsequencesSolution::RemovePalindromicSubsequencesSolution() {
  setMetaInfo(1332, "Remove Palindromic Subsequences",
              "https://leetcode.com/problems/remove-palindromic-subsequences/");
  registerStrategy(
      {"palindrome-count", "Accepted", "O(n)", "O(1)",
       {"Two Pointers", "String"}, ""},
      removePalindromeSubImpl);
}

int RemovePalindromicSubsequencesSolution::removePalindromeSub(std::string s) {
  return getSolution()(s);
}

}  // namespace leetcode::problem_1332
