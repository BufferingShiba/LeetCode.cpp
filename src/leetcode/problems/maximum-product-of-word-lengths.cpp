#include "leetcode/problems/maximum-product-of-word-lengths.h"

namespace leetcode {
namespace problem_318 {
namespace {

int maxProductBitmask(std::vector<std::string>& words) {
  const int n = static_cast<int>(words.size());
  std::vector<int> masks(n, 0);
  std::vector<int> lens(n, 0);
  for (int i = 0; i < n; ++i) {
    lens[i] = static_cast<int>(words[i].size());
    int mask = 0;
    for (char c : words[i]) {
      mask |= 1 << (c - 'a');
    }
    masks[i] = mask;
  }

  int best = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if ((masks[i] & masks[j]) == 0) {
        best = std::max(best, lens[i] * lens[j]);
      }
    }
  }
  return best;
}

}  // namespace

MaximumProductOfWordLengthsSolution::MaximumProductOfWordLengthsSolution() {
  setMetaInfo({.id = 318,
               .title = "Maximum Product of Word Lengths",
               .url = "https://leetcode.com/problems/maximum-product-of-word-lengths/"});
  registerStrategy(
      {.name = "Bitmask + O(n^2) Scan",
       .expected = "Accepted",
       .time_complexity = "O(n^2 + total_letters)",
       .space_complexity = "O(n)",
       .tags = {"Bit Manipulation", "Array"},
       .notes =
           "Map each word to a 26-bit mask of letters. Two words share no "
           "letter iff their masks AND to 0. Enumerate all pairs."},
      maxProductBitmask);
}

}  // namespace problem_318
}  // namespace leetcode
