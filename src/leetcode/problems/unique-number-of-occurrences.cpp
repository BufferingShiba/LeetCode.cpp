#include "leetcode/problems/unique-number-of-occurrences.h"

#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace {

bool uniqueOccurrencesImpl(std::vector<int>& arr) {
  std::unordered_map<int, int> count;
  for (int v : arr) {
    ++count[v];
  }
  std::unordered_set<int> seen;
  for (const auto& kv : count) {
    if (!seen.insert(kv.second).second) {
      return false;
    }
  }
  return true;
}

}  // namespace

UniqueNumberOfOccurrencesSolution::UniqueNumberOfOccurrencesSolution() {
  setMetaInfo({.id = 1207,
               .title = "Unique Number of Occurrences",
               .url = "https://leetcode.com/problems/unique-number-of-occurrences/"});
  registerStrategy(
      {.name = "HashTableCounting",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table"}},
      uniqueOccurrencesImpl);
}

bool UniqueNumberOfOccurrencesSolution::uniqueOccurrences(std::vector<int>& arr) {
  return getSolution()(arr);
}

}  // namespace leetcode
