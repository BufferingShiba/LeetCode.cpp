#include "leetcode/problems/additive-number.h"

#include <algorithm>
#include <string>

namespace leetcode {
namespace problem_306 {

namespace {

// Addition of two non-negative integer strings (no leading zeros).
std::string addStrings(const std::string& a, const std::string& b) {
  std::string result;
  int i = static_cast<int>(a.size()) - 1;
  int j = static_cast<int>(b.size()) - 1;
  int carry = 0;
  while (i >= 0 || j >= 0 || carry) {
    int digit = carry;
    if (i >= 0) digit += a[i--] - '0';
    if (j >= 0) digit += b[j--] - '0';
    carry = digit / 10;
    result.push_back(static_cast<char>('0' + digit % 10));
  }
  if (result.empty()) result.push_back('0');
  std::reverse(result.begin(), result.end());
  return result;
}

// Given the two preceding numbers, check that `remaining` matches the additive
// sequence (each next number equals sum of the previous two).
bool verifyTail(const std::string& remaining, const std::string& first,
                const std::string& second) {
  std::string sum = addStrings(first, second);
  if (remaining.size() < sum.size()) return false;
  if (remaining.compare(0, sum.size(), sum) != 0) return false;
  std::string rest = remaining.substr(sum.size());
  if (rest.empty()) return true;
  return verifyTail(rest, second, sum);
}

}  // namespace

static bool solution1(string num) {
  int n = static_cast<int>(num.size());
  // Enumerate the split between first/second/second+rest. The sequence must
  // have at least three numbers, so first takes [0, i], second takes
  // [i+1, j], and the tail (sum) starts at j+1.
  for (int i = 0; i <= n - 3; ++i) {
    if (i > 0 && num[0] == '0') break;  // first number: no leading zeros
    for (int j = i + 1; j <= n - 2; ++j) {
      if (j - i > 1 && num[i + 1] == '0') break;  // second: no leading zeros
      std::string first = num.substr(0, i + 1);
      std::string second = num.substr(i + 1, j - i);
      if (verifyTail(num.substr(j + 1), first, second)) return true;
    }
  }
  return false;
}

AdditiveNumberSolution::AdditiveNumberSolution() {
  setMetaInfo({
      .id = 306,
      .title = "Additive Number",
      .url = "https://leetcode.com/problems/additive-number"
  });
  registerStrategy(
      {
          .name = "Brute Force",
          .expected = "Accepted",
          .time_complexity = "O(n^3)",
          .space_complexity = "O(n)",
          .tags = {"backtracking", "string"},
      },
      solution1);
}

bool AdditiveNumberSolution::isAdditiveNumber(string num) {
  return getSolution()(num);
}

}  // namespace problem_306
}  // namespace leetcode
