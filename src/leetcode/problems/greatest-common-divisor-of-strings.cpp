#include "leetcode/problems/greatest-common-divisor-of-strings.h"

#include <numeric>
#include <string>

namespace leetcode {
namespace problem_1071 {

namespace {

std::string gcdOfStringsImpl(std::string str1, std::string str2) {
  if (str1 + str2 != str2 + str1) {
    return "";
  }
  auto len = std::gcd(str1.size(), str2.size());
  return str1.substr(0, len);
}

}  // namespace

GreatestCommonDivisorOfStringsSolution::GreatestCommonDivisorOfStringsSolution() {
  setMetaInfo({.id = 1071,
               .title = "Greatest Common Divisor of Strings",
               .url = "https://leetcode.com/problems/greatest-common-divisor-of-strings/"});

  registerStrategy(
      {.name = "GCD",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Math", "String"}},
      gcdOfStringsImpl);

  setDefaultStrategy();
}

std::string GreatestCommonDivisorOfStringsSolution::gcdOfStrings(std::string str1,
                                                                  std::string str2) {
  return getSolution()(str1, str2);
}

}  // namespace problem_1071
}  // namespace leetcode
