#include "leetcode/problems/smallest-palindromic-rearrangement-i.h"

#include <algorithm>

namespace leetcode {
namespace problem_3517 {

static string solution1(string s) {
  int cnt[26] = {0};
  for (char c : s) cnt[c - 'a']++;

  string left;
  string mid;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] % 2 == 1) mid.push_back(char('a' + i));
    for (int j = 0; j < cnt[i] / 2; j++) {
      left.push_back(char('a' + i));
    }
  }

  string right = left;
  std::reverse(right.begin(), right.end());
  return left + mid + right;
}

SmallestPalindromicRearrangementISolution::SmallestPalindromicRearrangementISolution() {
  setMetaInfo({
      .id = 3517,
      .title = "Smallest Palindromic Rearrangement I",
      .url = "https://leetcode.com/problems/smallest-palindromic-rearrangement-i"
  });
  registerStrategy({.name = "Greedy Count Construction"}, solution1);
}

string SmallestPalindromicRearrangementISolution::smallestPalindrome(string s) {
  return getSolution()(s);
}

}  // namespace problem_3517
}  // namespace leetcode
