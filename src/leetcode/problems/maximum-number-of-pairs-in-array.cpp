#include "leetcode/problems/maximum-number-of-pairs-in-array.h"

#include <array>

namespace leetcode::problem_2341 {

namespace {

std::vector<int> numberOfPairsImpl(std::vector<int>& nums) {
  std::array<int, 101> freq{};
  int pairs = 0;
  for (int num : nums) {
    ++freq[num];
  }
  for (int cnt : freq) {
    pairs += cnt / 2;
  }
  return {pairs, static_cast<int>(nums.size()) - 2 * pairs};
}

}  // namespace

MaximumNumberOfPairsInArraySolution::MaximumNumberOfPairsInArraySolution() {
  setMetaInfo({.id = 2341,
               .title = "Maximum Number of Pairs in Array",
               .url = "https://leetcode.com/problems/maximum-number-of-pairs-in-array/"});
  registerStrategy({.name = "Counting",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Hash Table", "Counting"}},
                   numberOfPairsImpl);
}

std::vector<int> MaximumNumberOfPairsInArraySolution::numberOfPairs(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace leetcode::problem_2341
