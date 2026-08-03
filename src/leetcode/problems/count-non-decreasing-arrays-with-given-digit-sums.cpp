#include "leetcode/problems/count-non-decreasing-arrays-with-given-digit-sums.h"

#include <algorithm>
#include <array>

namespace leetcode {
namespace problem_3883 {
namespace {

constexpr int kMaxValue = 5000;
constexpr int kMod = 1'000'000'007;

int sumDigits(int value) {
  int result = 0;
  do {
    result += value % 10;
    value /= 10;
  } while (value != 0);
  return result;
}

void buildPrefix(const std::vector<int>& values, std::vector<int>& prefix) {
  int running = 0;
  for (int value = 0; value <= kMaxValue; ++value) {
    running += values[value];
    if (running >= kMod) running -= kMod;
    prefix[value] = running;
  }
}

int digitSumPrefixDp(std::vector<int>& digitSum) {
  std::array<int, kMaxValue + 1> valueDigitSums{};
  for (int value = 0; value <= kMaxValue; ++value) {
    valueDigitSums[value] = sumDigits(value);
  }

  std::vector<int> current(kMaxValue + 1, 0);
  std::vector<int> prefix(kMaxValue + 1, 0);

  for (int value = 0; value <= kMaxValue; ++value) {
    if (valueDigitSums[value] == digitSum.front()) current[value] = 1;
  }
  buildPrefix(current, prefix);

  for (std::size_t position = 1; position < digitSum.size(); ++position) {
    std::fill(current.begin(), current.end(), 0);
    for (int value = 0; value <= kMaxValue; ++value) {
      if (valueDigitSums[value] == digitSum[position]) {
        current[value] = prefix[value];
      }
    }
    buildPrefix(current, prefix);
  }

  return prefix[kMaxValue];
}

}  // namespace

CountNonDecreasingArraysWithGivenDigitSumsSolution::
    CountNonDecreasingArraysWithGivenDigitSumsSolution() {
  setMetaInfo({.id = 3883,
               .title = "Count Non Decreasing Arrays With Given Digit Sums",
               .url = "https://leetcode.com/problems/count-non-decreasing-arrays-with-given-digit-sums/"});
  registerStrategy(
      {.name = "DigitSumPrefixDp",
       .expected = "Accepted",
       .time_complexity = "O(n * 5000)",
       .space_complexity = "O(5000)",
       .tags = {"Array", "Dynamic Programming", "Prefix Sum"}},
      digitSumPrefixDp);
}

}  // namespace problem_3883
}  // namespace leetcode
