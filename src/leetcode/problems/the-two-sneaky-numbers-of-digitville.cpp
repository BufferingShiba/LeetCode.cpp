#include "leetcode/problems/the-two-sneaky-numbers-of-digitville.h"

#include <algorithm>

namespace leetcode {
namespace problem_3289 {

namespace {

std::vector<int> findSneakyNumbers(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size()) - 2;
  std::vector<int> frequency(n, 0);
  std::vector<int> result;
  for (int value : nums) {
    if (++frequency[value] == 2) {
      result.push_back(value);
    }
  }
  return result;
}

}  // namespace

TheTwoSneakyNumbersOfDigitvilleSolution::
    TheTwoSneakyNumbersOfDigitvilleSolution() {
  setMetaInfo({.id = 3289,
               .title = "The Two Sneaky Numbers of Digitville",
               .url = "https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/"});
  registerStrategy({.name = "FrequencyCounting",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Hash Table"}},
                   findSneakyNumbers);
}

}  // namespace problem_3289
}  // namespace leetcode
