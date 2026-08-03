#include "leetcode/problems/backspace-string-compare.h"

namespace leetcode::problem_844 {

namespace {

bool backspaceCompareImpl(std::string s, std::string t) {
  int i = static_cast<int>(s.size()) - 1;
  int j = static_cast<int>(t.size()) - 1;

  while (i >= 0 || j >= 0) {
    // find next surviving char in s
    int skip = 0;
    while (i >= 0) {
      if (s[i] == '#') {
        ++skip;
        --i;
      } else if (skip > 0) {
        --skip;
        --i;
      } else {
        break;
      }
    }

    // find next surviving char in t
    skip = 0;
    while (j >= 0) {
      if (t[j] == '#') {
        ++skip;
        --j;
      } else if (skip > 0) {
        --skip;
        --j;
      } else {
        break;
      }
    }

    // compare current surviving chars
    if (i >= 0 && j >= 0) {
      if (s[i] != t[j]) return false;
    } else if (i >= 0 || j >= 0) {
      return false;
    }

    --i;
    --j;
  }

  return true;
}

}  // namespace

BackspaceStringCompareSolution::BackspaceStringCompareSolution() {
  setMetaInfo({.id = 844,
               .title = "Backspace String Compare",
               .url = "https://leetcode.com/problems/backspace-string-compare/"});

  registerStrategy(
      {.name = "Two Pointers (O(1) space)",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Two Pointers", "String"}},
      backspaceCompareImpl);

  setDefaultStrategy();
}

}  // namespace leetcode::problem_844
