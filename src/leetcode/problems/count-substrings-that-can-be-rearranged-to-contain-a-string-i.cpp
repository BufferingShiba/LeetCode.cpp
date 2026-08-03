#include "leetcode/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-i.h"

#include <array>
#include <string>

namespace leetcode::problem_3297 {

namespace {

long long validSubstringCountImpl(std::string word1, std::string word2) {
  std::array<int, 26> need{};
  int missing = 0;
  for (char c : word2) {
    if (need[c - 'a'] == 0) {
      ++missing;
    }
    ++need[c - 'a'];
  }

  std::array<int, 26> have{};
  long long ans = 0;
  const int n = static_cast<int>(word1.size());
  int left = 0;

  for (int right = 0; right < n; ++right) {
    const int ch = word1[right] - 'a';
    ++have[ch];
    if (have[ch] == need[ch]) {
      --missing;
    }
    while (missing == 0) {
      ans += static_cast<long long>(n - right);
      const int lc = word1[left] - 'a';
      if (have[lc] == need[lc]) {
        ++missing;
      }
      --have[lc];
      ++left;
    }
  }
  return ans;
}

}  // namespace

long long CountSubstringsThatCanBeRearrangedToContainAStringISolution::
    validSubstringCount(std::string word1, std::string word2) {
  return getSolution()(std::move(word1), std::move(word2));
}

CountSubstringsThatCanBeRearrangedToContainAStringISolution::
    CountSubstringsThatCanBeRearrangedToContainAStringISolution() {
  setMetaInfo({.id = 3297,
               .title = "Count Substrings That Can Be Rearranged to Contain a "
                        "String I",
               .url = "https://leetcode.com/problems/"
                      "count-substrings-that-can-be-rearranged-to-contain-a-"
                      "string-i/"});

  registerStrategy(
      {.name = "slidingWindow",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String", "Sliding Window"}},
      validSubstringCountImpl);
}

}  // namespace leetcode::problem_3297
