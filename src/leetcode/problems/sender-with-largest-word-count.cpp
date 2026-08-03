#include "leetcode/problems/sender-with-largest-word-count.h"

#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_2284 {

namespace {

std::string largestWordCountImpl(std::vector<std::string>& messages,
                                 std::vector<std::string>& senders) {
  std::unordered_map<std::string, int> count;
  for (int i = 0; i < static_cast<int>(messages.size()); ++i) {
    int words = 1;
    for (char c : messages[i]) {
      if (c == ' ') ++words;
    }
    count[senders[i]] += words;
  }

  std::string best;
  int bestCount = -1;
  for (const auto& [name, words] : count) {
    if (words > bestCount || (words == bestCount && name > best)) {
      best = name;
      bestCount = words;
    }
  }
  return best;
}

}  // namespace

SenderWithLargestWordCountSolution::SenderWithLargestWordCountSolution() {
  setMetaInfo({.id = 2284,
               .title = "Sender With Largest Word Count",
               .url = "https://leetcode.com/problems/sender-with-largest-word-count/"});
  registerStrategy(
      {.name = "hashmap_count",
       .expected = "Accepted",
       .time_complexity = "O(total chars)",
       .space_complexity = "O(number of distinct senders)",
       .tags = {"Array", "Hash Table", "String", "Counting"},
       .notes =
           "Count words per sender, then pick max with lexicographically largest tie-break."},
      largestWordCountImpl);
  setDefaultStrategy();
}

}  // namespace problem_2284
}  // namespace leetcode
