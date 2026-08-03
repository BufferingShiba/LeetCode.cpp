#include "leetcode/problems/valid-digit-number.h"

#include <string>

namespace leetcode {
namespace problem_3908 {

namespace {

bool validDigitImpl(int n, int x) {
  std::string s = std::to_string(n);
  if (s.front() == ('0' + x)) {
    return false;
  }
  for (char c : s) {
    if (c == ('0' + x)) {
      return true;
    }
  }
  return false;
}

}  // namespace

ValidDigitNumberSolution::ValidDigitNumberSolution() {
  setMetaInfo({.id = 3908,
               .title = "Valid Digit Number",
               .url = "https://leetcode.com/problems/valid-digit-number/"});
  registerStrategy(
      {.name = "string-scan",
       .expected = "Accepted",
       .time_complexity = "O(d)",
       .space_complexity = "O(d)",
       .tags = {"Math"},
       .notes = "Convert n to string; fail if first digit equals x, else succeed on any match"},
      validDigitImpl);
}

bool ValidDigitNumberSolution::validDigit(int n, int x) {
  return getSolution()(n, x);
}

}  // namespace problem_3908
}  // namespace leetcode
