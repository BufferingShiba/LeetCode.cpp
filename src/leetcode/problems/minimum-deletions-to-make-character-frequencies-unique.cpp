#include "leetcode/problems/minimum-deletions-to-make-character-frequencies-unique.h"

#include <algorithm>
#include <array>
#include <unordered_set>

namespace leetcode {
namespace problem_1647 {

// Greedy: sort frequencies descending, for each frequency reduce it until it
// hits an unused value (or 0), counting each reduction as one deletion.
namespace {

int minDeletionsImpl(const std::string& s) {
  std::array<int, 26> freq{};
  for (char c : s) {
    freq[c - 'a']++;
  }

  std::vector<int> freqs;
  for (int f : freq) {
    if (f > 0) freqs.push_back(f);
  }
  std::sort(freqs.begin(), freqs.end(), std::greater<int>());

  int deletions = 0;
  std::unordered_set<int> used;
  for (int f : freqs) {
    while (f > 0 && used.count(f) > 0) {
      --f;
      ++deletions;
    }
    if (f > 0) {
      used.insert(f);
    }
  }
  return deletions;
}

}  // namespace

MinimumDeletionsToMakeCharacterFrequenciesUniqueSolution::
    MinimumDeletionsToMakeCharacterFrequenciesUniqueSolution() {
  setMetaInfo({.id = 1647,
               .title = "Minimum Deletions to Make Character Frequencies Unique",
               .url = "https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/"});
  registerStrategy(
      {"GreedyHashTable",
       "Accepted",
       "O(n)",
       "O(n)",
       {"Hash Table", "String", "Greedy", "Sorting"}},
      minDeletionsImpl);
}

int MinimumDeletionsToMakeCharacterFrequenciesUniqueSolution::minDeletions(
    std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_1647
}  // namespace leetcode
