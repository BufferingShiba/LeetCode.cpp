#include "leetcode/problems/first-unique-even-element.h"

namespace leetcode {
namespace problem_3866 {

namespace {

int firstUniqueEvenImpl(std::vector<int>& nums) {
  int freq[101] = {0};
  for (int x : nums) {
    ++freq[x];
  }
  for (int x : nums) {
    if ((x & 1) == 0 && freq[x] == 1) {
      return x;
    }
  }
  return -1;
}

}  // namespace

FirstUniqueEvenElementSolution::FirstUniqueEvenElementSolution() {
  setMetaInfo({.id = 3866,
               .title = "First Unique Even Element",
               .url = "https://leetcode.com/problems/first-unique-even-element/"});

  registerStrategy(
      {.name = "TwoPassFrequencyArray",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table", "Counting"}},
      firstUniqueEvenImpl);
}

int FirstUniqueEvenElementSolution::firstUniqueEven(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3866
}  // namespace leetcode
