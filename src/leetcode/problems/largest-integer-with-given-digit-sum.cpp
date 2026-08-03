#include "leetcode/problems/largest-integer-with-given-digit-sum.h"

#include <string>

namespace leetcode {
namespace problem_4000 {

static int largestIntegerImpl(int n, int s) {
  if (s == 0) return 0;
  if (s > 9 * n) return -1;

  std::string result;
  int remaining_sum = s;

  for (int i = 0; i < n; ++i) {
    int remaining_digits = n - i - 1;
    for (int d = 9; d >= 0; --d) {
      if (d <= remaining_sum &&
          (remaining_sum - d) <= 9 * remaining_digits &&
          (remaining_sum - d) >= 0) {
        result.push_back(static_cast<char>('0' + d));
        remaining_sum -= d;
        break;
      }
    }
  }

  return std::stoi(result);
}

LargestIntegerWithGivenDigitSumSolution::LargestIntegerWithGivenDigitSumSolution() {
  setMetaInfo(4000,
              "Largest Integer With Given Digit Sum",
              "https://leetcode.com/problems/largest-integer-with-given-digit-sum/");

  registerStrategy(
      {.name = "Greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Greedy", "Math", "String"}},
      largestIntegerImpl);
}

int LargestIntegerWithGivenDigitSumSolution::largestInteger(int n, int s) {
  return getSolution()(n, s);
}

}  // namespace problem_4000
}  // namespace leetcode
