#include "leetcode/problems/count-special-integers.h"

#include <string>

namespace leetcode::problem_2376 {

// Count numbers with `len` digits where all digits are distinct, first digit
// cannot be zero.
static long long CountDistinctByLen(int len) {
  if (len > 10) return 0;
  long long count = 9;  // first digit choices: 1..9
  int available = 9;    // remaining digits after first
  for (int i = 1; i < len; ++i) {
    count *= available--;
  }
  return count;
}

// Count how many ways to fill `len` positions using distinct digits not in
// `usedMask` (digits consumed so far).
static long long CountPermutations(int len, int usedMask) {
  int available = 10;
  for (int d = 0; d < 10; ++d) {
    if (usedMask & (1 << d)) --available;
  }
  long long count = 1;
  for (int i = 0; i < len; ++i) {
    count *= (available - i);
  }
  return count;
}

static int countSpecialNumbersImpl(int n) {
  std::string s = std::to_string(n);
  const int L = static_cast<int>(s.size());

  long long result = 0;

  // Numbers with fewer digits than n.
  for (int len = 1; len < L; ++len) {
    result += CountDistinctByLen(len);
  }

  // Numbers with exactly L digits that are <= n.
  int usedMask = 0;
  for (int pos = 0; pos < L; ++pos) {
    int digit = s[pos] - '0';
    int startDigit = (pos == 0) ? 1 : 0;
    for (int d = startDigit; d < digit; ++d) {
      if (usedMask & (1 << d)) continue;  // digit already used in prefix
      int newMask = usedMask | (1 << d);
      int remaining = L - pos - 1;
      result += CountPermutations(remaining, newMask);
    }
    // Fix current digit to equal n's digit.
    if (usedMask & (1 << digit)) {
      // prefix already contains this digit; can't match n exactly.
      return static_cast<int>(result);
    }
    usedMask |= (1 << digit);
  }

  // n itself has all distinct digits.
  result += 1;
  return static_cast<int>(result);
}

CountSpecialIntegersSolution::CountSpecialIntegersSolution() {
  this->setMetaInfo({.id = 2376,
                     .title = "Count Special Integers",
                     .url = "https://leetcode.com/problems/count-special-integers/"});
  this->registerStrategy(
      {.name = "permutation-counting",
       .expected = "Accepted",
       .time_complexity = "O(len(n) * 10)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Dynamic Programming"},
       .notes =
           "Count numbers shorter than n via permutations, then scan n's "
           "digits choosing smaller leading options with a used-digit mask."},
      countSpecialNumbersImpl);
}

int CountSpecialIntegersSolution::countSpecialNumbers(int n) {
  return this->getSolution()(n);
}

}  // namespace leetcode::problem_2376
