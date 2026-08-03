#include "leetcode/problems/remove-zeros-in-decimal-representation.h"

#include <string>

namespace leetcode {
namespace problem_3726 {

namespace {

long long removeZerosImpl(long long n) {
  std::string s = std::to_string(n);
  std::string filtered;
  filtered.reserve(s.size());
  for (char ch : s) {
    if (ch != '0') {
      filtered.push_back(ch);
    }
  }
  return std::stoll(filtered);
}

}  // namespace

RemoveZerosInDecimalRepresentationSolution::
    RemoveZerosInDecimalRepresentationSolution() {
  setMetaInfo({.id = 3726,
               .title = "Remove Zeros in Decimal Representation",
               .url = "https://leetcode.com/problems/remove-zeros-in-decimal-representation/"});
  registerStrategy(
      {.name = "Simulation",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(log n)",
       .tags = {"Math", "Simulation"}},
      removeZerosImpl);
}

long long RemoveZerosInDecimalRepresentationSolution::removeZeros(long long n) {
  return getSolution()(n);
}

}  // namespace problem_3726
}  // namespace leetcode
