#include "leetcode/problems/find-the-minimum-possible-sum-of-a-beautiful-array.h"

namespace leetcode::problem_2834 {

namespace {

constexpr int kMod = 1'000'000'007;

// Compute sum of 1 + 2 + ... + x, modulo kMod.
long long sum1ToX(long long x) {
  // x * (x + 1) / 2 mod kMod
  long long a = x;
  long long b = x + 1;
  if (a % 2 == 0) a /= 2;
  else b /= 2;
  return (a % kMod) * (b % kMod) % kMod;
}

int minimumPossibleSumImpl(int n, int target) {
  // m = max count of numbers we can pick from [1, target-1]
  long long m = target / 2;

  long long ans = 0;

  if (n <= m) {
    // We only need the first n positive integers.
    ans = sum1ToX(n);
  } else {
    // Pick all m numbers from [1, target-1]: 1, 2, ..., m
    ans = sum1ToX(m);

    // Remaining numbers: pick from target, target+1, ...
    long long rem = n - m;
    // Sum of target + (target+1) + ... + (target + rem - 1)
    // = rem * target + (0 + 1 + ... + rem - 1)
    long long part1 = (rem % kMod) * (target % kMod) % kMod;
    long long part2 = sum1ToX(rem - 1);
    ans = (ans + part1 + part2) % kMod;
  }

  return static_cast<int>(ans);
}

}  // namespace

FindTheMinimumPossibleSumOfABeautifulArraySolution::FindTheMinimumPossibleSumOfABeautifulArraySolution() {
  setMetaInfo({.id = 2834,
               .title = "Find the Minimum Possible Sum of a Beautiful Array",
               .url = "https://leetcode.com/problems/find-the-minimum-possible-sum-of-a-beautiful-array/"});

  registerStrategy({.name = "math-greedy",
                    .expected = "Accepted",
                    .time_complexity = "O(1)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "Greedy"}},
                   minimumPossibleSumImpl);
}

int FindTheMinimumPossibleSumOfABeautifulArraySolution::minimumPossibleSum(int n, int target) {
  return getSolution()(n, target);
}

}  // namespace leetcode::problem_2834
