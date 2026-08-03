#include "leetcode/problems/shortest-distance-to-a-character.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_821 {

namespace {

std::vector<int> shortestToCharImpl(std::string s, char c) {
  const int n = static_cast<int>(s.size());
  std::vector<int> answer(n, n);

  int last = -n;
  for (int i = 0; i < n; ++i) {
    if (s[i] == c) last = i;
    answer[i] = i - last;
  }

  last = 2 * n;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == c) last = i;
    answer[i] = std::min(answer[i], last - i);
  }

  return answer;
}

}  // namespace

ShortestDistanceToACharacterSolution::ShortestDistanceToACharacterSolution() {
  setMetaInfo({.id = 821,
               .title = "Shortest Distance to a Character",
               .url = "https://leetcode.com/problems/shortest-distance-to-a-character/"});

  registerStrategy(
      {.name = "TwoPassScan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1) excluding output",
       .tags = {"Array", "Two Pointers", "String"}},
      shortestToCharImpl);
}

std::vector<int> ShortestDistanceToACharacterSolution::shortestToChar(
    std::string s, char c) {
  return getSolution()(std::move(s), c);
}

}  // namespace problem_821
}  // namespace leetcode
