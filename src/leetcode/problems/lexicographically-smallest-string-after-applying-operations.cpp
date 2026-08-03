#include "leetcode/problems/lexicographically-smallest-string-after-applying-operations.h"

#include <queue>
#include <string>
#include <unordered_set>

namespace leetcode {
namespace problem_1625 {

namespace {

std::string findLexSmallestStringImpl(std::string s, int a, int b) {
  int n = static_cast<int>(s.size());
  std::unordered_set<std::string> visited;
  std::queue<std::string> q;
  std::string ans = s;

  visited.insert(s);
  q.push(s);

  auto add_op = [&](const std::string& cur) {
    std::string nxt = cur;
    for (int i = 1; i < n; i += 2) {
      nxt[i] = '0' + (cur[i] - '0' + a) % 10;
    }
    return nxt;
  };

  auto rotate_op = [&](const std::string& cur) {
    return cur.substr(n - b) + cur.substr(0, n - b);
  };

  while (!q.empty()) {
    std::string cur = q.front();
    q.pop();

    if (cur < ans) {
      ans = cur;
    }

    std::string nxt_add = add_op(cur);
    if (visited.insert(nxt_add).second) {
      q.push(nxt_add);
    }

    std::string nxt_rot = rotate_op(cur);
    if (visited.insert(nxt_rot).second) {
      q.push(nxt_rot);
    }
  }

  return ans;
}

}  // namespace

std::string
LexicographicallySmallestStringAfterApplyingOperationsSolution::findLexSmallestString(
    std::string s, int a, int b) {
  return getSolution()(std::move(s), a, b);
}

LexicographicallySmallestStringAfterApplyingOperationsSolution::
    LexicographicallySmallestStringAfterApplyingOperationsSolution()
    : SolutionBase<Func>() {
  setMetaInfo({.id = 1625,
               .title = "Lexicographically Smallest String After Applying Operations",
               .url = "https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/"});

  registerStrategy(
      {.name = "BFS",
       .expected = "Accepted",
       .time_complexity = "O(n * L * D)",
       .space_complexity = "O(n * L * D)",
       .tags = {"String", "Breadth-First Search"}},
      findLexSmallestStringImpl);
}

}  // namespace problem_1625
}  // namespace leetcode
