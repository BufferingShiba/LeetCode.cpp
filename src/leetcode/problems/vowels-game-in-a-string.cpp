#include "leetcode/problems/vowels-game-in-a-string.h"

#include <string>

namespace leetcode {
namespace problem_3227 {

namespace {

bool doesAliceWinImpl(const std::string& s) {
  for (char c : s) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      return true;
    }
  }
  return false;
}

}  // namespace

VowelsGameInAStringSolution::VowelsGameInAStringSolution() {
  setMetaInfo({.id = 3227,
               .title = "Vowels Game in a String",
               .url = "https://leetcode.com/problems/vowels-game-in-a-string/"});
  registerStrategy(
      {.name = "vowel-existence-count",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Math", "String", "Brainteaser", "Game Theory"}},
      doesAliceWinImpl);
}

bool VowelsGameInAStringSolution::doesAliceWin(std::string s) {
  return getSolution()(s);
}

}  // namespace problem_3227
}  // namespace leetcode
