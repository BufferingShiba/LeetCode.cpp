#include "leetcode/problems/coupon-code-validator.h"

#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

namespace leetcode::problem_3606 {

static std::vector<std::string> validateCouponsImpl(
    std::vector<std::string>& code,
    std::vector<std::string>& businessLine,
    std::vector<bool>& isActive) {
  auto priority = [](const std::string& bl) -> int {
    if (bl == "electronics") return 0;
    if (bl == "grocery") return 1;
    if (bl == "pharmacy") return 2;
    if (bl == "restaurant") return 3;
    return -1;
  };

  auto isValidCode = [](const std::string& s) -> bool {
    if (s.empty()) return false;
    for (char c : s) {
      if (!std::isalnum(static_cast<unsigned char>(c)) && c != '_') {
        return false;
      }
    }
    return true;
  };

  std::vector<std::pair<std::string, std::string>> valid;
  int n = static_cast<int>(code.size());
  for (int i = 0; i < n; ++i) {
    if (!isActive[i]) continue;
    if (!isValidCode(code[i])) continue;
    int p = priority(businessLine[i]);
    if (p == -1) continue;
    valid.emplace_back(code[i], businessLine[i]);
  }

  std::sort(valid.begin(), valid.end(),
            [&priority](const auto& a, const auto& b) {
              int pa = priority(a.second);
              int pb = priority(b.second);
              if (pa != pb) return pa < pb;
              return a.first < b.first;
            });

  std::vector<std::string> result;
  result.reserve(valid.size());
  for (const auto& p : valid) {
    result.push_back(p.first);
  }
  return result;
}

CouponCodeValidatorSolution::CouponCodeValidatorSolution() {
  setMetaInfo({.id = 3606,
               .title = "Coupon Code Validator",
               .url = "https://leetcode.com/problems/coupon-code-validator/"});
  registerStrategy(
      {.name = "Filter and Sort",
       .expected = "Accepted",
       .time_complexity = "O(n + m log m)",
       .space_complexity = "O(m)",
       .tags = {"Array", "Hash Table", "String", "Sorting"}},
      validateCouponsImpl);
}

std::vector<std::string> CouponCodeValidatorSolution::validateCoupons(
    std::vector<std::string>& code,
    std::vector<std::string>& businessLine,
    std::vector<bool>& isActive) {
  return getSolution()(code, businessLine, isActive);
}

}  // namespace leetcode::problem_3606
