#include "leetcode/problems/buddy-strings.h"

namespace leetcode {
namespace problem_859 {

namespace {

bool buddyStringsImpl(std::string s, std::string goal) {
  if (s.length() != goal.length()) {
    return false;
  }

  if (s == goal) {
    int count[26] = {0};
    for (char c : s) {
      if (++count[c - 'a'] > 1) {
        return true;
      }
    }
    return false;
  }

  int first = -1, second = -1;
  for (int i = 0; i < static_cast<int>(s.length()); ++i) {
    if (s[i] != goal[i]) {
      if (first == -1) {
        first = i;
      } else if (second == -1) {
        second = i;
      } else {
        return false;  // more than two mismatches
      }
    }
  }

  return second != -1 && s[first] == goal[second] && s[second] == goal[first];
}

}  // namespace

BuddyStringsSolution::BuddyStringsSolution() {
  setMetaInfo({.id = 859,
               .title = "Buddy Strings",
               .url = "https://leetcode.com/problems/buddy-strings/"});

  registerStrategy(
      {.name = "Two Pointers + Counting",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String"}},
      buddyStringsImpl);
}

bool BuddyStringsSolution::buddyStrings(std::string s, std::string goal) {
  return getSolution()(std::move(s), std::move(goal));
}

}  // namespace problem_859
}  // namespace leetcode
