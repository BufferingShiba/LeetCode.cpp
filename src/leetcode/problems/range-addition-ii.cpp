#include "leetcode/problems/range-addition-ii.h"

#include <algorithm>

namespace leetcode {
namespace problem_598 {

namespace {

int maxCountImpl(int m, int n, std::vector<std::vector<int>>& ops) {
  if (ops.empty()) {
    return m * n;
  }
  int min_a = ops[0][0];
  int min_b = ops[0][1];
  for (const auto& op : ops) {
    min_a = std::min(min_a, op[0]);
    min_b = std::min(min_b, op[1]);
  }
  return min_a * min_b;
}

}  // namespace

RangeAdditionIiSolution::RangeAdditionIiSolution() {
  setMetaInfo({.id = 598,
               .title = "Range Addition II",
               .url = "https://leetcode.com/problems/range-addition-ii/"});
  registerStrategy({.name = "intersection",
                    .expected = "Accepted",
                    .time_complexity = "O(P)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Math"}},
                   maxCountImpl);
}

int RangeAdditionIiSolution::maxCount(int m, int n,
                                       std::vector<std::vector<int>>& ops) {
  return getSolution()(m, n, ops);
}

}  // namespace problem_598
}  // namespace leetcode
