#include "leetcode/problems/find-the-number-of-distinct-colors-among-the-balls.h"

#include <unordered_map>

namespace leetcode {
namespace problem_3160 {
namespace {

std::vector<int> queryResultsImpl(int limit,
                                  std::vector<std::vector<int>>& queries) {
  (void)limit;
  std::unordered_map<int, int> ballColor;   // ball -> current color
  std::unordered_map<int, int> colorCount;  // color -> number of balls using it
  std::vector<int> result;
  result.reserve(queries.size());

  int distinct = 0;
  for (const auto& q : queries) {
    int ball = q[0];
    int color = q[1];

    auto it = ballColor.find(ball);
    if (it != ballColor.end()) {
      int oldColor = it->second;
      if (--colorCount[oldColor] == 0) {
        colorCount.erase(oldColor);
        --distinct;
      }
    }

    ballColor[ball] = color;
    if (++colorCount[color] == 1) {
      ++distinct;
    }

    result.push_back(distinct);
  }
  return result;
}

}  // namespace

FindTheNumberOfDistinctColorsAmongTheBallsSolution::
    FindTheNumberOfDistinctColorsAmongTheBallsSolution() {
  setMetaInfo({.id = 3160,
               .title = "Find the Number of Distinct Colors Among the Balls",
               .url = "https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/"});
  registerStrategy(
      {.name = "hashmap simulation",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Simulation"}},
      queryResultsImpl);
}

std::vector<int> FindTheNumberOfDistinctColorsAmongTheBallsSolution::
    queryResults(int limit, std::vector<std::vector<int>>& queries) {
  return getSolution()(limit, queries);
}

}  // namespace problem_3160
}  // namespace leetcode
