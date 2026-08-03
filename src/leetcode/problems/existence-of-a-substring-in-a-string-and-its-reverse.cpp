#include "leetcode/problems/existence-of-a-substring-in-a-string-and-its-reverse.h"

#include <string>
#include <unordered_set>

namespace leetcode {
namespace problem_3083 {

namespace {

bool isSubstringPresentImpl(std::string s) {
  int n = static_cast<int>(s.size());
  if (n < 2) {
    return false;
  }
  std::unordered_set<std::string> pairs;
  for (int i = 0; i + 1 < n; ++i) {
    pairs.insert(s.substr(i, 2));
  }
  for (int i = 0; i + 1 < n; ++i) {
    std::string rev;
    rev.push_back(s[i + 1]);
    rev.push_back(s[i]);
    if (pairs.count(rev) > 0) {
      return true;
    }
  }
  return false;
}

}  // namespace

ExistenceOfASubstringInAStringAndItsReverseSolution::
    ExistenceOfASubstringInAStringAndItsReverseSolution() {
  setMetaInfo({.id = 3083,
               .title = "Existence of a Substring in a String and Its Reverse",
               .url = "https://leetcode.com/problems/existence-of-a-substring-in-a-string-and-its-reverse/"});
  registerStrategy(
      {.name = "hash-set-of-adjacent-pairs",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Hash Table", "String"}},
      isSubstringPresentImpl);
}

bool ExistenceOfASubstringInAStringAndItsReverseSolution::
    isSubstringPresent(std::string s) {
  return getSolution()(s);
}

}  // namespace problem_3083
}  // namespace leetcode
