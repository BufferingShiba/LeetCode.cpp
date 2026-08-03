#include "leetcode/problems/print-words-vertically.h"

#include <sstream>

namespace leetcode {
namespace problem_1324 {

namespace {

std::vector<std::string> printVerticallyImpl(std::string s) {
  // Step 1: split into words
  std::vector<std::string> words;
  std::istringstream iss(s);
  std::string word;
  while (iss >> word) {
    words.push_back(word);
  }

  // Step 2: find the maximum word length
  int maxLen = 0;
  for (const auto& w : words) {
    if ((int)w.size() > maxLen) {
      maxLen = (int)w.size();
    }
  }

  // Step 3: build result rows
  std::vector<std::string> result(maxLen);
  for (int i = 0; i < maxLen; ++i) {
    std::string row;
    for (const auto& w : words) {
      if (i < (int)w.size()) {
        row += w[i];
      } else {
        row += ' ';
      }
    }
    // Remove trailing spaces
    while (!row.empty() && row.back() == ' ') {
      row.pop_back();
    }
    result[i] = std::move(row);
  }

  return result;
}

}  // anonymous namespace

PrintWordsVerticallySolution::PrintWordsVerticallySolution() {
  setMetaInfo({.id = 1324,
               .title = "Print Words Vertically",
               .url = "https://leetcode.com/problems/print-words-vertically/"});
  registerStrategy({.name = "Simulation",
                    .expected = "Accepted",
                    .time_complexity = "O(N + W * M)",
                    .space_complexity = "O(N)",
                    .tags = {"Array", "String", "Simulation"}},
                   printVerticallyImpl);
}

std::vector<std::string> PrintWordsVerticallySolution::printVertically(
    std::string s) {
  return getSolution()(s);
}

}  // namespace problem_1324
}  // namespace leetcode
