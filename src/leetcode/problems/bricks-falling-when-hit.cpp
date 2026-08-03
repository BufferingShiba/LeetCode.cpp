#include "leetcode/problems/bricks-falling-when-hit.h"

namespace leetcode::problem_803 {

namespace {

class DSU {
    std::vector<int> parent, sz;

 public:
    explicit DSU(int n) : parent(n), sz(n, 1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) std::swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }

    int size(int x) { return sz[find(x)]; }
};

std::vector<int> hitBricksImpl(std::vector<std::vector<int>>& grid,
                                std::vector<std::vector<int>>& hits) {
    int m = static_cast<int>(grid.size());
    int n = static_cast<int>(grid[0].size());
    int total = m * n;
    int ceiling = total;  // virtual stable node

    // Step 1: erase all hit positions
    auto copy = grid;
    for (auto& h : hits) {
        copy[h[0]][h[1]] = 0;
    }

    // Step 2: build DSU on remaining bricks
    DSU dsu(total + 1);
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            if (copy[r][c] == 0) continue;
            int id = r * n + c;
            // union with right and down to avoid duplicate edges
            if (r + 1 < m && copy[r + 1][c] == 1)
                dsu.unite(id, (r + 1) * n + c);
            if (c + 1 < n && copy[r][c + 1] == 1)
                dsu.unite(id, r * n + c + 1);
            // attach top row to ceiling
            if (r == 0) dsu.unite(id, ceiling);
        }
    }

    // Step 3: reverse process hits
    int H = static_cast<int>(hits.size());
    std::vector<int> result(H);

    for (int i = H - 1; i >= 0; --i) {
        int r = hits[i][0], c = hits[i][1];
        if (grid[r][c] == 0) {
            result[i] = 0;
            continue;
        }

        int before = dsu.size(ceiling);

        copy[r][c] = 1;
        int id = r * n + c;
        for (auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && copy[nr][nc] == 1) {
                dsu.unite(id, nr * n + nc);
            }
        }
        if (r == 0) dsu.unite(id, ceiling);

        int after = dsu.size(ceiling);
        result[i] = std::max(0, after - before - 1);
    }

    return result;
}

}  // namespace

BricksFallingWhenHitSolution::BricksFallingWhenHitSolution() {
    setMetaInfo(
        {.id = 803,
         .title = "Bricks Falling When Hit",
         .url = "https://leetcode.com/problems/bricks-falling-when-hit/"});
    registerStrategy(
        {.name = "ReverseUnionFind",
         .expected = "Accepted",
         .time_complexity = "O(m*n + h*α(mn))",
         .space_complexity = "O(m*n)",
         .tags = {"Array", "Union-Find", "Matrix"}},
        hitBricksImpl);
}

std::vector<int> BricksFallingWhenHitSolution::hitBricks(
    std::vector<std::vector<int>>& grid,
    std::vector<std::vector<int>>& hits) {
    return getSolution()(grid, hits);
}

}  // namespace leetcode::problem_803
