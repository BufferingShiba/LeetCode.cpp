#include "leetcode/problems/length-of-last-word.h"

namespace leetcode {
namespace problem_58 {

static int lengthOfLastWordImpl(std::string s) {
  int i = static_cast<int>(s.size()) - 1;
  // skip trailing spaces
  while (i >= 0 && s[i] == ' ') {
    --i;
  }
  int length = 0;
  // count non-space characters
  while (i >= 0 && s[i] != ' ') {
    --i;
    ++length;
  }
  return length;
}

LengthOfLastWordSolution::LengthOfLastWordSolution() {
  setMetaInfo({.id = 58,
               .title = "Length of Last Word",
               .url = "https://leetcode.com/problems/length-of-last-word/"});
  registerStrategy({.name = "right-to-left scan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"string"}},
                   lengthOfLastWordImpl);
}

int LengthOfLastWordSolution::lengthOfLastWord(std::string s) {
  return getSolution()(s);
}

}  // namespace problem_58
}  // namespace leetcode
