#include "leetcode/problems/latest-time-you-can-obtain-after-replacing-characters.h"

#include <string>

namespace leetcode {
namespace problem_3114 {

namespace {

std::string findLatestTimeImpl(std::string s) {
  if (s[0] == '?') {
    s[0] = (s[1] != '?' && s[1] > '1') ? '0' : '1';
  }
  if (s[1] == '?') {
    s[1] = (s[0] == '1') ? '1' : '9';
  }
  if (s[3] == '?') {
    s[3] = '5';
  }
  if (s[4] == '?') {
    s[4] = '9';
  }
  return s;
}

}  // namespace

LatestTimeYouCanObtainAfterReplacingCharactersSolution::
    LatestTimeYouCanObtainAfterReplacingCharactersSolution() {
  setMetaInfo({.id = 3114,
               .title = "Latest Time You Can Obtain After Replacing Characters",
               .url = "https://leetcode.com/problems/latest-time-you-can-obtain-after-replacing-characters/"});
  registerStrategy(
      {.name = "Greedy",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"String", "Greedy"}},
      findLatestTimeImpl);
}

std::string LatestTimeYouCanObtainAfterReplacingCharactersSolution::
    findLatestTime(std::string s) {
  return getSolution()(s);
}

}  // namespace problem_3114
}  // namespace leetcode
