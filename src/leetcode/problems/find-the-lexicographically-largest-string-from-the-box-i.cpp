#include "leetcode/problems/find-the-lexicographically-largest-string-from-the-box-i.h"

#include <algorithm>
#include <string>

namespace leetcode {
namespace problem_3403 {

static std::string answerStringImpl(std::string word, int numFriends) {
  int n = static_cast<int>(word.size());
  int k = numFriends;

  if (k == 1) return word;

  char maxChar = *std::max_element(word.begin(), word.end());

  int bestStart = -1;
  int bestLen = 0;

  for (int i = 0; i < n; ++i) {
    if (word[i] != maxChar) continue;

    int len = 0;
    if (k == 2) {
      // For k=2, only two boundary cases are valid.
      if (i == 0) {
        len = n - 1;  // suffix must be non-empty
      } else {
        len = n - i;  // must reach the end
      }
    } else {
      // k >= 3: any length up to n - k + 1 is valid.
      len = std::min(n - i, n - k + 1);
    }

    // Compare with current best candidate.
    if (bestStart == -1) {
      bestStart = i;
      bestLen = len;
      continue;
    }

    int cmpLen = std::min(len, bestLen);
    bool isLarger = false;
    bool diffFound = false;
    for (int j = 0; j < cmpLen; ++j) {
      if (word[i + j] != word[bestStart + j]) {
        isLarger = word[i + j] > word[bestStart + j];
        diffFound = true;
        break;
      }
    }
    if (!diffFound) {
      // All compared characters equal: longer string is larger.
      isLarger = len > bestLen;
    }

    if (isLarger) {
      bestStart = i;
      bestLen = len;
    }
  }

  return word.substr(bestStart, bestLen);
}

FindTheLexicographicallyLargestStringFromTheBoxISolution::
    FindTheLexicographicallyLargestStringFromTheBoxISolution() {
  setMetaInfo({.id = 3403,
               .title = "Find the Lexicographically Largest String From the Box I",
               .url = "https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/"});
  registerStrategy(
      {.name = "Greedy Max Char",
       .expected = "Accepted",
       .time_complexity = "O(n^2)",
       .space_complexity = "O(1)",
       .tags = {"Two Pointers", "String", "Enumeration"}},
      answerStringImpl);
  setDefaultStrategy();
}

std::string FindTheLexicographicallyLargestStringFromTheBoxISolution::answerString(
    std::string word, int numFriends) {
  return getSolution()(std::move(word), numFriends);
}

}  // namespace problem_3403
}  // namespace leetcode
