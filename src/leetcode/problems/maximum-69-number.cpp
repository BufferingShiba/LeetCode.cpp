#include "leetcode/problems/maximum-69-number.h"

namespace leetcode {
namespace problem_1323 {

namespace {

int maximum69NumberImpl(int num) {
  // Convert to string to locate the first '6' from the most significant side.
  std::string s = std::to_string(num);
  for (char& c : s) {
    if (c == '6') {
      c = '9';
      break;
    }
  }
  return std::stoi(s);
}

}  // namespace

int Maximum69NumberSolution::maximum69Number(int num) {
  return getSolution()(num);
}

Maximum69NumberSolution::Maximum69NumberSolution() {
  setMetaInfo({.id = 1323,
               .title = "Maximum 69 Number",
               .url = "https://leetcode.com/problems/maximum-69-number/"});
  registerStrategy(
      {.name = "Greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Math", "Greedy"}},
      maximum69NumberImpl);
}

}  // namespace problem_1323
}  // namespace leetcode
