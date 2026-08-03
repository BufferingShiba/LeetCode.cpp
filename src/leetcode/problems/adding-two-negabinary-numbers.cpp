#include "leetcode/problems/adding-two-negabinary-numbers.h"

#include <algorithm>
#include <vector>

namespace leetcode {
namespace problem_1073 {

namespace {

std::vector<int> addNegabinaryImpl(std::vector<int>& arr1, std::vector<int>& arr2) {
  std::vector<int> result;
  int i = static_cast<int>(arr1.size()) - 1;
  int j = static_cast<int>(arr2.size()) - 1;
  int carry = 0;

  while (i >= 0 || j >= 0 || carry != 0) {
    int sum = carry;
    if (i >= 0) sum += arr1[i--];
    if (j >= 0) sum += arr2[j--];

    result.push_back(sum & 1);       // current digit = sum % 2 (preserve parity)
    carry = -(sum >> 1);              // carry uses weight -2
  }

  // result currently reversed (LSB first); drop leading zero significance.
  while (result.size() > 1 && result.back() == 0) {
    result.pop_back();
  }
  std::reverse(result.begin(), result.end());
  return result;
}

}  // namespace

AddingTwoNegabinaryNumbersSolution::AddingTwoNegabinaryNumbersSolution() {
  setMetaInfo({.id = 1073,
               .title = "Adding Two Negabinary Numbers",
               .url = "https://leetcode.com/problems/adding-two-negabinary-numbers/"});
  registerStrategy(
      {"Digit Addition with Carry", "Accepted", "O(n)", "O(n)",
       {"Array", "Math"}},
      addNegabinaryImpl);
}

std::vector<int> AddingTwoNegabinaryNumbersSolution::addNegabinary(
    std::vector<int>& arr1, std::vector<int>& arr2) {
  return getSolution()(arr1, arr2);
}

}  // namespace problem_1073
}  // namespace leetcode
