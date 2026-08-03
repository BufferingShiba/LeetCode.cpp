#include "leetcode/problems/maximum-difference-by-remapping-a-digit.h"

#include <string>

namespace leetcode::problem_2566 {

static int minMaxDifferenceImpl(int num) {
  std::string s = std::to_string(num);

  // Maximum: replace first non-'9' digit with '9'
  std::string maxStr = s;
  char maxTarget = 0;
  for (char c : maxStr) {
    if (c != '9') {
      maxTarget = c;
      break;
    }
  }
  if (maxTarget != 0) {
    for (char& c : maxStr) {
      if (c == maxTarget) {
        c = '9';
      }
    }
  }
  int maxVal = std::stoi(maxStr);

  // Minimum: replace first digit (most significant) with '0'
  std::string minStr = s;
  char minTarget = minStr[0];
  for (char& c : minStr) {
    if (c == minTarget) {
      c = '0';
    }
  }
  int minVal = std::stoi(minStr);

  return maxVal - minVal;
}

MaximumDifferenceByRemappingADigitSolution::MaximumDifferenceByRemappingADigitSolution() {
  setMetaInfo({.id = 2566,
               .title = "Maximum Difference by Remapping a Digit",
               .url = "https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/"});
  registerStrategy(
      {.name = "greedy",
       .expected = "Accepted",
       .time_complexity = "O(L)",
       .space_complexity = "O(L)",
       .tags = {"Math", "Greedy"}},
      minMaxDifferenceImpl);
}

int MaximumDifferenceByRemappingADigitSolution::minMaxDifference(int num) {
  return getSolution()(num);
}

}  // namespace leetcode::problem_2566
