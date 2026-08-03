#include "leetcode/problems/maximum-value-of-a-string-in-an-array.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2496 {

namespace {

int maximumValueImpl(std::vector<std::string>& strs) {
  int ans = 0;
  for (const std::string& s : strs) {
    bool isNumeric = true;
    for (char c : s) {
      if (!isdigit(static_cast<unsigned char>(c))) {
        isNumeric = false;
        break;
      }
    }
    int value = (isNumeric && !s.empty()) ? std::stoi(s) : static_cast<int>(s.size());
    if (value > ans) ans = value;
  }
  return ans;
}

}  // namespace

MaximumValueOfAStringInAnArraySolution::MaximumValueOfAStringInAnArraySolution() {
  setMetaInfo({.id = 2496,
               .title = "Maximum Value of a String in an Array",
               .url = "https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/"});
  registerStrategy(
      {.name = "linear-scan",
       .expected = "Accepted",
       .time_complexity = "O(n * len)",
       .space_complexity = "O(1)",
       .tags = {"Array", "String"}},
      maximumValueImpl);
}

int MaximumValueOfAStringInAnArraySolution::maximumValue(std::vector<std::string>& strs) {
  return getSolution()(strs);
}

}  // namespace problem_2496
}  // namespace leetcode
