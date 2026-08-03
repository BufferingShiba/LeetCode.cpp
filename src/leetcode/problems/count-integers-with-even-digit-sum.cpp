#include "leetcode/problems/count-integers-with-even-digit-sum.h"

namespace leetcode::problem_2180 {

namespace {

bool evenDigitSum(int x) {
  int sum = 0;
  while (x > 0) {
    sum += x % 10;
    x /= 10;
  }
  return sum % 2 == 0;
}

int countEvenImpl(int num) {
  int count = 0;
  for (int i = 1; i <= num; ++i) {
    if (evenDigitSum(i)) {
      ++count;
    }
  }
  return count;
}

}  // namespace

CountIntegersWithEvenDigitSum::CountIntegersWithEvenDigitSum() {
  setMetaInfo({.id = 2180,
               .title = "Count Integers With Even Digit Sum",
               .url = "https://leetcode.com/problems/count-integers-with-even-digit-sum/"});

  registerStrategy({.name = "simulation",
                    .expected = "Accepted",
                    .time_complexity = "O(num * digits)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "Simulation"}},
                   countEvenImpl);
}

int CountIntegersWithEvenDigitSum::countEven(int num) {
  return getSolution()(num);
}

}  // namespace leetcode::problem_2180
