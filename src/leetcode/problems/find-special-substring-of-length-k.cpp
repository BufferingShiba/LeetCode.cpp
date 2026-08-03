#include "leetcode/problems/find-special-substring-of-length-k.h"

namespace leetcode::problem_3456 {
namespace {

bool hasSpecialSubstringImpl(std::string s, int k) {
  int n = static_cast<int>(s.size());
  int i = 0;
  while (i < n) {
    int j = i;
    while (j < n && s[j] == s[i]) {
      ++j;
    }
    int len = j - i;
    bool leftOk = (i == 0) || (s[i - 1] != s[i]);
    bool rightOk = (j == n) || (s[j] != s[i]);
    if (len == k && leftOk && rightOk) {
      return true;
    }
    i = j;
  }
  return false;
}

}  // namespace

bool FindSpecialSubstringOfLengthKSolution::hasSpecialSubstring(std::string s, int k) {
  return getSolution()(std::move(s), k);
}

FindSpecialSubstringOfLengthKSolution::FindSpecialSubstringOfLengthKSolution() {
  setMetaInfo({.id = 3456,
               .title = "Find Special Substring of Length K",
               .url = "https://leetcode.com/problems/find-special-substring-of-length-k/"});
  registerStrategy({.name = "GroupConsecutive",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"String"}},
                   hasSpecialSubstringImpl);
}

}  // namespace leetcode::problem_3456
