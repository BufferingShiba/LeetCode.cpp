#include "leetcode/problems/find-latest-group-of-size-m.h"

#include <numeric>
#include <vector>

namespace leetcode {
namespace problem_1562 {

namespace {

class DSU {
public:
    explicit DSU(int n) : parent(n + 2), sz(n + 2, 0) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    int size(int x) { return sz[find(x)]; }

    // Union the segment containing a and b (roots unchanged tracking). Returns new root.
    int unite(int ra, int rb) {
        if (ra == rb) return ra;
        if (sz[ra] < sz[rb]) std::swap(ra, rb);
        parent[rb] = ra;
        sz[ra] += sz[rb];
        return ra;
    }

    void setSize(int x, int s) { sz[x] = s; }

private:
    std::vector<int> parent;
    std::vector<int> sz;
};

int findLatestStepImpl(std::vector<int>& arr, int m) {
    const int n = static_cast<int>(arr.size());
    std::vector<bool> active(n + 2, false);
    DSU dsu(n);
    int cnt = 0;  // number of groups of size m
    int ans = -1;

    auto merge = [&](int x, int y) {
        int rx = dsu.find(x);
        int ry = dsu.find(y);
        if (rx == ry) return;
        if (dsu.size(rx) == m) --cnt;
        if (dsu.size(ry) == m) --cnt;
        int root = dsu.unite(rx, ry);
        if (dsu.size(root) == m) ++cnt;
    };

    for (int i = 1; i <= n; ++i) {
        int p = arr[i - 1];
        active[p] = true;
        dsu.setSize(p, 1);
        if (m == 1) ++cnt;
        if (active[p - 1]) merge(p, p - 1);
        if (active[p + 1]) merge(p, p + 1);
        if (cnt > 0) ans = i;
    }
    return ans;
}

}  // namespace

FindLatestGroupOfSizeMSolution::FindLatestGroupOfSizeMSolution() {
    setMetaInfo({.id = 1562,
                 .title = "Find Latest Group of Size M",
                 .url = "https://leetcode.com/problems/find-latest-group-of-size-m/"});
    registerStrategy({.name = "union-find-forward",
                      .expected = "Accepted",
                      .time_complexity = "O(n * α(n))",
                      .space_complexity = "O(n)",
                      .tags = {"Union Find", "Simulation"}},
                     findLatestStepImpl);
}

int FindLatestGroupOfSizeMSolution::findLatestStep(std::vector<int>& arr, int m) {
    return getSolution()(arr, m);
}

}  // namespace problem_1562
}  // namespace leetcode
