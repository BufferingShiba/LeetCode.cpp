#include "leetcode/problems/longest-unequal-adjacent-groups-subsequence-i.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2900 {

namespace {

std::vector<std::string> getLongestSubsequenceImpl(
    std::vector<std::string>& words, std::vector<int>& groups) {
  std::vector<std::string> result;
  int last_group = -1;
  for (std::size_t i = 0; i < words.size(); ++i) {
    if (result.empty() || groups[i] != last_group) {
      result.push_back(words[i]);
      last_group = groups[i];
    }
  }
  return result;
}

}  // namespace

LongestUnequalAdjacentGroupsSubsequenceISolution::
    LongestUnequalAdjacentGroupsSubsequenceISolution() {
  setMetaInfo({.id = 2900,
               .title = "Longest Unequal Adjacent Groups Subsequence I",
               .url = "https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/"});
  registerStrategy(
      {.name = "greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Greedy"}},
      getLongestSubsequenceImpl);
}

std::vector<std::string>
LongestUnequalAdjacentGroupsSubsequenceISolution::getLongestSubsequence(
    std::vector<std::string>& words, std::vector<int>& groups) {
  return getSolution()(words, groups);
}

}  // namespace problem_2900
}  // namespace leetcode
