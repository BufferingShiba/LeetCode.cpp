#include "leetcode/problems/minimum-string-length-after-removing-substrings.h"

#include <string>

namespace leetcode::problem_2696 {

namespace {

int minLengthStack(const std::string& s) {
  std::string stack;
  stack.reserve(s.size());
  for (char c : s) {
    stack.push_back(c);
    int n = static_cast<int>(stack.size());
    if (n >= 2) {
      if ((stack[n - 2] == 'A' && stack[n - 1] == 'B') ||
          (stack[n - 2] == 'C' && stack[n - 1] == 'D')) {
        stack.pop_back();
        stack.pop_back();
      }
    }
  }
  return static_cast<int>(stack.size());
}

}  // namespace

MinimumStringLengthAfterRemovingSubstringsSolution::
    MinimumStringLengthAfterRemovingSubstringsSolution() {
  setMetaInfo({.id = 2696,
               .title = "Minimum String Length After Removing Substrings",
               .url =
                   "https://leetcode.com/problems/minimum-string-length-after-removing-substrings/"});

  registerStrategy(
      {.name = "Stack",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"String", "Stack"},
       .notes =
           "Push characters onto a stack; when the top two form AB or CD, pop them."},
      minLengthStack);
}

int MinimumStringLengthAfterRemovingSubstringsSolution::minLength(
    const std::string& s) {
  return getSolution()(s);
}

}  // namespace leetcode::problem_2696
