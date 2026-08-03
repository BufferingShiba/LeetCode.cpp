#include "leetcode/problems/count-equal-and-divisible-pairs-in-an-array.h"

namespace leetcode {
namespace problem_2176 {
namespace {

int countPairsImpl(std::vector<int>& nums, int k) {
  int count = 0;
  const int n = static_cast<int>(nums.size());
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (nums[i] == nums[j] && (i * j) % k == 0) {
        ++count;
      }
    }
  }
  return count;
}

}  // namespace

CountEqualAndDivisiblePairsInAnArraySolution::CountEqualAndDivisiblePairsInAnArraySolution() {
  setMetaInfo({.id = 2176,
               .title = "Count Equal and Divisible Pairs in an Array",
               .url = "https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/"});
  registerStrategy({.name = "brute-force",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2)",
                    .space_complexity = "O(1)",
                    .tags = {"Array"}},
                   countPairsImpl);
}

int CountEqualAndDivisiblePairsInAnArraySolution::countPairs(std::vector<int>& nums, int k) {
  return getSolution()(nums, k);
}

}  // namespace problem_2176
}  // namespace leetcode
