#include "leetcode/problems/decrypt-string-from-alphabet-to-integer-mapping.h"

#include <algorithm>

namespace leetcode::problem_1309 {

namespace {

std::string freqAlphabetsImpl(std::string s) {
  std::string result;
  int i = static_cast<int>(s.size()) - 1;
  while (i >= 0) {
    if (s[i] == '#') {
      int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
      result.push_back(static_cast<char>('a' + num - 1));
      i -= 3;
    } else {
      int num = s[i] - '0';
      result.push_back(static_cast<char>('a' + num - 1));
      --i;
    }
  }
  std::reverse(result.begin(), result.end());
  return result;
}

DecryptStringFromAlphabetToIntegerMappingSolution& sharedInstance() {
  static DecryptStringFromAlphabetToIntegerMappingSolution instance;
  return instance;
}

}  // namespace

DecryptStringFromAlphabetToIntegerMappingSolution::
    DecryptStringFromAlphabetToIntegerMappingSolution() {
  setMetaInfo(
      {.id = 1309,
       .title = "Decrypt String from Alphabet to Integer Mapping",
       .url =
           "https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/"});
  registerStrategy(
      {.name = "right-to-left-scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"String"}},
      &freqAlphabetsImpl);
}

std::string DecryptStringFromAlphabetToIntegerMappingSolution::freqAlphabets(
    std::string s) {
  return getSolution()(std::move(s));
}

std::vector<std::string>
DecryptStringFromAlphabetToIntegerMappingSolution::strategyNames() {
  return sharedInstance().getStrategyNames();
}

}  // namespace leetcode::problem_1309
