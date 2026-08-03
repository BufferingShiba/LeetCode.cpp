#include "leetcode/problems/search-suggestions-system.h"

#include <algorithm>

namespace leetcode {
namespace problem_1268 {
namespace {

std::vector<std::vector<std::string>> sortedPrefixStrategy(
    std::vector<std::string>& products, std::string searchWord) {
  std::sort(products.begin(), products.end());

  std::vector<std::vector<std::string>> suggestions;
  suggestions.reserve(searchWord.size());
  std::string prefix;
  prefix.reserve(searchWord.size());

  for (char ch : searchWord) {
    prefix.push_back(ch);
    const auto first = std::lower_bound(products.begin(), products.end(), prefix);
    std::vector<std::string> matches;
    for (auto it = first; it != products.end() && matches.size() < 3; ++it) {
      if (it->compare(0, prefix.size(), prefix) != 0) break;
      matches.push_back(*it);
    }
    suggestions.push_back(std::move(matches));
  }
  return suggestions;
}

}  // namespace

SearchSuggestionsSystemSolution::SearchSuggestionsSystemSolution() {
  setMetaInfo({.id = 1268,
               .title = "Search Suggestions System",
               .url = "https://leetcode.com/problems/search-suggestions-system/"});
  registerStrategy(
      {.name = "SortedPrefixLowerBound",
       .expected = "Accepted",
       .time_complexity = "O(n log n + m log n + 3m)",
       .space_complexity = "O(n + m)",
       .tags = {"Array", "String", "Binary Search", "Sorting"}},
      sortedPrefixStrategy);
}

}  // namespace problem_1268
}  // namespace leetcode
