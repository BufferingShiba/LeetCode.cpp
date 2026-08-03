#include "leetcode/problems/largest-odd-number-in-string.h"

namespace leetcode {
namespace problem_1903 {

namespace {

std::string largestOddNumberImpl(std::string num) {
  for (int i = static_cast<int>(num.size()) - 1; i >= 0; --i) {
    int digit = num[i] - '0';
    if (digit % 2 == 1) {
      return num.substr(0, i + 1);
    }
  }
  return "";
}

}  // namespace

LargestOddNumberInStringSolution::LargestOddNumberInStringSolution() {
  setMetaInfo({1903, "Largest Odd Number in String",
               "https://leetcode.com/problems/largest-odd-number-in-string/"});
  registerStrategy(
      {"GreedyScanFromRight", "Accepted", "O(n)", "O(1)", {"Greedy", "String"}},
      largestOddNumberImpl);
}

std::string LargestOddNumberInStringSolution::largestOddNumber(std::string num) {
  return getSolution()(std::move(num));
}

}  // namespace problem_1903
}  // namespace leetcode
