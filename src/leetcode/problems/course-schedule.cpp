#include "leetcode/problems/course-schedule.h"

#include <queue>
#include <vector>

namespace leetcode {
namespace problem_207 {

namespace {

bool canFinishImpl(int numCourses, std::vector<std::vector<int>>& prerequisites) {
  std::vector<int> indegree(numCourses, 0);
  std::vector<std::vector<int>> graph(numCourses);
  for (const auto& p : prerequisites) {
    int course = p[0];
    int prereq = p[1];
    graph[prereq].push_back(course);
    ++indegree[course];
  }

  std::queue<int> q;
  for (int i = 0; i < numCourses; ++i) {
    if (indegree[i] == 0) q.push(i);
  }

  int visited = 0;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    ++visited;
    for (int neighbor : graph[node]) {
      if (--indegree[neighbor] == 0) q.push(neighbor);
    }
  }

  return visited == numCourses;
}

}  // namespace

CourseScheduleSolution::CourseScheduleSolution() {
  setMetaInfo({.id = 207,
               .title = "Course Schedule",
               .url = "https://leetcode.com/problems/course-schedule/"});
  registerStrategy(
      {.name = "KahnTopologicalSort",
       .expected = "Accepted",
       .time_complexity = "O(V + E)",
       .space_complexity = "O(V + E)",
       .tags = {"BFS", "Graph", "Topological Sort"}},
      canFinishImpl);
}

bool CourseScheduleSolution::canFinish(int numCourses,
                                       std::vector<std::vector<int>>& prerequisites) {
  return getSolution()(numCourses, prerequisites);
}

}  // namespace problem_207
}  // namespace leetcode
