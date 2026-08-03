// Find The Least Frequent Digit
#include "leetcode/problems/find-the-least-frequent-digit.h"

#include <array>
#include <string>

namespace leetcode {
namespace problem_3663 {
namespace {

int getLeastFrequentDigitImpl(int n) {
  std::array<int, 10> freq{};
  if (n == 0) {
    freq[0] = 1;
  } else {
    while (n > 0) {
      ++freq[n % 10];
      n /= 10;
    }
  }
  int best = 10;
  int bestFreq = 0x7fffffff;
  for (int d = 0; d < 10; ++d) {
    if (freq[d] > 0 && freq[d] < bestFreq) {
      bestFreq = freq[d];
      best = d;
    }
  }
  return best;
}

}  // namespace

FindTheLeastFrequentDigitSolution::FindTheLeastFrequentDigitSolution() {
  setMetaInfo({.id = 3663,
               .title = "Find The Least Frequent Digit",
               .url = "https://leetcode.com/problems/find-the-least-frequent-digit/"});
  registerStrategy(
      {.name = "counting",
       .expected = "Accepted",
       .time_complexity = "O(log_10(n))",
       .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table", "Math", "Counting"}},
      getLeastFrequentDigitImpl);
}

int FindTheLeastFrequentDigitSolution::getLeastFrequentDigit(int n) {
  return getSolution()(n);
}

}  // namespace problem_3663
}  // namespace leetcode
