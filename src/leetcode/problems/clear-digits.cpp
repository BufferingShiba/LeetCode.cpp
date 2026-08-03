#include "leetcode/problems/clear-digits.h"

#include <cctype>
#include <string>

namespace leetcode::problem_3174 {

static std::string clearDigitsImpl(std::string s) {
  std::string stk;
  for (char c : s) {
    if (std::isdigit(static_cast<unsigned char>(c))) {
      if (!stk.empty()) {
        stk.pop_back();
      }
    } else {
      stk.push_back(c);
    }
  }
  return stk;
}

ClearDigitsSolution::ClearDigitsSolution() {
  setMetaInfo({.id = 3174, .title = "Clear Digits", .url = "https://leetcode.com/problems/clear-digits/"});
  registerStrategy(
      {.name = "Stack Simulation",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"String", "Stack", "Simulation"}},
      clearDigitsImpl);
}

std::string ClearDigitsSolution::clearDigits(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace leetcode::problem_3174
