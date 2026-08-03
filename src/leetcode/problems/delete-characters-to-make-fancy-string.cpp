#include "leetcode/problems/delete-characters-to-make-fancy-string.h"

namespace leetcode {
namespace problem_1957 {

static std::string makeFancyStringImpl(std::string s) {
  std::string result;
  for (char c : s) {
    int n = static_cast<int>(result.size());
    if (n >= 2 && result[n - 1] == c && result[n - 2] == c) {
      continue;
    }
    result.push_back(c);
  }
  return result;
}

DeleteCharactersToMakeFancyStringSolution::DeleteCharactersToMakeFancyStringSolution() {
  setMetaInfo({.id = 1957,
               .title = "Delete Characters to Make Fancy String",
               .url = "https://leetcode.com/problems/delete-characters-to-make-fancy-string/"});
  registerStrategy({.name = "greedy",
                     .expected = "Accepted",
                     .time_complexity = "O(n)",
                     .space_complexity = "O(n)",
                     .tags = {"String"}},
                     makeFancyStringImpl);
}

std::string DeleteCharactersToMakeFancyStringSolution::makeFancyString(std::string s) {
  return getSolution()(s);
}

}  // namespace problem_1957
}  // namespace leetcode
