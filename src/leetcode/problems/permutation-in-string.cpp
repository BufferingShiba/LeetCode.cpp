#include "leetcode/problems/permutation-in-string.h"

namespace leetcode {
namespace problem_567 {

static bool checkInclusionImpl(std::string s1, std::string s2) {
  int n1 = static_cast<int>(s1.size());
  int n2 = static_cast<int>(s2.size());
  if (n1 > n2) return false;

  int target[26] = {0};
  int window[26] = {0};

  for (char c : s1) {
    target[c - 'a']++;
  }

  // initial window of size n1
  for (int i = 0; i < n1; ++i) {
    window[s2[i] - 'a']++;
  }

  // count how many characters have matching frequencies
  int matches = 0;
  for (int i = 0; i < 26; ++i) {
    if (target[i] == window[i]) ++matches;
  }
  if (matches == 26) return true;

  // slide the window
  for (int i = n1; i < n2; ++i) {
    // add right char
    int r = s2[i] - 'a';
    window[r]++;
    if (window[r] == target[r]) {
      ++matches;
    } else if (window[r] == target[r] + 1) {
      --matches;
    }

    // remove left char
    int l = s2[i - n1] - 'a';
    window[l]--;
    if (window[l] == target[l]) {
      ++matches;
    } else if (window[l] == target[l] - 1) {
      --matches;
    }

    if (matches == 26) return true;
  }

  return false;
}

PermutationInStringSolution::PermutationInStringSolution() {
  setMetaInfo({.id = 567,
               .title = "Permutation in String",
               .url = "https://leetcode.com/problems/permutation-in-string/"});

  registerStrategy(
      {.name = "SlidingWindow",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "Two Pointers", "String", "Sliding Window"}},
      checkInclusionImpl);

  setDefaultStrategy();
}

bool PermutationInStringSolution::checkInclusion(std::string s1, std::string s2) {
  return getSolution()(s1, s2);
}

}  // namespace problem_567
}  // namespace leetcode
