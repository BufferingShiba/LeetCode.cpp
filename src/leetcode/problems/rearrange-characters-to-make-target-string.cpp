#include "leetcode/problems/rearrange-characters-to-make-target-string.h"

#include <algorithm>
#include <array>

namespace leetcode {
namespace problem_2287 {

namespace {

int rearrangeCharactersImpl(const std::string& s, const std::string& target) {
  std::array<int, 26> countS{};
  for (char c : s) {
    ++countS[c - 'a'];
  }

  std::array<int, 26> countT{};
  for (char c : target) {
    ++countT[c - 'a'];
  }

  int ans = s.size();
  for (int i = 0; i < 26; ++i) {
    if (countT[i] > 0) {
      ans = std::min(ans, countS[i] / countT[i]);
    }
  }
  return ans;
}

}  // namespace

RearrangeCharactersToMakeTargetStringSolution::
    RearrangeCharactersToMakeTargetStringSolution() {
  setMetaInfo(
      {.id = 2287,
       .title = "Rearrange Characters to Make Target String",
       .url = "https://leetcode.com/problems/rearrange-characters-to-make-target-string/"});
  registerStrategy(
      {.name = "Counting",
       .expected = "Accepted",
       .time_complexity = "O(len(s) + len(target))",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String", "Counting"}},
      rearrangeCharactersImpl);
}

int RearrangeCharactersToMakeTargetStringSolution::rearrangeCharacters(
    std::string s, std::string target) {
  return getSolution()(std::move(s), std::move(target));
}

}  // namespace problem_2287
}  // namespace leetcode
