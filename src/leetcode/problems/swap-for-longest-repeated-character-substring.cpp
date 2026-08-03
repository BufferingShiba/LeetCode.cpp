#include "leetcode/problems/swap-for-longest-repeated-character-substring.h"

#include <array>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_1156 {

static int solution1(string text) {
  // Compress into runs of identical characters: (char, run length).
  std::vector<std::pair<char, int>> groups;
  std::array<int, 26> freq{};
  for (char ch : text) {
    ++freq[ch - 'a'];
    if (groups.empty() || groups.back().first != ch) {
      groups.emplace_back(ch, 1);
    } else {
      ++groups.back().second;
    }
  }

  int best = 0;

  // A single run of c can be extended by 1 if another c exists elsewhere
  // (swap that c with a neighbor adjacent to the run).
  for (const auto& g : groups) {
    int len = g.second;
    int total = freq[g.first - 'a'];
    if (total > len) ++len;  // pull one extra c adjacent to this run.
    best = std::max(best, len);
  }

  // Two same-char runs separated by a single different char can be merged by
  // swapping the separator with a 'c' at the far end of the other run.
  for (int i = 0; i + 2 < static_cast<int>(groups.size()); ++i) {
    if (groups[i].first != groups[i + 2].first || groups[i + 1].second != 1) {
      continue;
    }
    char c = groups[i].first;
    int len = groups[i].second + groups[i + 2].second;
    if (freq[c - 'a'] > len) ++len;  // an extra c lets us fill the gap too.
    best = std::max(best, len);
  }

  return best;
}

SwapForLongestRepeatedCharacterSubstringSolution::SwapForLongestRepeatedCharacterSubstringSolution() {
  setMetaInfo({
      .id = 1156,
      .title = "Swap For Longest Repeated Character Substring",
      .url = "https://leetcode.com/problems/swap-for-longest-repeated-character-substring"
  });
  registerStrategy({.name = "Run Compression"}, solution1);
}

int SwapForLongestRepeatedCharacterSubstringSolution::maxRepOpt1(string text) {
  return getSolution()(text);
}

}  // namespace problem_1156
}  // namespace leetcode
