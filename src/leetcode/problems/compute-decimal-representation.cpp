#include "leetcode/problems/compute-decimal-representation.h"
#include <cmath>

namespace leetcode::problem_3697 {

namespace {

std::vector<int> decimalRepresentationImpl(int n) {
  std::vector<int> result;
  long long power = 1;
  // compute the highest power of 10 <= n
  while (power * 10 <= n) {
    power *= 10;
  }
  int remain = n;
  while (power > 0) {
    int digit = remain / static_cast<int>(power);
    if (digit > 0) {
      result.push_back(digit * static_cast<int>(power));
    }
    remain -= digit * static_cast<int>(power);
    power /= 10;
  }
  return result;
}

}  // namespace

ComputeDecimalRepresentationSolution::ComputeDecimalRepresentationSolution() {
  setMetaInfo({.id = 3697,
               .title = "Compute Decimal Representation",
               .url = "https://leetcode.com/problems/compute-decimal-representation/"});
  registerStrategy(
      {.name = "decimal_place_greedy",
       .expected = "Accepted",
       .time_complexity = "O(log10 n)",
       .space_complexity = "O(log10 n)",
       .tags = {"Array", "Math"}},
      decimalRepresentationImpl);
}

std::vector<int> ComputeDecimalRepresentationSolution::decimalRepresentation(
    int n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_3697
