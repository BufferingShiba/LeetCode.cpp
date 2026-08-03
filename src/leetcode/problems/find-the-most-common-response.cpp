#include "leetcode/problems/find-the-most-common-response.h"

#include <string>
#include <unordered_map>
#include <unordered_set>

namespace leetcode {
namespace problem_3527 {

static string solution1(vector<vector<string>>& responses) {
  std::unordered_map<std::string, int> freq;
  for (const auto& day : responses) {
    std::unordered_set<std::string> seen;
    for (const auto& resp : day) {
      if (seen.insert(resp).second) {
        ++freq[resp];
      }
    }
  }

  std::string best;
  int bestCount = -1;
  for (const auto& [resp, count] : freq) {
    if (count > bestCount ||
        (count == bestCount && resp < best)) {
      best = resp;
      bestCount = count;
    }
  }
  return best;
}

FindTheMostCommonResponseSolution::FindTheMostCommonResponseSolution() {
  setMetaInfo({
      .id = 3527,
      .title = "Find the Most Common Response",
      .url = "https://leetcode.com/problems/find-the-most-common-response"
  });
  registerStrategy(
      {.name = "Hash Map Dedup",
       .expected = "Accepted",
       .time_complexity = "O(N*M)",
       .space_complexity = "O(N*M)",
       .tags = {"Hash Table"},
       .notes = "Dedupe per day with a set, then count global frequency."},
      solution1);
}

string FindTheMostCommonResponseSolution::findCommonResponse(vector<vector<string>>& responses) {
  return getSolution()(responses);
}

}  // namespace problem_3527
}  // namespace leetcode
