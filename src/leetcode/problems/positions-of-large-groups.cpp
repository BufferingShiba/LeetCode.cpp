#include "leetcode/problems/positions-of-large-groups.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_830 {

namespace {

std::vector<std::vector<int>> scanGroups(const std::string& s) {
  std::vector<std::vector<int>> result;
  int n = static_cast<int>(s.size());
  int start = 0;
  while (start < n) {
    int end = start;
    while (end < n && s[end] == s[start]) {
      ++end;
    }
    if (end - start >= 3) {
      result.push_back({start, end - 1});
    }
    start = end;
  }
  return result;
}

}  // namespace

PositionsOfLargeGroupsSolution::PositionsOfLargeGroupsSolution() {
  setMetaInfo({.id = 830,
               .title = "Positions of Large Groups",
               .url = "https://leetcode.com/problems/positions-of-large-groups/"});

  registerStrategy(
      {.name = "scan",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"String", "Single Pass"}},
      scanGroups);
}

}  // namespace problem_830
}  // namespace leetcode
