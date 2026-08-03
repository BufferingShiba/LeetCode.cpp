#include "leetcode/problems/find-the-difference.h"

namespace leetcode {
namespace problem_389 {

namespace {

char findTheDifferenceXor(std::string s, std::string t) {
  char res = 0;
  for (char c : s) res ^= c;
  for (char c : t) res ^= c;
  return res;
}

}  // namespace

FindTheDifferenceSolution::FindTheDifferenceSolution() {
  setMetaInfo({.id = 389,
               .title = "Find the Difference",
               .url = "https://leetcode.com/problems/find-the-difference/"});
  registerStrategy({.name = "Xor",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Bit Manipulation", "String"}},
                   findTheDifferenceXor);
}

char FindTheDifferenceSolution::findTheDifference(std::string s, std::string t) {
  return getSolution()(std::move(s), std::move(t));
}

}  // namespace problem_389
}  // namespace leetcode
