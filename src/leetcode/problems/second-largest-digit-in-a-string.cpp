#include "leetcode/problems/second-largest-digit-in-a-string.h"

namespace leetcode {
namespace problem_1796 {

namespace {

int secondHighestImpl(std::string s) {
  int largest = -1;
  int secondLargest = -1;

  for (char c : s) {
    if (c >= '0' && c <= '9') {
      int digit = c - '0';
      if (digit > largest) {
        secondLargest = largest;
        largest = digit;
      } else if (digit < largest && digit > secondLargest) {
        secondLargest = digit;
      }
    }
  }

  return secondLargest;
}

}  // namespace

SecondLargestDigitInAStringSolution::SecondLargestDigitInAStringSolution() {
  setMetaInfo({.id = 1796,
               .title = "Second Largest Digit in a String",
               .url = "https://leetcode.com/problems/second-largest-digit-in-a-string/"});

  registerStrategy(
      {.name = "OnePass",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String"}},
      secondHighestImpl);
}

int SecondLargestDigitInAStringSolution::secondHighest(std::string s) {
  return getSolution()(s);
}

}  // namespace problem_1796
}  // namespace leetcode
