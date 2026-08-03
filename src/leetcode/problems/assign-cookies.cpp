#include "leetcode/problems/assign-cookies.h"

#include <algorithm>

namespace leetcode::problem_455 {

static int findContentChildrenImpl(std::vector<int>& g, std::vector<int>& s) {
  std::sort(g.begin(), g.end());
  std::sort(s.begin(), s.end());

  int child = 0;
  int cookie = 0;
  const int n = static_cast<int>(g.size());
  const int m = static_cast<int>(s.size());

  while (child < n && cookie < m) {
    if (s[cookie] >= g[child]) {
      ++child;
    }
    ++cookie;
  }

  return child;
}

AssignCookiesSolution::AssignCookiesSolution() {
  setMetaInfo({.id = 455, .title = "Assign Cookies", .url = "https://leetcode.com/problems/assign-cookies/"});

  registerStrategy(
      {.name = "Greedy + Two Pointers",
       .expected = "Accepted",
       .time_complexity = "O(n log n + m log m)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Two Pointers", "Greedy", "Sorting"}},
      findContentChildrenImpl);
}

}  // namespace leetcode::problem_455
