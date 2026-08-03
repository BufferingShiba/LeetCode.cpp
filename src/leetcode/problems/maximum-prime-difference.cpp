#include "leetcode/problems/maximum-prime-difference.h"

namespace leetcode {
namespace problem_3115 {

namespace {

bool isPrime(int n) {
  if (n < 2) return false;
  for (int d = 2; d * d <= n; ++d) {
    if (n % d == 0) return false;
  }
  return true;
}

int solve(std::vector<int>& nums) {
  int first = -1;
  int last = -1;
  const int n = static_cast<int>(nums.size());
  for (int i = 0; i < n; ++i) {
    if (isPrime(nums[i])) {
      if (first == -1) first = i;
      last = i;
    }
  }
  return last - first;
}

}  // namespace

MaximumPrimeDifferenceSolution::MaximumPrimeDifferenceSolution() {
  setMetaInfo({.id = 3115,
               .title = "Maximum Prime Difference",
               .url = "https://leetcode.com/problems/maximum-prime-difference/"});
  registerStrategy(
      {.name = "Two-Pointer Scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math", "Number Theory"},
       .notes = "Single forward scan computing first and last prime indices."},
      solve);
}

}  // namespace problem_3115
}  // namespace leetcode
