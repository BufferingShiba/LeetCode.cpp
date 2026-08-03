#include "leetcode/problems/find-the-town-judge.h"

namespace leetcode::problem_997 {

namespace {
int findJudgeImpl(int n, std::vector<std::vector<int>>& trust) {
  std::vector<int> indegree(n + 1, 0);
  std::vector<int> outdegree(n + 1, 0);
  for (const auto& t : trust) {
    ++outdegree[t[0]];
    ++indegree[t[1]];
  }
  for (int i = 1; i <= n; ++i) {
    if (indegree[i] == n - 1 && outdegree[i] == 0) {
      return i;
    }
  }
  return -1;
}
}  // namespace

FindTheTownJudgeSolution::FindTheTownJudgeSolution() {
  setMetaInfo({.id = 997,
               .title = "Find the Town Judge",
               .url = "https://leetcode.com/problems/find-the-town-judge/"});
  registerStrategy(
      {.name = "degree-count",
       .expected = "Accepted",
       .time_complexity = "O(n + trust.length)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Graph Theory"}},
      findJudgeImpl);
}

int FindTheTownJudgeSolution::findJudge(int n,
                                        std::vector<std::vector<int>>& trust) {
  return getSolution()(n, trust);
}

}  // namespace leetcode::problem_997
