#include "leetcode/problems/reverse-string-prefix.h"

namespace leetcode {
namespace problem_3794 {

namespace {

std::string reversePrefixImpl(std::string s, int k) {
  int left = 0;
  int right = k - 1;
  while (left < right) {
    std::swap(s[left], s[right]);
    ++left;
    --right;
  }
  return s;
}

}  // namespace

ReverseStringPrefix::ReverseStringPrefix() {
  setMetaInfo({.id = 3794,
               .title = "Reverse String Prefix",
               .url = "https://leetcode.com/problems/reverse-string-prefix/"});
  registerStrategy(
      {.name = "Two Pointers",
       .expected = "Accepted",
       .time_complexity = "O(k)",
       .space_complexity = "O(1)",
       .tags = {"Two Pointers", "String"}},
      reversePrefixImpl);
}

std::string ReverseStringPrefix::reversePrefix(std::string s, int k) {
  return getSolution()(s, k);
}

}  // namespace problem_3794
}  // namespace leetcode
