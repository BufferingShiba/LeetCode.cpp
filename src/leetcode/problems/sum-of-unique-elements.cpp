#include <unordered_map>

#include "leetcode/problems/sum-of-unique-elements.h"

namespace leetcode {
namespace problem_1748 {

static int solution1(vector<int>& nums) {
  std::unordered_map<int, int> count;
  for (int num : nums) {
    ++count[num];
  }
  int sum = 0;
  for (const auto& [num, freq] : count) {
    if (freq == 1) {
      sum += num;
    }
  }
  return sum;
}

SumOfUniqueElementsSolution::SumOfUniqueElementsSolution() {
  setMetaInfo({
      .id = 1748,
      .title = "Sum of Unique Elements",
      .url = "https://leetcode.com/problems/sum-of-unique-elements"
  });
  registerStrategy(
      {.name = "Brute Force",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Counting"}},
      solution1);
}

int SumOfUniqueElementsSolution::sumOfUnique(vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_1748
}  // namespace leetcode
