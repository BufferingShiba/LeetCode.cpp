#include "leetcode/problems/lexicographically-smallest-string-after-substring-operation.h"

namespace leetcode::problem_2734 {

namespace {

std::string smallestStringGreedy(std::string s) {
  const int n = static_cast<int>(s.size());
  int start = 0;
  while (start < n && s[start] == 'a') {
    ++start;
  }
  if (start == n) {
    // All characters are 'a'; the only option is to turn the last char into 'z'.
    s[n - 1] = 'z';
    return s;
  }
  // Starting from the first non-'a' char, decrement consecutive chars until a 'a'
  // (which is excluded because 'a' -> 'z' would increase lexicographic order).
  for (int i = start; i < n && s[i] != 'a'; ++i) {
    s[i] = static_cast<char>(s[i] - 1);
  }
  return s;
}

}  // namespace

LexicographicallySmallestStringAfterSubstringOperationSolution::
    LexicographicallySmallestStringAfterSubstringOperationSolution() {
  setMetaInfo({.id = 2734,
               .title =
                   "Lexicographically Smallest String After Substring Operation",
               .url = "https://leetcode.com/problems/"
                      "lexicographically-smallest-string-after-substring-operation/"});
  registerStrategy(
      {.name = "greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Greedy"}},
      smallestStringGreedy);
}

std::string LexicographicallySmallestStringAfterSubstringOperationSolution::
    smallestString(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_2734
