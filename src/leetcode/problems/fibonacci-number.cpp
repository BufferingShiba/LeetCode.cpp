#include "leetcode/problems/fibonacci-number.h"

namespace leetcode {
namespace problem_509 {

namespace {

int fibImpl(int n) {
  if (n <= 1) {
    return n;
  }
  int prev = 0;
  int curr = 1;
  for (int i = 2; i <= n; ++i) {
    int next = prev + curr;
    prev = curr;
    curr = next;
  }
  return curr;
}

}  // namespace

FibonacciNumberSolution::FibonacciNumberSolution() {
  this->setMetaInfo({.id = 509,
                     .title = "Fibonacci Number",
                     .url = "https://leetcode.com/problems/fibonacci-number/"});

  this->registerStrategy(
      {.name = "Iterative DP",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Dynamic Programming", "Math"}},
      fibImpl);
}

int FibonacciNumberSolution::fib(int n) {
  return this->getSolution()(n);
}

}  // namespace problem_509
}  // namespace leetcode
