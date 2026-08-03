#include "leetcode/problems/find-the-key-of-the-numbers.h"

#include <algorithm>

namespace leetcode::problem_3270 {

namespace {

int generateKeyImpl(int num1, int num2, int num3) {
  int result = 0;
  int multiplier = 1;
  for (int i = 0; i < 4; ++i) {
    int d1 = num1 % 10;
    int d2 = num2 % 10;
    int d3 = num3 % 10;
    int minDigit = std::min({d1, d2, d3});
    result += minDigit * multiplier;
    multiplier *= 10;
    num1 /= 10;
    num2 /= 10;
    num3 /= 10;
  }
  return result;
}

}  // namespace

FindTheKeyOfTheNumbersSolution::FindTheKeyOfTheNumbersSolution() {
  setMetaInfo({.id = 3270, .title = "Find the Key of the Numbers",
               .url = "https://leetcode.com/problems/find-the-key-of-the-numbers/"});

  registerStrategy(
      {.name = "digit-by-digit",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math"}},
      generateKeyImpl);
}

int FindTheKeyOfTheNumbersSolution::generateKey(int num1, int num2, int num3) {
  return getSolution()(num1, num2, num3);
}

}  // namespace leetcode::problem_3270
