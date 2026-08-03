#include "leetcode/problems/rearrange-spaces-between-words.h"

#include <sstream>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1592 {

namespace {

std::string reorderSpacesImpl(std::string text) {
  int total_spaces = 0;
  for (char c : text) {
    if (c == ' ') {
      total_spaces++;
    }
  }

  std::vector<std::string> words;
  std::istringstream iss(text);
  std::string word;
  while (iss >> word) {
    words.push_back(word);
  }

  if (words.size() == 1) {
    return words[0] + std::string(total_spaces, ' ');
  }

  int gap_spaces = total_spaces / (static_cast<int>(words.size()) - 1);
  int extra_spaces = total_spaces % (static_cast<int>(words.size()) - 1);

  std::string result;
  for (size_t i = 0; i < words.size(); ++i) {
    result += words[i];
    if (i < words.size() - 1) {
      result += std::string(gap_spaces, ' ');
    }
  }
  result += std::string(extra_spaces, ' ');

  return result;
}

}  // namespace

RearrangeSpacesBetweenWordsSolution::RearrangeSpacesBetweenWordsSolution() {
  setMetaInfo({.id = 1592,
               .title = "Rearrange Spaces Between Words",
               .url = "https://leetcode.com/problems/rearrange-spaces-between-words/"});

  registerStrategy(
      {.name = "Counting & Joining",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"String", "Simulation"}},
      reorderSpacesImpl);
}

std::string RearrangeSpacesBetweenWordsSolution::reorderSpaces(std::string text) {
  return getSolution()(text);
}

}  // namespace problem_1592
}  // namespace leetcode
