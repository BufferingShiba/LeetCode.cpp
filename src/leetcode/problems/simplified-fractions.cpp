#include "leetcode/problems/simplified-fractions.h"

#include <numeric>

namespace leetcode {
namespace problem_1447 {

namespace {

std::vector<std::string> enumerateFractions(int n) {
  std::vector<std::string> result;
  for (int denominator = 2; denominator <= n; ++denominator) {
    for (int numerator = 1; numerator < denominator; ++numerator) {
      if (std::gcd(numerator, denominator) == 1) {
        result.push_back(std::to_string(numerator) + "/" +
                         std::to_string(denominator));
      }
    }
  }
  return result;
}

}  // namespace

SimplifiedFractionsSolution::SimplifiedFractionsSolution() {
  setMetaInfo({.id = 1447,
               .title = "Simplified Fractions",
               .url = "https://leetcode.com/problems/simplified-fractions/"});
  registerStrategy({.name = "CoprimeEnumeration",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2 log n)",
                    .space_complexity = "O(n^2)",
                    .tags = {"Math", "String", "Number Theory"}},
                   enumerateFractions);
}

}  // namespace problem_1447
}  // namespace leetcode
