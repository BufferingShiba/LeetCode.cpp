#include "leetcode/problems/number-of-ways-to-select-buildings.h"

namespace leetcode {
namespace problem_2222 {

namespace {

long long numberOfWaysImpl(const std::string& s) {
  const int n = static_cast<int>(s.size());
  long long totalZero = 0;
  long long totalOne = 0;
  for (char c : s) {
    if (c == '0') {
      ++totalZero;
    } else {
      ++totalOne;
    }
  }

  long long zeroLeft = 0;
  long long oneLeft = 0;
  long long ans = 0;
  for (char c : s) {
    if (c == '0') {
      // 当前为中间字符时模式必须是 "101"，左边一个 '1'，右边一个 '1'
      ans += oneLeft * (totalOne - oneLeft);
      ++zeroLeft;
    } else {
      // 当前为中间字符时模式必须是 "010"，左边一个 '0'，右边一个 '0'
      ans += zeroLeft * (totalZero - zeroLeft);
      ++oneLeft;
    }
  }
  return ans;
}

}  // namespace

NumberOfWaysToSelectBuildingsSolution::NumberOfWaysToSelectBuildingsSolution() {
  setMetaInfo({.id = 2222,
               .title = "Number of Ways to Select Buildings",
               .url = "https://leetcode.com/problems/number-of-ways-to-select-buildings/"});
  registerStrategy(
      {.name = "PrefixCount",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Dynamic Programming", "Prefix Sum"}},
      numberOfWaysImpl);
}

long long NumberOfWaysToSelectBuildingsSolution::numberOfWays(std::string s) {
  return getSolution()(s);
}

}  // namespace problem_2222
}  // namespace leetcode
