#include <vector>

#include "leetcode/problems/reverse-string.h"

namespace leetcode {
namespace problem_344 {
namespace {

void reverseStringImpl(std::vector<char>& s) {
  int left = 0;
  int right = static_cast<int>(s.size()) - 1;
  while (left < right) {
    std::swap(s[left], s[right]);
    ++left;
    --right;
  }
}

}  // namespace

ReverseStringSolution::ReverseStringSolution() {
  setMetaInfo({.id = 344,
               .title = "Reverse String",
               .url = "https://leetcode.com/problems/reverse-string/"});
  registerStrategy(
      {.name = "TwoPointers",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Two Pointers", "String"}},
      reverseStringImpl);
}

void ReverseStringSolution::reverseString(std::vector<char>& s) {
  getSolution()(s);
}

}  // namespace problem_344
}  // namespace leetcode
