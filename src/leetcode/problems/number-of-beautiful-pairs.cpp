#include "leetcode/problems/number-of-beautiful-pairs.h"

#include <numeric>

namespace leetcode {
namespace problem_2748 {
namespace {

int firstDigit(int num) {
  while (num >= 10) {
    num /= 10;
  }
  return num;
}

int countBeautifulPairsImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  int count = 0;
  for (int i = 0; i < n; ++i) {
    const int a = firstDigit(nums[i]);
    for (int j = i + 1; j < n; ++j) {
      const int b = nums[j] % 10;
      if (std::gcd(a, b) == 1) {
        ++count;
      }
    }
  }
  return count;
}

}  // namespace

NumberOfBeautifulPairsSolution::NumberOfBeautifulPairsSolution() {
  setMetaInfo({.id = 2748,
               .title = "Number of Beautiful Pairs",
               .url = "https://leetcode.com/problems/number-of-beautiful-pairs/"});
  registerStrategy(
      {.name = "BruteForce",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Counting", "Number Theory"}},
      countBeautifulPairsImpl);
}

int NumberOfBeautifulPairsSolution::countBeautifulPairs(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2748
}  // namespace leetcode
