#include "leetcode/problems/find-the-xor-of-numbers-which-appear-twice.h"

#include <vector>

namespace leetcode {
namespace problem_3158 {

static int duplicateNumbersXORImpl(std::vector<int>& nums) {
  int count[51] = {0};
  for (int x : nums) {
    count[x]++;
  }
  int result = 0;
  for (int i = 1; i <= 50; ++i) {
    if (count[i] == 2) {
      result ^= i;
    }
  }
  return result;
}

FindTheXorOfNumbersWhichAppearTwiceSolution::FindTheXorOfNumbersWhichAppearTwiceSolution() {
  setMetaInfo({.id = 3158,
               .title = "Find the XOR of Numbers Which Appear Twice",
               .url = "https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/"});
  registerStrategy({.name = "CountingArray",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Hash Table", "Bit Manipulation"}},
                   duplicateNumbersXORImpl);
}

int FindTheXorOfNumbersWhichAppearTwiceSolution::duplicateNumbersXOR(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3158
}  // namespace leetcode
