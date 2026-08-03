#include "leetcode/problems/check-if-array-is-good.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_2784 {

static bool isGoodImpl(std::vector<int>& nums) {
  int n = *std::max_element(nums.begin(), nums.end());
  if (static_cast<int>(nums.size()) != n + 1) {
    return false;
  }

  std::vector<int> freq(n + 1, 0);
  for (int x : nums) {
    if (x < 1 || x > n) {
      return false;
    }
    if (++freq[x] > (x == n ? 2 : 1)) {
      return false;
    }
  }

  // Check 1..n-1 appear exactly once
  for (int i = 1; i < n; ++i) {
    if (freq[i] != 1) {
      return false;
    }
  }

  // n must appear exactly twice
  return freq[n] == 2;
}

CheckIfArrayIsGoodSolution::CheckIfArrayIsGoodSolution() {
  setMetaInfo({.id = 2784,
               .title = "Check if Array is Good",
               .url = "https://leetcode.com/problems/check-if-array-is-good/"});
  registerStrategy(
      {.name = "frequency-count",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table"}},
      isGoodImpl);
}

bool CheckIfArrayIsGoodSolution::isGood(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2784
}  // namespace leetcode
