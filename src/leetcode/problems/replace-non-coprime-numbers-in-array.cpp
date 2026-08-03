#include "leetcode/problems/replace-non-coprime-numbers-in-array.h"

#include <algorithm>
#include <numeric>
#include <vector>

namespace leetcode::problem_2197 {

static std::vector<int> replaceNonCoprimesImpl(std::vector<int>& nums) {
  std::vector<int> stack;
  stack.reserve(nums.size());

  for (int x : nums) {
    stack.push_back(x);

    while (stack.size() >= 2) {
      int a = stack[stack.size() - 2];
      int b = stack[stack.size() - 1];
      int g = std::gcd(a, b);
      if (g > 1) {
        stack.pop_back();
        stack.pop_back();
        long long lcm = static_cast<long long>(a) / g * b;
        stack.push_back(static_cast<int>(lcm));
      } else {
        break;
      }
    }
  }

  return stack;
}

ReplaceNonCoprimeNumbersInArraySolution::ReplaceNonCoprimeNumbersInArraySolution() {
  setMetaInfo({.id = 2197,
               .title = "Replace Non-Coprime Numbers in Array",
               .url = "https://leetcode.com/problems/replace-non-coprime-numbers-in-array/"});

  registerStrategy(
      {.name = "Stack Simulation",
       .expected = "Accepted",
       .time_complexity = "O(n log M)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Math", "Stack", "Number Theory"}},
      replaceNonCoprimesImpl);
}

std::vector<int> ReplaceNonCoprimeNumbersInArraySolution::replaceNonCoprimes(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_2197
