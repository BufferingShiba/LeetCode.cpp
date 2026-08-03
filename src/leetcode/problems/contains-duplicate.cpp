#include <unordered_set>

#include "leetcode/problems/contains-duplicate.h"

namespace leetcode {
namespace problem_217 {

namespace {

bool containsDuplicateImpl(std::vector<int>& nums) {
  std::unordered_set<int> seen;
  seen.reserve(nums.size());
  for (int num : nums) {
    if (seen.count(num)) {
      return true;
    }
    seen.insert(num);
  }
  return false;
}

}  // namespace

ContainsDuplicateSolution::ContainsDuplicateSolution() {
  setMetaInfo({.id = 217,
               .title = "Contains Duplicate",
               .url = "https://leetcode.com/problems/contains-duplicate/"});
  registerStrategy(
      {.name = "HashSet",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table"}},
      containsDuplicateImpl);
}

bool ContainsDuplicateSolution::containsDuplicate(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_217
}  // namespace leetcode
