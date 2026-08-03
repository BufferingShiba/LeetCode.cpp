#include "leetcode/problems/find-numbers-with-even-number-of-digits.h"

namespace leetcode {
namespace problem_1295 {

namespace {

int findNumbersImpl(std::vector<int>& nums) {
  int count = 0;
  for (int num : nums) {
    int digits = 0;
    while (num > 0) {
      ++digits;
      num /= 10;
    }
    if (digits % 2 == 0) {
      ++count;
    }
  }
  return count;
}

}  // namespace

FindNumbersWithEvenNumberOfDigitsSolution::
    FindNumbersWithEvenNumberOfDigitsSolution() {
  setMetaInfo({.id = 1295,
               .title = "Find Numbers with Even Number of Digits",
               .url = "https://leetcode.com/problems/find-numbers-with-even-number-of-digits/"});
  registerStrategy(
      {.name = "DigitCountScan",
       .expected = "Accepted",
       .time_complexity = "O(n*d)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math"}},
      findNumbersImpl);
}

int FindNumbersWithEvenNumberOfDigitsSolution::findNumbers(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_1295
}  // namespace leetcode
