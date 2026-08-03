#include "leetcode/problems/ugly-number.h"

namespace leetcode::problem_263 {

namespace {

bool isUglyImpl(int n) {
  if (n <= 0) {
    return false;
  }
  while (n % 2 == 0) n /= 2;
  while (n % 3 == 0) n /= 3;
  while (n % 5 == 0) n /= 5;
  return n == 1;
}

}  // namespace

bool UglyNumberSolution::isUgly(int n) {
  return getSolution()(n);
}

UglyNumberSolution::UglyNumberSolution() {
  setMetaInfo({.id = 263, .title = "Ugly Number", .url = "https://leetcode.com/problems/ugly-number/"});
  registerStrategy({.name = "division_by_2_3_5",
                    .expected = "Accepted",
                    .time_complexity = "O(log n)",
                    .space_complexity = "O(1)",
                    .tags = {"Math"}},
                   isUglyImpl);
}

}  // namespace leetcode::problem_263
