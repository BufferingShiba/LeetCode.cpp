#include "leetcode/problems/minimum-number-of-operations-to-make-x-and-y-equal.h"

#include <algorithm>
#include <unordered_map>

namespace leetcode {
namespace problem_2998 {

namespace {

int minimumOperationsImpl(int x, int y) {
  std::unordered_map<int, int> memo;

  std::function<int(int)> dfs = [&](int v) -> int {
    if (v <= y) {
      return y - v;  // only increments are possible / needed
    }
    auto it = memo.find(v);
    if (it != memo.end()) {
      return it->second;
    }

    int res = v - y;  // decrement all the way down

    // Divide by 11: first adjust v to a nearby multiple of 11.
    res = std::min(res, (v % 11) + 1 + dfs(v / 11));
    res = std::min(res, (11 - v % 11) + 1 + dfs(v / 11 + 1));

    // Divide by 5: first adjust v to a nearby multiple of 5.
    res = std::min(res, (v % 5) + 1 + dfs(v / 5));
    res = std::min(res, (5 - v % 5) + 1 + dfs(v / 5 + 1));

    memo[v] = res;
    return res;
  };

  return dfs(x);
}

}  // namespace

MinimumNumberOfOperationsToMakeXAndYEqualSolution::
    MinimumNumberOfOperationsToMakeXAndYEqualSolution() {
  this->setMetaInfo({.id = 2998,
                     .title = "Minimum Number of Operations to Make X and Y "
                              "Equal",
                     .url = "https://leetcode.com/problems/minimum-number-of-"
                            "operations-to-make-x-and-y-equal/"});

  this->registerStrategy(
      {"Memoized DFS", "Accepted", "O(x)", "O(x)", {"Dynamic Programming",
                                                       "Memoization", "BFS"}},
      minimumOperationsImpl);
}

int MinimumNumberOfOperationsToMakeXAndYEqualSolution::
    minimumOperationsToMakeEqual(int x, int y) {
  return getSolution()(x, y);
}

}  // namespace problem_2998
}  // namespace leetcode
