#include "leetcode/problems/base-7.h"

namespace leetcode {
namespace problem_504 {

namespace {

std::string convertToBase7Impl(int num) {
  if (num == 0) {
    return "0";
  }
  bool negative = num < 0;
  long long n = std::llabs(static_cast<long long>(num));
  std::string result;
  while (n > 0) {
    result.push_back(static_cast<char>('0' + n % 7));
    n /= 7;
  }
  if (negative) {
    result.push_back('-');
  }
  std::reverse(result.begin(), result.end());
  return result;
}

}  // namespace

Base7Solution::Base7Solution() {
  setMetaInfo({.id = 504,
               .title = "Base 7",
               .url = "https://leetcode.com/problems/base-7/"});
  registerStrategy({.name = "modulo",
                    .expected = "Accepted",
                    .time_complexity = "O(log7(|num|))",
                    .space_complexity = "O(log7(|num|))",
                    .tags = {"Math", "String"}},
                   convertToBase7Impl);
}

std::string Base7Solution::convertToBase7(int num) {
  return getSolution()(num);
}

}  // namespace problem_504
}  // namespace leetcode
