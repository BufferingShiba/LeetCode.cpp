#include "leetcode/problems/length-of-the-longest-valid-substring.h"

#include <string>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_2781 {

namespace {

int longestValidSubstringImpl(std::string word, std::vector<std::string>& forbidden) {
  std::unordered_set<std::string> forb(forbidden.begin(), forbidden.end());
  const int n = static_cast<int>(word.size());
  int left = 0;
  int best = 0;

  // Max forbidden pattern length is at most 10.
  for (int right = 0; right < n; ++right) {
    // Check suffixes ending at `right`, bounded by the current window start.
    for (int i = right; i >= left && right - i + 1 <= 10; --i) {
      if (forb.count(word.substr(i, right - i + 1))) {
        left = i + 1;  // Any window starting at or before `i` contains a forbidden substring.
        break;
      }
    }
    best = std::max(best, right - left + 1);
  }
  return best;
}

}  // namespace

LengthOfTheLongestValidSubstringSolution::LengthOfTheLongestValidSubstringSolution() {
  setMetaInfo({.id = 2781,
               .title = "Length_of_the_Longest_Valid_Substring",
               .url = "https://leetcode.com/problems/length-of-the-longest-valid-substring/"});

  registerStrategy(
      {.name = "sliding-window",
       .expected = "Accepted",
       .time_complexity = "O(n * 10)",
       .space_complexity = "O(sum of forbidden lengths)",
       .tags = {"sliding-window", "hash-set", "string"}},
      longestValidSubstringImpl);
}

int LengthOfTheLongestValidSubstringSolution::longestValidSubstring(
    std::string word, std::vector<std::string>& forbidden) {
  return getSolution()(std::move(word), forbidden);
}

}  // namespace problem_2781
}  // namespace leetcode
