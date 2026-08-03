#include "leetcode/problems/reformat-phone-number.h"

namespace leetcode {
namespace problem_1694 {

namespace {

std::string reformatNumberImpl(const std::string& number) {
  std::string digits;
  for (char c : number) {
    if (c >= '0' && c <= '9') {
      digits.push_back(c);
    }
  }

  std::string result;
  int pos = 0;
  int n = static_cast<int>(digits.size());
  while (n - pos > 4) {
    if (!result.empty()) result.push_back('-');
    result += digits.substr(pos, 3);
    pos += 3;
  }

  // Remaining <= 4 digits
  int remain = n - pos;
  if (remain > 0) {
    if (!result.empty()) result.push_back('-');
  }
  if (remain == 4) {
    result += digits.substr(pos, 2);
    result.push_back('-');
    result += digits.substr(pos + 2, 2);
  } else if (remain > 0) {
    result += digits.substr(pos, remain);
  }
  return result;
}

}  // namespace

ReformatPhoneNumberSolution::ReformatPhoneNumberSolution() {
  setMetaInfo({.id = 1694,
               .title = "Reformat Phone Number",
               .url = "https://leetcode.com/problems/reformat-phone-number/"});
  registerStrategy({.name = "greedy-grouping",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"String"}},
                   reformatNumberImpl);
}

std::string ReformatPhoneNumberSolution::reformatNumber(
    const std::string& number) {
  return getSolution()(number);
}

}  // namespace problem_1694
}  // namespace leetcode
