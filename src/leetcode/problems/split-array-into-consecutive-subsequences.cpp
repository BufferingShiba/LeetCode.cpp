
#include "leetcode/problems/split-array-into-consecutive-subsequences.h"

#include <unordered_map>

namespace leetcode {
namespace problem_659 {

namespace {

bool isPossibleImpl(std::vector<int>& nums) {
  std::unordered_map<int, int> count;
  std::unordered_map<int, int> end;
  for (int x : nums) {
    ++count[x];
  }
  for (int x : nums) {
    if (count[x] == 0) {
      continue;
    }
    --count[x];
    if (end[x - 1] > 0) {
      // extend an existing consecutive subsequence ending at x-1
      --end[x - 1];
      ++end[x];
    } else if (count[x + 1] > 0 && count[x + 2] > 0) {
      // start a new subsequence of length 3
      --count[x + 1];
      --count[x + 2];
      ++end[x + 2];
    } else {
      return false;
    }
  }
  return true;
}

}  // namespace

SplitArrayIntoConsecutiveSubsequencesSolution::
    SplitArrayIntoConsecutiveSubsequencesSolution() {
  setMetaInfo({.id = 659,
               .title = "Split Array into Consecutive Subsequences",
               .url = "https://leetcode.com/problems/split-array-into-consecutive-subsequences/"});
  registerStrategy(
      {.name = "Greedy with Hash Maps", .expected = "Accepted",
       .time_complexity = "O(n)", .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Greedy"}},
      isPossibleImpl);
}

bool SplitArrayIntoConsecutiveSubsequencesSolution::isPossible(
    std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_659
}  // namespace leetcode
