#include "leetcode/problems/majority-frequency-characters.h"

namespace leetcode {
namespace problem_3692 {

namespace {

std::string majorityFrequencyGroupImpl(std::string s) {
  int freq[26] = {0};
  for (char c : s) {
    ++freq[c - 'a'];
  }

  int bestK = -1;
  int bestSize = -1;
  for (int k = 1; k <= static_cast<int>(s.size()); ++k) {
    int cnt = 0;
    for (int i = 0; i < 26; ++i) {
      if (freq[i] == k) {
        ++cnt;
      }
    }
    if (cnt > bestSize || (cnt == bestSize && k > bestK)) {
      bestSize = cnt;
      bestK = k;
    }
  }

  std::string result;
  for (int i = 0; i < 26; ++i) {
    if (freq[i] == bestK) {
      result.push_back(static_cast<char>('a' + i));
    }
  }
  return result;
}

}  // namespace

MajorityFrequencyCharactersSolution::MajorityFrequencyCharactersSolution() {
  setMetaInfo({.id = 3692,
               .title = "Majority Frequency Characters",
               .url = "https://leetcode.com/problems/majority-frequency-characters/"});
  registerStrategy({.name = "HashTableCounting",
                    .expected = "Accepted",
                    .time_complexity = "O(n + 26)",
                    .space_complexity = "O(1)",
                    .tags = {"Hash Table", "String", "Counting"}},
                   majorityFrequencyGroupImpl);
}

std::string MajorityFrequencyCharactersSolution::majorityFrequencyGroup(
    std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_3692
}  // namespace leetcode
