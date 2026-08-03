#include "leetcode/problems/find-the-lexicographically-smallest-valid-sequence.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode::problem_3302 {

namespace {

// Greedy with suffix-matching preprocessing.
std::vector<int> validSequenceImpl(const std::string& word1,
                                   const std::string& word2) {
  const int n = static_cast<int>(word1.size());
  const int m = static_cast<int>(word2.size());

  // suffix[i] = the smallest start index L in word2 such that word1[i..]
  // can strictly match word2[L..] (maximal suffix matched strictly).
  // suffix[n] == m by convention (empty remaining always matches).
  std::vector<int> suffix(n + 1, m);
  int need = m - 1;
  for (int i = n - 1; i >= 0; --i) {
    if (need >= 0 && word1[i] == word2[need]) {
      --need;
    }
    suffix[i] = need + 1;
  }

  std::vector<int> ans;
  ans.reserve(m);
  int j = 0;      // already matched word2[0..j-1]
  int rem = 1;    // change opportunities left
  for (int i = 0; i < n && j < m; ++i) {
    if (word1[i] == word2[j]) {
      ans.push_back(i);
      ++j;
    } else if (rem > 0 && suffix[i + 1] <= j + 1) {
      // Change word1[i] into word2[j]; the rest must be strictly matched
      // by word1[i+1..], i.e. suffix[i+1] covers word2[j+1..].
      --rem;
      ans.push_back(i);
      ++j;
    }
  }

  if (j != m) {
    return {};
  }
  return ans;
}

}  // namespace

std::vector<int> FindTheLexicographicallySmallestValidSequenceSolution::
    validSequence(std::string word1, std::string word2) {
  return getSolution()(std::move(word1), std::move(word2));
}

FindTheLexicographicallySmallestValidSequenceSolution::
    FindTheLexicographicallySmallestValidSequenceSolution() {
  setMetaInfo(
      {.id = 3302,
       .title = "Find the Lexicographically Smallest Valid Sequence",
       .url = "https://leetcode.com/problems/"
              "find-the-lexicographically-smallest-valid-sequence/"});
  registerStrategy(
      {.name = "SuffixPreprocessGreedy",
       .expected = "Accepted",
       .time_complexity = "O(n + m)",
       .space_complexity = "O(n)",
       .tags = {"String", "Dynamic Programming", "Greedy", "Two Pointers"}},
      validSequenceImpl);
}

}  // namespace leetcode::problem_3302
