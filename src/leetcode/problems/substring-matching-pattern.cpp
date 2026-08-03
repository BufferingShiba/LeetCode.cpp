#include "leetcode/problems/substring-matching-pattern.h"

namespace leetcode {
namespace problem_3407 {

static bool solution1(string s, string p) {
  size_t star = p.find('*');
  string prefix = p.substr(0, star);
  string suffix = p.substr(star + 1);

  // Find first occurrence of prefix in s.
  size_t start = s.find(prefix);
  if (start == string::npos) return false;

  // After matching prefix, look for suffix starting from end of prefix.
  size_t suffixStart = s.find(suffix, start + prefix.size());
  return suffixStart != string::npos;
}

SubstringMatchingPatternSolution::SubstringMatchingPatternSolution() {
  setMetaInfo({
      .id = 3407,
      .title = "Substring Matching Pattern",
      .url = "https://leetcode.com/problems/substring-matching-pattern"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

bool SubstringMatchingPatternSolution::hasMatch(string s, string p) {
  return getSolution()(s, p);
}

}  // namespace problem_3407
}  // namespace leetcode
