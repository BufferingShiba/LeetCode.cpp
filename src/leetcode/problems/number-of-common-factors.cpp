#include "leetcode/problems/number-of-common-factors.h"

#include <algorithm>

namespace leetcode {
namespace problem_2427 {

namespace {

int commonFactorsImpl(int a, int b) {
  const int limit = std::min(a, b);
  int count = 0;
  for (int x = 1; x <= limit; ++x) {
    if (a % x == 0 && b % x == 0) {
      ++count;
    }
  }
  return count;
}

}  // namespace

NumberOfCommonFactorsSolution::NumberOfCommonFactorsSolution() {
  setMetaInfo({.id = 2427,
               .title = "Number of Common Factors",
               .url = "https://leetcode.com/problems/number-of-common-factors/"});
  registerStrategy(
      {.name = "enumeration",
       .expected = "Accepted",
       .time_complexity = "O(min(a, b))",
       .space_complexity = "O(1)",
       .tags = {"Math", "Enumeration", "Number Theory"}},
      commonFactorsImpl);
}

int NumberOfCommonFactorsSolution::commonFactors(int a, int b) {
  return getSolution()(a, b);
}

}  // namespace problem_2427
}  // namespace leetcode
