#include "leetcode/problems/license-key-formatting.h"

namespace leetcode::problem_482 {

static std::string licenseKeyFormattingImpl(std::string s, int k) {
  // Step 1: collect alphanumeric chars, convert to uppercase
  std::string cleaned;
  cleaned.reserve(s.size());
  for (char ch : s) {
    if (ch != '-') {
      if (ch >= 'a' && ch <= 'z') {
        ch = static_cast<char>(ch - 'a' + 'A');
      }
      cleaned.push_back(ch);
    }
  }

  if (cleaned.empty()) {
    return "";
  }

  // Step 2: determine first group length
  int n = static_cast<int>(cleaned.size());
  int first = n % k;
  if (first == 0) {
    first = k;
  }

  // Step 3: build result
  std::string result;
  result.reserve(n + (n - 1) / k);  // approximate
  result.append(cleaned, 0, first);

  for (int i = first; i < n; i += k) {
    result.push_back('-');
    result.append(cleaned, i, k);
  }

  return result;
}

LicenseKeyFormattingSolution::LicenseKeyFormattingSolution() {
  setMetaInfo({.id = 482,
               .title = "License Key Formatting",
               .url = "https://leetcode.com/problems/license-key-formatting/"});

  registerStrategy(
      {.name = "Iterative",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"String"}},
      licenseKeyFormattingImpl);

  setDefaultStrategy();
}

std::string LicenseKeyFormattingSolution::licenseKeyFormatting(std::string s, int k) {
  return getSolution()(std::move(s), k);
}

}  // namespace leetcode::problem_482
