#include "leetcode/problems/find-the-original-typed-string-i.h"

namespace leetcode {
namespace problem_3330 {

namespace {

int possibleStringCountImpl(const std::string& word) {
  int extra = 0;
  for (std::size_t i = 0; i < word.size();) {
    std::size_t j = i;
    while (j < word.size() && word[j] == word[i]) {
      ++j;
    }
    extra += static_cast<int>((j - i) - 1);
    i = j;
  }
  return extra + 1;
}

}  // namespace

FindTheOriginalTypedStringISolution::FindTheOriginalTypedStringISolution() {
  setMetaInfo({.id = 3330,
               .title = "Find the Original Typed String I",
               .url = "https://leetcode.com/problems/find-the-original-typed-string-i/"});
  registerStrategy(
      {"run_length_count", "Accepted", "O(n)", "O(1)", {"String"}},
      possibleStringCountImpl);
}

int FindTheOriginalTypedStringISolution::possibleStringCount(std::string word) {
  return getSolution()(word);
}

}  // namespace problem_3330
}  // namespace leetcode
