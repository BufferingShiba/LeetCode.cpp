#include "leetcode/problems/sequential-digits.h"

#include <algorithm>

namespace leetcode::problem_1291 {

namespace {

std::vector<int> sequentialDigitsImpl(int low, int high) {
  std::vector<int> result;
  // Enumerate all sequential numbers by start digit, extending length.
  for (int start = 1; start <= 9; ++start) {
    int num = start;
    for (int next = start + 1; next <= 9; ++next) {
      num = num * 10 + next;
      if (num > high) {
        break;
      }
      if (num >= low) {
        result.push_back(num);
      }
    }
  }
  // The enumeration above is not sorted numerically (length grows per start), so
  // sort to satisfy the "sorted" requirement.
  std::sort(result.begin(), result.end());
  return result;
}

}  // namespace

SequentialDigitsSolution::SequentialDigitsSolution() {
  setMetaInfo({.id = 1291,
               .title = "Sequential Digits",
               .url = "https://leetcode.com/problems/sequential-digits/"});

  registerStrategy(
      {.name = "enumeration",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Enumeration"}},
      sequentialDigitsImpl);
}

std::vector<int> SequentialDigitsSolution::sequentialDigits(int low,
                                                            int high) {
  return getSolution()(low, high);
}

}  // namespace leetcode::problem_1291
