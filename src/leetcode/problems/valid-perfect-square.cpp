#include "leetcode/problems/valid-perfect-square.h"

namespace leetcode {
namespace problem_367 {

namespace {

bool isPerfectSquareImpl(int num) {
  if (num < 2) {
    return true;
  }
  long long left = 1;
  long long right = num;
  while (left <= right) {
    long long mid = left + (right - left) / 2;
    long long square = mid * mid;
    if (square == num) {
      return true;
    } else if (square < num) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return false;
}

}  // namespace

ValidPerfectSquareSolution::ValidPerfectSquareSolution() {
  setMetaInfo({.id = 367,
               .title = "Valid Perfect Square",
               .url = "https://leetcode.com/problems/valid-perfect-square/"});
  registerStrategy(
      {.name = "Binary Search",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Binary Search"}},
      isPerfectSquareImpl);
}

bool ValidPerfectSquareSolution::isPerfectSquare(int num) {
  return getSolution()(num);
}

}  // namespace problem_367
}  // namespace leetcode
