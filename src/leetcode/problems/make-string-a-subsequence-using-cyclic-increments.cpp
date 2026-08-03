#include "leetcode/problems/make-string-a-subsequence-using-cyclic-increments.h"

namespace {

bool canMakeSubsequenceImpl(std::string str1, std::string str2) {
  int j = 0;
  int n = static_cast<int>(str1.size());
  int m = static_cast<int>(str2.size());

  for (int i = 0; i < n && j < m; ++i) {
    char c = str1[i];
    char next_c = (c == 'z') ? 'a' : static_cast<char>(c + 1);
    if (c == str2[j] || next_c == str2[j]) {
      ++j;
    }
  }

  return j == m;
}

}  // namespace

namespace leetcode {
namespace problem_2825 {

MakeStringASubsequenceUsingCyclicIncrementsSolution::
    MakeStringASubsequenceUsingCyclicIncrementsSolution() {
  setMetaInfo({.id = 2825,
               .title = "Make String a Subsequence Using Cyclic Increments",
               .url =
                   "https://leetcode.com/problems/make-string-a-subsequence-"
                   "using-cyclic-increments/"});

  registerStrategy(
      {.name = "Two Pointers",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Two Pointers", "String"}},
      canMakeSubsequenceImpl);
}

bool MakeStringASubsequenceUsingCyclicIncrementsSolution::canMakeSubsequence(
    std::string str1, std::string str2) {
  return getSolution()(std::move(str1), std::move(str2));
}

}  // namespace problem_2825
}  // namespace leetcode
