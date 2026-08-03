#include "leetcode/problems/unique-middle-element.h"

namespace leetcode::problem_3978 {

namespace {

bool isMiddleElementUniqueImpl(std::vector<int>& nums) {
  const int n = static_cast<int>(nums.size());
  const int middle = nums[n / 2];
  int count = 0;
  for (const int x : nums) {
    if (x == middle) {
      ++count;
    }
  }
  return count == 1;
}

}  // namespace

bool UniqueMiddleElementSolution::isMiddleElementUnique(std::vector<int>& nums) {
  return getSolution()(nums);
}

UniqueMiddleElementSolution::UniqueMiddleElementSolution() {
  setMetaInfo({.id = 3978,
               .title = "Unique Middle Element",
               .url =
                   "https://leetcode.com/problems/unique-middle-element/"});
  registerStrategy(
      {"count-middle", "Accepted", "O(n)", "O(1)",
       std::vector<std::string>{"array"}},
      isMiddleElementUniqueImpl);
}

}  // namespace leetcode::problem_3978
