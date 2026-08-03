#include "leetcode/problems/sum-of-numbers-with-units-digit-k.h"

#include <algorithm>

namespace leetcode::problem_2310 {

namespace {

// 枚举集合大小 n（最多为 10，因为个位模式以 10 为周期）。
// 设 n 个数，每个数个位为 k，可写作 k + 10*a_i (a_i >= 0)。
// 则 num = n*k + 10 * (sum a_i)。
// 条件：n*k <= num 且 (num - n*k) 能被 10 整除。
int minimumNumbersEnumeration(int num, int k) {
  if (num == 0) {
    return 0;
  }
  for (int n = 1; n <= 10; ++n) {
    if (n * k <= num && (num - n * k) % 10 == 0) {
      return n;
    }
  }
  return -1;
}

}  // namespace

SumOfNumbersWithUnitsDigitKSolution::SumOfNumbersWithUnitsDigitKSolution() {
  setMetaInfo({.id = 2310,
               .title = "Sum of Numbers With Units Digit K",
               .url = "https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/"});

  registerStrategy({.name = "enumeration",
                    .expected = "Accepted",
                    .time_complexity = "O(10)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "Enumeration"},
                    .notes = "每位数为 k 的数可写为 k + 10*a，枚举集合大小 n，条件为 n*k <= num 且 (num - n*k) % 10 == 0"},
                   minimumNumbersEnumeration);

  setDefaultStrategy();
}

int SumOfNumbersWithUnitsDigitKSolution::minimumNumbers(int num, int k) {
  return getSolution()(num, k);
}

}  // namespace leetcode::problem_2310
