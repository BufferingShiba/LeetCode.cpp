#include "leetcode/problems/remove-all-adjacent-duplicates-in-string.h"

namespace leetcode {
namespace problem_1047 {

namespace {

std::string removeDuplicatesImpl(std::string s) {
  std::string result;
  result.reserve(s.size());
  for (char c : s) {
    if (!result.empty() && result.back() == c) {
      result.pop_back();
    } else {
      result.push_back(c);
    }
  }
  return result;
}

}  // namespace

RemoveAllAdjacentDuplicatesInStringSolution::
    RemoveAllAdjacentDuplicatesInStringSolution() {
  setMetaInfo(
      {.id = 1047,
       .title = "Remove All Adjacent Duplicates In String",
       .url = "https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/"});
  registerStrategy(
      {.name = "stack",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"String", "Stack"}},
      removeDuplicatesImpl);
}

std::string RemoveAllAdjacentDuplicatesInStringSolution::removeDuplicates(
    std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_1047
}  // namespace leetcode
