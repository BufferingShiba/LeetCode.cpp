#include "leetcode/problems/course-schedule-iv.h"

#include <bitset>

namespace leetcode {
namespace problem_1462 {

namespace {

std::vector<bool> checkIfPrerequisiteImpl(int numCourses,
                                          std::vector<std::vector<int>>& prerequisites,
                                          std::vector<std::vector<int>>& queries) {
  std::vector<std::vector<int>> graph(numCourses);
  std::vector<int> indegree(numCourses, 0);
  for (const auto& e : prerequisites) {
    graph[e[0]].push_back(e[1]);
    ++indegree[e[1]];
  }

  // Compute transitive closure via topological order: each course inherits
  // the reachability (ancestor courses) of all its prerequisites.
  std::vector<std::bitset<100>> prereq(numCourses);
  std::vector<int> queue;
  queue.reserve(numCourses);
  for (int i = 0; i < numCourses; ++i) {
    if (indegree[i] == 0) queue.push_back(i);
  }

  size_t head = 0;
  while (head < queue.size()) {
    int cur = queue[head++];
    for (int nxt : graph[cur]) {
      prereq[nxt] |= prereq[cur];
      prereq[nxt].set(cur);
      if (--indegree[nxt] == 0) queue.push_back(nxt);
    }
  }

  std::vector<bool> answer;
  answer.reserve(queries.size());
  for (const auto& q : queries) {
    answer.push_back(prereq[q[1]].test(q[0]));
  }
  return answer;
}

}  // namespace

CourseScheduleIvSolution::CourseScheduleIvSolution() {
  setMetaInfo({.id = 1462,
               .title = "Course Schedule IV",
               .url = "https://leetcode.com/problems/course-schedule-iv/"});
  registerStrategy(
      {.name = "topo-transitive-closure",
       .expected = "Accepted",
       .time_complexity = "O(N*E + Q)",
       .space_complexity = "O(N^2)",
       .tags = {"Topological Sort", "BFS", "Graph", "Bitset"}},
      checkIfPrerequisiteImpl);
}

std::vector<bool> CourseScheduleIvSolution::checkIfPrerequisite(
    int numCourses,
    std::vector<std::vector<int>>& prerequisites,
    std::vector<std::vector<int>>& queries) {
  return getSolution()(numCourses, prerequisites, queries);
}

}  // namespace problem_1462
}  // namespace leetcode
