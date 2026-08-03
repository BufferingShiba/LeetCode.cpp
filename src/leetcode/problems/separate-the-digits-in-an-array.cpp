#include "leetcode/problems/separate-the-digits-in-an-array.h"

namespace leetcode {
namespace problem_2553 {

namespace {

std::vector<int> separateDigitsImpl(std::vector<int>& nums) {
  std::vector<int> answer;
  for (int num : nums) {
    std::string s = std::to_string(num);
    for (char c : s) {
      answer.push_back(c - '0');
    }
  }
  return answer;
}

}  // namespace

SeparateTheDigitsInAnArraySolution::SeparateTheDigitsInAnArraySolution() {
  setMetaInfo({.id = 2553,
               .title = "Separate the Digits in an Array",
               .url = "https://leetcode.com/problems/separate-the-digits-in-an-array/"});
  registerStrategy(
      {"to_string", "Accepted", "O(n * d)", "O(n * d)", {"Array", "Simulation"}},
      separateDigitsImpl);
}

std::vector<int> SeparateTheDigitsInAnArraySolution::separateDigits(std::vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_2553
}  // namespace leetcode
