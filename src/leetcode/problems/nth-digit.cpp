#include "leetcode/problems/nth-digit.h"

#include <cmath>

namespace leetcode::problem_400 {

namespace {

int findNthDigitImpl(int n) {
  long long nn = n;  // use 64-bit to avoid overflow

  // Step 1: find the digit-length range
  int len = 1;
  long long count = 9;       // how many numbers in this range
  long long start = 1;       // first number of this range

  while (nn > len * count) {
    nn -= len * count;
    ++len;
    count *= 10;
    start *= 10;
  }

  // Step 2: find the exact number
  // nn is now the 1-indexed position within numbers of length `len`
  long long num = start + (nn - 1) / len;

  // Step 3: find the digit within the number
  int digitIndex = static_cast<int>((nn - 1) % len);

  // Extract the digit: we need the (len - 1 - digitIndex)-th digit from the right
  // Or equivalently: divide by 10^(len-1-digitIndex) then mod 10
  int power = static_cast<int>(std::pow(10, len - 1 - digitIndex));
  return static_cast<int>((num / power) % 10);
}

}  // namespace

NthDigitSolution::NthDigitSolution() {
  setMetaInfo({.id = 400, .title = "Nth Digit", .url = "https://leetcode.com/problems/nth-digit/"});

  registerStrategy(
      {.name = "Math",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(1)",
       .tags = {"Math"}},
      findNthDigitImpl);
}

int NthDigitSolution::findNthDigit(int n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_400
