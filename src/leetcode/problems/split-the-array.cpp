#include "leetcode/problems/split-the-array.h"

#include <algorithm>
#include <unordered_map>

namespace leetcode {
namespace problem_3046 {

namespace {

bool isPossibleToSplitImpl(std::vector<int>& nums) {
  std::unordered_map<int, int> count;
  for (int x : nums) {
    if (++count[x] > 2) {
      return false;
    }
  }
  return true;
}

}  // namespace

SplitTheArraySolution::SplitTheArraySolution() {
  setMetaInfo({.id = 3046,
               .title = "Split the Array",
               .url = "https://leetcode.com/problems/split-the-array/"});

  registerStrategy(
      {.name = "HashCount",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Counting"}},
      isPossibleToSplitImpl);

  setDefaultStrategy();
}

bool SplitTheArraySolution::isPossibleToSplit(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_3046
}  // namespace leetcode
