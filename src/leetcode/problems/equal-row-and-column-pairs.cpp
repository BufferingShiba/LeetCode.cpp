#include "leetcode/problems/equal-row-and-column-pairs.h"

#include <string>
#include <sstream>
#include <unordered_map>

namespace leetcode::problem_2352 {

namespace {

int equalPairsImpl(std::vector<std::vector<int>>& grid) {
  const int n = static_cast<int>(grid.size());
  std::unordered_map<std::string, int> rowCount;
  for (int i = 0; i < n; ++i) {
    std::ostringstream oss;
    for (int j = 0; j < n; ++j) {
      oss << grid[i][j] << '#';
    }
    ++rowCount[oss.str()];
  }
  int result = 0;
  for (int j = 0; j < n; ++j) {
    std::ostringstream oss;
    for (int i = 0; i < n; ++i) {
      oss << grid[i][j] << '#';
    }
    auto it = rowCount.find(oss.str());
    if (it != rowCount.end()) {
      result += it->second;
    }
  }
  return result;
}

}  // namespace

int EqualRowAndColumnPairsSolution::equalPairs(
    std::vector<std::vector<int>>& grid) {
  return getSolution()(grid);
}

EqualRowAndColumnPairsSolution::EqualRowAndColumnPairsSolution() {
  setMetaInfo({.id = 2352,
               .title = "Equal Row and Column Pairs",
               .url = "https://leetcode.com/problems/equal-row-and-column-pairs/"});
  registerStrategy(
      {"hash table",
       "Accepted",
       "O(n^2)",
       "O(n^2)",
       {"Array", "Hash Table", "Matrix", "Simulation"}},
      [](std::vector<std::vector<int>>& grid) -> int {
        return equalPairsImpl(grid);
      });
}

}  // namespace leetcode::problem_2352
