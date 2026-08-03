#include "leetcode/problems/take-k-of-each-character-from-left-and-right.h"

#include <array>
#include <string>

namespace leetcode {
namespace problem_2516 {

namespace {

int takeCharactersImpl(std::string s, int k) {
  const int n = static_cast<int>(s.size());
  std::array<int, 3> total = {0, 0, 0};
  for (char c : s) {
    ++total[c - 'a'];
  }
  for (int i = 0; i < 3; ++i) {
    if (total[i] < k) {
      return -1;
    }
  }
  if (k == 0) {
    return 0;
  }

  // Window counts; limit = total - k per character.
  std::array<int, 3> limit = {total[0] - k, total[1] - k, total[2] - k};
  std::array<int, 3> cnt = {0, 0, 0};

  int best = 0;
  int left = 0;
  for (int right = 0; right < n; ++right) {
    ++cnt[s[right] - 'a'];
    while (cnt[0] > limit[0] || cnt[1] > limit[1] || cnt[2] > limit[2]) {
      --cnt[s[left] - 'a'];
      ++left;
    }
    best = std::max(best, right - left + 1);
  }
  return n - best;
}

}  // namespace

TakeKOfEachCharacterFromLeftAndRightSolution::
    TakeKOfEachCharacterFromLeftAndRightSolution() {
  setMetaInfo({.id = 2516,
               .title = "Take K of Each Character From Left and Right",
               .url = "https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/"});
  registerStrategy(
      {.name = "SlidingWindowMaxKeptSubarray",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String", "Sliding Window"}},
      takeCharactersImpl);
}

int TakeKOfEachCharacterFromLeftAndRightSolution::takeCharacters(
    std::string s, int k) {
  return getSolution()(s, k);
}

}  // namespace problem_2516
}  // namespace leetcode
