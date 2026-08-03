#include <string>
#include <vector>

#include "leetcode/problems/check-if-digits-are-equal-in-string-after-operations-i.h"

namespace leetcode {
namespace problem_3461 {

namespace {

bool hasSameDigitsImpl(std::string s) {
  std::vector<int> cur;
  cur.reserve(s.size());
  for (char c : s) {
    cur.push_back(c - '0');
  }
  while (cur.size() > 2) {
    std::vector<int> next;
    next.reserve(cur.size() - 1);
    for (size_t i = 0; i + 1 < cur.size(); ++i) {
      next.push_back((cur[i] + cur[i + 1]) % 10);
    }
    cur.swap(next);
  }
  return cur[0] == cur[1];
}

}  // namespace

CheckIfDigitsAreEqualInStringAfterOperationsISolution::
    CheckIfDigitsAreEqualInStringAfterOperationsISolution() {
  setMetaInfo({.id = 3461,
               .title = "Check If Digits Are Equal in String After Operations I",
               .url = "https://leetcode.com/problems/"
                      "check-if-digits-are-equal-in-string-after-operations-i/"});

  registerStrategy(
      {.name = "Simulation",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(n)",
       .tags = {"Math", "String", "Simulation"}},
      hasSameDigitsImpl);
}

bool CheckIfDigitsAreEqualInStringAfterOperationsISolution::hasSameDigits(
    std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_3461
}  // namespace leetcode
