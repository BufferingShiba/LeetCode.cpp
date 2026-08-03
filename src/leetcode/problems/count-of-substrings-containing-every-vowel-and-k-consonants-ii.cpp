#include "leetcode/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii.h"

#include <algorithm>
#include <string>

namespace leetcode {
namespace problem_3306 {

namespace {

bool isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

long long countOfSubstringsImpl(std::string word, int k) {
  int n = static_cast<int>(word.size());
  long long ans = 0;

  int left1 = 0;  // smallest l with ≤ k consonants
  int left2 = 0;  // smallest l with ≤ k-1 consonants
  int cons1 = 0;
  int cons2 = 0;

  int last_a = -1, last_e = -1, last_i = -1, last_o = -1, last_u = -1;

  for (int r = 0; r < n; ++r) {
    char c = word[r];

    // update last vowel positions
    if (c == 'a') {
      last_a = r;
    } else if (c == 'e') {
      last_e = r;
    } else if (c == 'i') {
      last_i = r;
    } else if (c == 'o') {
      last_o = r;
    } else if (c == 'u') {
      last_u = r;
    } else {
      ++cons1;
      ++cons2;
    }

    // maintain left1: window [left1, r] has ≤ k consonants
    while (left1 <= r && cons1 > k) {
      if (!isVowel(word[left1])) --cons1;
      ++left1;
    }

    // maintain left2: window [left2, r] has ≤ k-1 consonants
    while (left2 <= r && cons2 > k - 1) {
      if (!isVowel(word[left2])) --cons2;
      ++left2;
    }

    // need all 5 vowels present
    int maxVowelL = std::min({last_a, last_e, last_i, last_o, last_u});
    if (maxVowelL == -1) continue;

    // valid left indices: intersection of [left1, left2-1] and [0, maxVowelL]
    int L = left1;
    int R = std::min(left2 - 1, maxVowelL);
    if (R >= L) {
      ans += R - L + 1;
    }
  }

  return ans;
}

}  // namespace

CountOfSubstringsContainingEveryVowelAndKConsonantsIiSolution::
    CountOfSubstringsContainingEveryVowelAndKConsonantsIiSolution() {
  setMetaInfo({.id = 3306,
               .title = "Count of Substrings Containing Every Vowel and K "
                        "Consonants II",
               .url =
                   "https://leetcode.com/problems/"
                   "count-of-substrings-containing-every-vowel-and-k-consonants-ii/"});

  registerStrategy({.name = "sliding_window",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Hash Table", "String", "Sliding Window"}},
                   countOfSubstringsImpl);
}

long long CountOfSubstringsContainingEveryVowelAndKConsonantsIiSolution::
    countOfSubstrings(std::string word, int k) {
  return getSolution()(word, k);
}

}  // namespace problem_3306
}  // namespace leetcode
