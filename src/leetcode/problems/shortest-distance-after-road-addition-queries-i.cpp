#include "leetcode/problems/shortest-distance-after-road-addition-queries-i.h"
#include <queue>

namespace leetcode::problem_3243 {

static std::vector<int> shortestDistanceAfterQueriesImpl(int n, std::vector<std::vector<int>>& queries) {
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        adj[i].push_back(i + 1);
    }

    std::vector<int> answer;
    answer.reserve(queries.size());

    for (const auto& q : queries) {
        int u = q[0], v = q[1];
        adj[u].push_back(v);

        // BFS from 0 to n-1
        std::vector<int> dist(n, -1);
        std::queue<int> que;
        dist[0] = 0;
        que.push(0);

        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            if (cur == n - 1) break;
            for (int nxt : adj[cur]) {
                if (dist[nxt] == -1) {
                    dist[nxt] = dist[cur] + 1;
                    que.push(nxt);
                }
            }
        }

        answer.push_back(dist[n - 1]);
    }

    return answer;
}

ShortestDistanceAfterRoadAdditionQueriesISolution::ShortestDistanceAfterRoadAdditionQueriesISolution() {
    setMetaInfo({.id = 3243,
                  .title = "Shortest Distance After Road Addition Queries I",
                  .url = "https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/"});
    registerStrategy({.name = "BFS",
                      .expected = "Accepted",
                      .time_complexity = "O(q * (n + q))",
                      .space_complexity = "O(n + q)",
                      .tags = {"Array", "Breadth-First Search", "Graph"}},
                     shortestDistanceAfterQueriesImpl);
}

std::vector<int> ShortestDistanceAfterRoadAdditionQueriesISolution::shortestDistanceAfterQueries(
    int n, std::vector<std::vector<int>>& queries) {
    return getSolution()(n, queries);
}

} // namespace leetcode::problem_3243
