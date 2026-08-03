#include "leetcode/problems/minimum-additions-to-make-valid-string.h"

namespace {

int addMinimumImpl(std::string word) {
  int ans = 0;
  int expected = 0;  // 0='a', 1='b', 2='c'
  for (char c : word) {
    int want = c - 'a';
    while (expected != want) {
      expected = (expected + 1) % 3;
      ++ans;
    }
    expected = (expected + 1) % 3;  // consume current char
  }
  if (expected != 0) {
    ans += 3 - expected;
  }
  return ans;
}

}  // namespace

namespace leetcode::problem_2645 {

int MinimumAdditionsToMakeValidStringSolution::addMinimum(std::string word) {
  return getSolution()(std::move(word));
}

MinimumAdditionsToMakeValidStringSolution::MinimumAdditionsToMakeValidStringSolution() {
  setMetaInfo({.id = 2645,
               .title = "Minimum Additions to Make Valid String",
               .url = "https://leetcode.com/problems/minimum-additions-to-make-valid-string/"});
  registerStrategy({.name = "Greedy",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"String", "Greedy"}},
                   addMinimumImpl);
}

}  // namespace leetcode::problem_2645
