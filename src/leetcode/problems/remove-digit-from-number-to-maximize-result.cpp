#include "leetcode/problems/remove-digit-from-number-to-maximize-result.h"

#include <string>

namespace leetcode {
namespace problem_2259 {

static std::string removeDigitImpl(std::string number, char digit) {
  int n = static_cast<int>(number.size());
  int lastPos = -1;

  for (int i = 0; i < n; ++i) {
    if (number[i] == digit) {
      lastPos = i;
      // 贪心：如果后一位更大，立即移除此处 digit
      if (i + 1 < n && number[i + 1] > digit) {
        return number.substr(0, i) + number.substr(i + 1);
      }
    }
  }

  // 没有满足贪心条件的位置，移除最后一个 digit
  return number.substr(0, lastPos) + number.substr(lastPos + 1);
}

RemoveDigitFromNumberToMaximizeResultSolution::RemoveDigitFromNumberToMaximizeResultSolution() {
  setMetaInfo({2259,
               "Remove Digit From Number to Maximize Result",
               "https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/"});

  registerStrategy(
      {"Greedy",
       "Accepted",
       "O(n)",
       "O(1)",
       {"String", "Greedy", "Enumeration"},
       ""},
      removeDigitImpl);
  setDefaultStrategy();
}

std::string RemoveDigitFromNumberToMaximizeResultSolution::removeDigit(
    std::string number, char digit) {
  return getSolution()(number, digit);
}

}  // namespace problem_2259
}  // namespace leetcode
