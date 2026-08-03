#include "leetcode/problems/maximum-number-of-vowels-in-a-substring-of-given-length.h"

namespace {

bool isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxVowelsImpl(std::string s, int k) {
  int count = 0;
  for (int i = 0; i < k; ++i) {
    if (isVowel(s[i])) {
      ++count;
    }
  }

  int maxCount = count;
  for (size_t i = k; i < s.size(); ++i) {
    if (isVowel(s[i - k])) {
      --count;
    }
    if (isVowel(s[i])) {
      ++count;
    }
    if (count > maxCount) {
      maxCount = count;
    }
  }

  return maxCount;
}

}  // namespace

namespace leetcode {
namespace problem_1456 {

MaximumNumberOfVowelsInASubstringOfGivenLengthSolution::MaximumNumberOfVowelsInASubstringOfGivenLengthSolution() {
  setMetaInfo({.id = 1456,
               .title = "Maximum Number of Vowels in a Substring of Given Length",
               .url = "https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/"});

  registerStrategy({.name = "Sliding Window",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"String", "Sliding Window"}},
                   maxVowelsImpl);
}

int MaximumNumberOfVowelsInASubstringOfGivenLengthSolution::maxVowels(std::string s, int k) {
  return getSolution()(s, k);
}

}  // namespace problem_1456
}  // namespace leetcode
