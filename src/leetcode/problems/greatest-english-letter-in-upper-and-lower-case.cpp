#include "leetcode/problems/greatest-english-letter-in-upper-and-lower-case.h"

namespace leetcode {
namespace problem_2309 {

static std::string greatestLetterImpl(std::string s) {
  int lower = 0, upper = 0;
  for (char c : s) {
    if (c >= 'a' && c <= 'z') {
      lower |= (1 << (c - 'a'));
    } else {
      upper |= (1 << (c - 'A'));
    }
  }
  for (int i = 25; i >= 0; --i) {
    if ((lower & (1 << i)) && (upper & (1 << i))) {
      return std::string(1, static_cast<char>('A' + i));
    }
  }
  return "";
}

GreatestEnglishLetterInUpperAndLowerCaseSolution::
    GreatestEnglishLetterInUpperAndLowerCaseSolution() {
  setMetaInfo({.id = 2309,
               .title = "Greatest English Letter in Upper and Lower Case",
               .url = "https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/"});
  registerStrategy(
      {.name = "bitmask",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String", "Enumeration"}},
      greatestLetterImpl);
  setDefaultStrategy();
}

std::string GreatestEnglishLetterInUpperAndLowerCaseSolution::greatestLetter(
    std::string s) {
  return getSolution()(s);
}

}  // namespace problem_2309
}  // namespace leetcode
