#include "leetcode/problems/change-minimum-characters-to-satisfy-one-of-three-conditions.h"

#include <algorithm>
#include <limits>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1737 {

namespace {

int minCharactersImpl(std::string a, std::string b) {
  const int n = static_cast<int>(a.size());
  const int m = static_cast<int>(b.size());

  std::vector<int> cntA(26, 0), cntB(26, 0);
  for (char ch : a) cntA[ch - 'a']++;
  for (char ch : b) cntB[ch - 'a']++;

  int best = std::numeric_limits<int>::max();
  for (int c = 0; c < 26; ++c) {
    best = std::min(best, n + m - cntA[c] - cntB[c]);
  }

  std::vector<int> preA(27, 0), preB(27, 0);
  for (int i = 0; i < 26; ++i) {
    preA[i + 1] = preA[i] + cntA[i];
    preB[i + 1] = preB[i] + cntB[i];
  }

  for (int i = 0; i < 25; ++i) {
    int changeA = (preA[26] - preA[i + 1]);
    int changeB = preB[i + 1];
    best = std::min(best, changeA + changeB);
  }

  for (int i = 0; i < 25; ++i) {
    int changeB = (preB[26] - preB[i + 1]);
    int changeA = preA[i + 1];
    best = std::min(best, changeA + changeB);
  }

  return best;
}

}  // namespace

int ChangeMinimumCharactersToSatisfyOneOfThreeConditionsSolution::minCharacters(
    std::string a, std::string b) {
  return getSolution()(std::move(a), std::move(b));
}

ChangeMinimumCharactersToSatisfyOneOfThreeConditionsSolution::ChangeMinimumCharactersToSatisfyOneOfThreeConditionsSolution() {
  setMetaInfo({1737, "Change Minimum Characters to Satisfy One of Three Conditions",
               "https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/"});
  registerStrategy(
      {.name = "counting + prefix sum",
       .expected = "Accepted",
       .time_complexity = "O(n + m + 26)",
       .space_complexity = "O(26)",
       .tags = {"Hash Table", "String", "Counting", "Prefix Sum"}},
      minCharactersImpl);
}

}  // namespace problem_1737
}  // namespace leetcode
