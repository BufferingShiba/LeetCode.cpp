#include "leetcode/problems/count-valid-word-occurrences.h"

#include <unordered_map>

namespace leetcode {
namespace problem_3926 {
namespace {

bool isLower(char c) { return c >= 'a' && c <= 'z'; }

std::vector<int> countByScan(std::vector<std::string>& chunks,
                             std::vector<std::string>& queries) {
  // Concatenate chunks into s.
  std::string s;
  for (const auto& c : chunks) {
    s += c;
  }

  // Extract words. A '-': joiner if previous and next chars both exist and are lowercase.
  std::unordered_map<std::string, int> wordCount;
  const int n = static_cast<int>(s.size());
  int i = 0;
  while (i < n) {
    // Skip separators: spaces and non-joiner hyphens.
    if (s[i] == ' ') {
      ++i;
      continue;
    }
    if (s[i] == '-') {
      // Joiner if prev and next are lowercase.
      bool prevLower = (i > 0) && isLower(s[i - 1]);
      bool nextLower = (i + 1 < n) && isLower(s[i + 1]);
      if (!(prevLower && nextLower)) {
        ++i;
        continue;
      }
    }
    // Start of a word.
    std::string word;
    while (i < n) {
      if (s[i] == ' ') {
        break;
      }
      if (s[i] == '-') {
        // Joiner if prev and next are lowercase.
        bool prevLower = (i > 0) && isLower(s[i - 1]);
        bool nextLower = (i + 1 < n) && isLower(s[i + 1]);
        if (!(prevLower && nextLower)) {
          break;
        }
      }
      word.push_back(s[i]);
      ++i;
    }
    // Accumulate the word.
    if (!word.empty()) {
      ++wordCount[word];
    }
  }

  std::vector<int> ans;
  ans.reserve(queries.size());
  for (const auto& q : queries) {
    auto it = wordCount.find(q);
    ans.push_back(it == wordCount.end() ? 0 : it->second);
  }
  return ans;
}

}  // namespace

CountValidWordOccurrencesSolution::CountValidWordOccurrencesSolution() {
  setMetaInfo({.id = 3926,
               .title = "Count Valid Word Occurrences",
               .url = "https://leetcode.com/problems/count-valid-word-occurrences/"});

  registerStrategy({.name = "ScanAndHash",
                    .expected = "Accepted",
                    .time_complexity = "O(N + Q)",
                    .space_complexity = "O(N)",
                    .tags = {"String", "Hash Table", "Counting"}},
                   countByScan);
}

std::vector<int> CountValidWordOccurrencesSolution::countWordOccurrences(
    std::vector<std::string>& chunks, std::vector<std::string>& queries) {
  return getSolution()(chunks, queries);
}

}  // namespace problem_3926
}  // namespace leetcode
