#include "leetcode/problems/check-if-it-is-a-good-array.h"

#include <numeric>

namespace leetcode {
namespace problem_1250 {

namespace {

bool isGoodArrayImpl(std::vector<int>& nums) {
  int g = 0;
  for (int x : nums) {
    g = std::gcd(g, x);
    if (g == 1) {
      return true;
    }
  }
  return g == 1;
}

}  // namespace

CheckIfItIsAGoodArraySolution::CheckIfItIsAGoodArraySolution() {
  setMetaInfo({.id = 1250,
               .title = "Check If It Is a Good Array",
               .url = "https://leetcode.com/problems/check-if-it-is-a-good-array/"});

  registerStrategy(
      {.name = "GCD",
       .expected = "Accepted",
       .time_complexity = "O(N log M)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Math", "Number Theory"}},
      isGoodArrayImpl);

  setDefaultStrategy();
}

bool CheckIfItIsAGoodArraySolution::isGoodArray(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_1250
}  // namespace leetcode
