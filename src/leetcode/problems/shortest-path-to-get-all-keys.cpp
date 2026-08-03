#include "leetcode/problems/shortest-path-to-get-all-keys.h"

#include <queue>
#include <utility>

namespace leetcode {
namespace problem_864 {

namespace {

constexpr int kDirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct State {
  int r;
  int c;
  int mask;
};

int shortestPathAllKeysImpl(std::vector<std::string>& grid) {
  const int m = static_cast<int>(grid.size());
  const int n = static_cast<int>(grid[0].size());

  int startR = 0, startC = 0;
  int totalKeys = 0;  // number of distinct keys in grid
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      char ch = grid[i][j];
      if (ch == '@') {
        startR = i;
        startC = j;
      } else if (ch >= 'a' && ch <= 'f') {
        ++totalKeys;
      }
    }
  }

  const int fullMask = (1 << totalKeys) - 1;
  const int maxStates = m * n * (1 << totalKeys);

  // BFS distance; reuse a flat vector, -1 means unvisited.
  std::vector<int> dist(maxStates, -1);
  auto encode = [n, totalKeys](int r, int c, int mask) {
    return (r * n + c) * (1 << totalKeys) + mask;
  };

  std::queue<State> q;
  q.push({startR, startC, 0});
  dist[encode(startR, startC, 0)] = 0;

  while (!q.empty()) {
    State cur = q.front();
    q.pop();
    int d = dist[encode(cur.r, cur.c, cur.mask)];

    if (cur.mask == fullMask) {
      return d;
    }

    for (int k = 0; k < 4; ++k) {
      int nr = cur.r + kDirs[k][0];
      int nc = cur.c + kDirs[k][1];
      if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
        continue;
      }
      char ch = grid[nr][nc];
      if (ch == '#') {
        continue;
      }

      int nmask = cur.mask;
      if (ch >= 'A' && ch <= 'F') {
        // lock: require corresponding key
        int keyBit = 1 << (ch - 'A');
        if ((cur.mask & keyBit) == 0) {
          continue;
        }
      } else if (ch >= 'a' && ch <= 'f') {
        // pick up key
        nmask |= (1 << (ch - 'a'));
      }

      int nid = encode(nr, nc, nmask);
      if (dist[nid] == -1) {
        dist[nid] = d + 1;
        q.push({nr, nc, nmask});
      }
    }
  }

  return -1;
}

}  // namespace

ShortestPathToGetAllKeysSolution::ShortestPathToGetAllKeysSolution() {
  setMetaInfo({.id = 864,
               .title = "Shortest Path to Get All Keys",
               .url = "https://leetcode.com/problems/shortest-path-to-get-all-keys/"});
  registerStrategy({.name = "BFS with Bitmask",
                    .expected = "Accepted",
                    .time_complexity = "O(m*n*2^k)",
                    .space_complexity = "O(m*n*2^k)",
                    .tags = {"Breadth-First Search", "Bit Manipulation", "Matrix"}},
                   shortestPathAllKeysImpl);
}

int ShortestPathToGetAllKeysSolution::shortestPathAllKeys(std::vector<std::string>& grid) {
  return getSolution()(grid);
}

}  // namespace problem_864
}  // namespace leetcode
