#include "leetcode/problems/maximum-difference-between-even-and-odd-frequency-i.h"

#include <algorithm>
#include <climits>
#include <string>

namespace leetcode {
namespace problem_3442 {

static int maxDifferenceImpl(std::string s) {
  int freq[26] = {0};
  for (char c : s) {
    ++freq[c - 'a'];
  }

  int max_odd = 0;
  int min_even = INT_MAX;

  for (int i = 0; i < 26; ++i) {
    if (freq[i] == 0) continue;
    if (freq[i] % 2 == 1) {
      max_odd = std::max(max_odd, freq[i]);
    } else {
      min_even = std::min(min_even, freq[i]);
    }
  }

  return max_odd - min_even;
}

MaximumDifferenceBetweenEvenAndOddFrequencyISolution::MaximumDifferenceBetweenEvenAndOddFrequencyISolution() {
  setMetaInfo({.id = 3442,
               .title = "Maximum Difference Between Even and Odd Frequency I",
               .url = "https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/"});
  registerStrategy({.name = "Frequency Count",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Hash Table", "String", "Counting"}},
                   maxDifferenceImpl);
}

int MaximumDifferenceBetweenEvenAndOddFrequencyISolution::maxDifference(std::string s) {
  return getSolution()(s);
}

}  // namespace problem_3442
}  // namespace leetcode
