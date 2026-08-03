#include "leetcode/problems/happy-number.h"

#include <unordered_set>

namespace leetcode {
namespace problem_202 {

namespace {

// 计算 n 各位数字的平方和
int sumOfSquares(int n) {
  int sum = 0;
  while (n > 0) {
    int digit = n % 10;
    sum += digit * digit;
    n /= 10;
  }
  return sum;
}

bool isHappyImpl(int n) {
  std::unordered_set<int> seen;
  while (n != 1 && seen.find(n) == seen.end()) {
    seen.insert(n);
    n = sumOfSquares(n);
  }
  return n == 1;
}

}  // namespace

HappyNumberSolution::HappyNumberSolution() {
  setMetaInfo({.id = 202,
               .title = "Happy Number",
               .url = "https://leetcode.com/problems/happy-number/"});
  registerStrategy(
      {.name = "HashSetCycleDetection",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(log n)",
       .tags = {"Hash Table", "Math"}},
      isHappyImpl);
}

bool HappyNumberSolution::isHappy(int n) { return getSolution()(n); }

}  // namespace problem_202
}  // namespace leetcode
