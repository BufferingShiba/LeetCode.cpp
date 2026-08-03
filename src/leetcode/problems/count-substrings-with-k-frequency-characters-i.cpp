#include "leetcode/problems/count-substrings-with-k-frequency-characters-i.h"

namespace leetcode {
namespace problem_3325 {

namespace {

int numberOfSubstringsSlidingWindow(const std::string& s, int k) {
  const int n = static_cast<int>(s.size());
  std::array<int, 26> freq{};
  long long validCount = 0;  // substrings where every char count < k
  int left = 0;

  for (int right = 0; right < n; ++right) {
    ++freq[s[right] - 'a'];
    // Shrink window until all char frequencies are < k.
    while (freq[s[right] - 'a'] >= k) {
      --freq[s[left] - 'a'];
      ++left;
    }
    // All substrings [left'..right] for left' in [left, right] are valid
    // (every char count < k).
    validCount += right - left + 1;
  }

  const long long total = static_cast<long long>(n) * (n + 1) / 2;
  return static_cast<int>(total - validCount);
}

}  // namespace

CountSubstringsWithKFrequencyCharactersISolution::
    CountSubstringsWithKFrequencyCharactersISolution() {
  setMetaInfo({.id = 3325,
               .title = "Count Substrings With K-Frequency Characters I",
               .url = "https://leetcode.com/problems/count-substrings-with-k-frequency-characters-i/"});
  registerStrategy(
      {"sliding-window-complement", "Accepted", "O(n)", "O(1)",
       {"Hash Table", "Sliding Window"}},
      [](std::string s, int k) {
        return numberOfSubstringsSlidingWindow(s, k);
      });
}

int CountSubstringsWithKFrequencyCharactersISolution::numberOfSubstrings(
    std::string s, int k) {
  return getSolution()(std::move(s), k);
}

}  // namespace problem_3325
}  // namespace leetcode
