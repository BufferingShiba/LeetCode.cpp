#include "leetcode/problems/open-the-lock.h"

#include <string>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_752 {
namespace {

int toInt(const std::string& s) {
  return (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 +
         (s[3] - '0');
}

int openLockImpl(std::vector<std::string>& deadends, std::string target) {
  std::unordered_set<int> dead;
  for (const auto& s : deadends) {
    dead.insert(toInt(s));
  }
  int t = toInt(target);
  if (dead.count(0)) return -1;

  std::unordered_set<int> visited;
  visited.insert(0);
  std::vector<int> q;
  q.push_back(0);
  int steps = 0;

  while (!q.empty()) {
    int sz = static_cast<int>(q.size());
    while (sz--) {
      int cur = q.front();
      q.erase(q.begin());
      if (cur == t) return steps;

      int p = 1000;
      for (int wheel = 0; wheel < 4; ++wheel) {
        int digit = (cur / p) % 10;
        for (int d : {-1, 1}) {
          int nd = (digit + d + 10) % 10;
          int nxt = cur - digit * p + nd * p;
          if (!dead.count(nxt) && !visited.count(nxt)) {
            visited.insert(nxt);
            q.push_back(nxt);
          }
        }
        p /= 10;
      }
    }
    ++steps;
  }
  return -1;
}

}  // namespace

OpenTheLockSolution::OpenTheLockSolution() {
  setMetaInfo(
      {.id = 752,
       .title = "Open the Lock",
       .url = "https://leetcode.com/problems/open-the-lock/"});
  registerStrategy(
      {.name = "BFS",
       .expected = "Accepted",
       .time_complexity = "O(10^4 * 8) = O(1)",
       .space_complexity = "O(10^4)",
       .tags = {"BFS", "String"}},
      openLockImpl);
}

int OpenTheLockSolution::openLock(std::vector<std::string>& deadends,
                                  std::string target) {
  return getSolution()(deadends, target);
}

}  // namespace problem_752
}  // namespace leetcode
