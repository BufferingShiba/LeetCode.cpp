#include "leetcode/problems/is-subsequence.h"

namespace leetcode {
namespace problem_392 {

namespace {

bool isSubsequenceImpl(const std::string& s, const std::string& t) {
  size_t i = 0;
  for (size_t j = 0; j < t.size() && i < s.size(); ++j) {
    if (s[i] == t[j]) {
      ++i;
    }
  }
  return i == s.size();
}

}  // namespace

IsSubsequenceSolution::IsSubsequenceSolution() {
  setMetaInfo({.id = 392,
               .title = "Is Subsequence",
               .url = "https://leetcode.com/problems/is-subsequence/"});
  registerStrategy(
      {"two-pointers-greedy",
       "Accepted",
       "O(n)",
       "O(1)",
       {"Two Pointers", "String"}},
      isSubsequenceImpl);
}

bool IsSubsequenceSolution::isSubsequence(std::string s, std::string t) {
  return getSolution()(std::move(s), std::move(t));
}

}  // namespace problem_392
}  // namespace leetcode
