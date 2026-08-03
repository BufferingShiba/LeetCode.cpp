#include "leetcode/problems/calculate-digit-sum-of-a-string.h"

namespace leetcode {
namespace problem_2243 {

static std::string digitSumImpl(std::string s, int k) {
  while (static_cast<int>(s.size()) > k) {
    std::string next;
    int sum = 0;
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
      sum += s[i] - '0';
      if ((i + 1) % k == 0 || i == static_cast<int>(s.size()) - 1) {
        next += std::to_string(sum);
        sum = 0;
      }
    }
    s = std::move(next);
  }
  return s;
}

CalculateDigitSumOfAStringSolution::CalculateDigitSumOfAStringSolution() {
  setMetaInfo({.id = 2243, .title = "Calculate Digit Sum of a String",
               .url = "https://leetcode.com/problems/calculate-digit-sum-of-a-string/"});
  registerStrategy(
      {.name = "Simulation",
       .expected = "Accepted",
       .time_complexity = "O(n * rounds)",
       .space_complexity = "O(n)",
       .tags = {"String", "Simulation"}},
      digitSumImpl);
  setDefaultStrategy();
}

}  // namespace problem_2243
}  // namespace leetcode
