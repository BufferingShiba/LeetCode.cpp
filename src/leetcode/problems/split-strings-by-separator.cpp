#include <string>
#include <vector>

#include "leetcode/problems/split-strings-by-separator.h"

namespace leetcode::problem_2788 {

namespace {

std::vector<std::string> splitWordsBySeparatorImpl(std::vector<std::string>& words,
                                                   char separator) {
  std::vector<std::string> result;
  for (const std::string& word : words) {
    std::string current;
    for (char ch : word) {
      if (ch == separator) {
        if (!current.empty()) {
          result.push_back(current);
          current.clear();
        }
      } else {
        current.push_back(ch);
      }
    }
    if (!current.empty()) {
      result.push_back(current);
    }
  }
  return result;
}

}  // namespace

SplitStringsBySeparatorSolution::SplitStringsBySeparatorSolution() {
  setMetaInfo({.id = 2788,
               .title = "Split Strings by Separator",
               .url = "https://leetcode.com/problems/split-strings-by-separator/"});
  registerStrategy({.name = "LinearScan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "String"}},
                   splitWordsBySeparatorImpl);
}

std::vector<std::string> SplitStringsBySeparatorSolution::splitWordsBySeparator(
    std::vector<std::string>& words, char separator) {
  return getSolution()(words, separator);
}

}  // namespace leetcode::problem_2788
