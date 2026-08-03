#include "leetcode/problems/add-strings.h"

#include <string>

namespace leetcode {
namespace problem_415 {
namespace {

std::string addStringsImpl(std::string num1, std::string num2) {
  std::string result;
  int i = static_cast<int>(num1.size()) - 1;
  int j = static_cast<int>(num2.size()) - 1;
  int carry = 0;
  while (i >= 0 || j >= 0 || carry > 0) {
    int sum = carry;
    if (i >= 0) sum += num1[i--] - '0';
    if (j >= 0) sum += num2[j--] - '0';
    carry = sum / 10;
    result.push_back(static_cast<char>('0' + sum % 10));
  }
  std::reverse(result.begin(), result.end());
  return result;
}

}  // namespace

AddStringsSolution::AddStringsSolution() {
  setMetaInfo({.id = 415,
               .title = "Add Strings",
               .url = "https://leetcode.com/problems/add-strings/"});
  registerStrategy(
      {"CarrySimulation", "Accepted", "O(n+m)", "O(max(n,m))", {"Math", "Simulation"}},
      addStringsImpl);
}

std::string AddStringsSolution::addStrings(std::string num1, std::string num2) {
  return getSolution()(std::move(num1), std::move(num2));
}

}  // namespace problem_415
}  // namespace leetcode
