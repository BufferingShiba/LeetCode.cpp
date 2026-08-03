#include "leetcode/problems/count-pairs-of-similar-strings.h"

#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode {
namespace problem_2506 {

namespace {

int similarPairsImpl(std::vector<std::string>& words) {
  std::unordered_map<int, int> mask_count;

  for (const auto& word : words) {
    int mask = 0;
    for (char ch : word) {
      mask |= (1 << (ch - 'a'));
    }
    ++mask_count[mask];
  }

  int result = 0;
  for (const auto& [mask, count] : mask_count) {
    if (count >= 2) {
      result += count * (count - 1) / 2;
    }
  }
  return result;
}

}  // namespace

CountPairsOfSimilarStringsSolution::CountPairsOfSimilarStringsSolution() {
  setMetaInfo({.id = 2506,
               .title = "Count Pairs Of Similar Strings",
               .url = "https://leetcode.com/problems/count-pairs-of-similar-strings/"});

  registerStrategy(
      {.name = "Bitmask + Hash Map",
       .expected = "Accepted",
       .time_complexity = "O(n * m)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "String", "Bit Manipulation",
                "Counting"}},
      similarPairsImpl);
}

int CountPairsOfSimilarStringsSolution::similarPairs(
    std::vector<std::string>& words) {
  return getSolution()(words);
}

}  // namespace problem_2506
}  // namespace leetcode
