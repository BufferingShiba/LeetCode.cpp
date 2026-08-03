#include "leetcode/problems/binary-prefix-divisible-by-5.h"

#include <vector>

namespace leetcode::problem_1018 {

namespace {

// 单遍扫描，只维护对 5 的余数。
std::vector<bool> prefixesDivBy5Impl(std::vector<int>& nums) {
  std::vector<bool> answer;
  answer.reserve(nums.size());
  int remainder = 0;
  for (int bit : nums) {
    remainder = (remainder * 2 + bit) % 5;
    answer.push_back(remainder == 0);
  }
  return answer;
}

}  // namespace

BinaryPrefixDivisibleBy5Solution::BinaryPrefixDivisibleBy5Solution() {
  this->setMetaInfo({.id = 1018,
                     .title = "Binary Prefix Divisible By 5",
                     .url = "https://leetcode.com/problems/binary-prefix-divisible-by-5/"});
  this->registerStrategy({.name = "ModuloTracking",
                          .expected = "Accepted",
                          .time_complexity = "O(n)",
                          .space_complexity = "O(1)",
                          .tags = {"Array", "Bit Manipulation"}},
                         prefixesDivBy5Impl);
}

std::vector<bool> BinaryPrefixDivisibleBy5Solution::prefixesDivBy5(
    std::vector<int>& nums) {
  return this->getSolution()(nums);
}

}  // namespace leetcode::problem_1018
