#include "leetcode/problems/capitalize-the-title.h"

#include <cctype>

namespace leetcode::problem_2129 {

namespace {

std::string capitalizeTitleImpl(std::string title) {
  const int n = static_cast<int>(title.size());
  int i = 0;
  while (i < n) {
    int j = i;
    while (j < n && title[j] != ' ') {
      ++j;
    }
    const int len = j - i;
    if (len <= 2) {
      for (int k = i; k < j; ++k) {
        title[k] = static_cast<char>(std::tolower(static_cast<unsigned char>(title[k])));
      }
    } else {
      title[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(title[i])));
      for (int k = i + 1; k < j; ++k) {
        title[k] = static_cast<char>(std::tolower(static_cast<unsigned char>(title[k])));
      }
    }
    i = j + 1;
  }
  return title;
}

}  // namespace

CapitalizeTheTitleSolution::CapitalizeTheTitleSolution() {
  setMetaInfo({.id = 2129,
               .title = "Capitalize the Title",
               .url = "https://leetcode.com/problems/capitalize-the-title/"});
  registerStrategy(
      {.name = "single-pass-wordwise",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Two Pointers"}},
      capitalizeTitleImpl);
}

std::string CapitalizeTheTitleSolution::capitalizeTitle(const std::string& title) const {
  return getSolution()(title);
}

}  // namespace leetcode::problem_2129
