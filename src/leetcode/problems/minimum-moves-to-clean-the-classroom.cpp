#include "leetcode/problems/minimum-moves-to-clean-the-classroom.h"

#include <queue>
#include <tuple>
#include <utility>
#include <vector>

namespace leetcode::problem_3568 {
namespace {

int minMovesImpl(std::vector<std::string>& classroom, int energy) {
  const int m = static_cast<int>(classroom.size());
  const int n = static_cast<int>(classroom[0].size());

  int startR = -1, startC = -1;
  std::vector<std::pair<int, int>> litPos;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (classroom[i][j] == 'S') {
        startR = i;
        startC = j;
      } else if (classroom[i][j] == 'L') {
        litPos.emplace_back(i, j);
      }
    }
  }

  const int k = static_cast<int>(litPos.size());
  if (k == 0) return 0;
  const int allMask = (1 << k) - 1;

  auto bitOf = [&](int r, int c) -> int {
    for (int i = 0; i < k; ++i) {
      if (litPos[i].first == r && litPos[i].second == c) return i;
    }
    return -1;
  };

  // bestEng[r][c][mask] = max energy seen for state (pos, mask).
  std::vector<std::vector<std::vector<int>>> bestEng(
      m, std::vector<std::vector<int>>(n, std::vector<int>(1 << k, -1)));

  bestEng[startR][startC][0] = energy;
  std::queue<std::tuple<int, int, int, int, int>> q;  // r, c, mask, energy, dist
  q.emplace(startR, startC, 0, energy, 0);

  const int dr[4] = {-1, 1, 0, 0};
  const int dc[4] = {0, 0, -1, 1};

  while (!q.empty()) {
    auto [r, c, mask, e, dist] = q.front();
    q.pop();

    if (mask == allMask) return dist;

    // Cannot move further with zero energy unless on a reset area.
    if (e == 0 && classroom[r][c] != 'R') continue;

    for (int d = 0; d < 4; ++d) {
      int nr = r + dr[d];
      int nc = c + dc[d];
      if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
      if (classroom[nr][nc] == 'X') continue;

      int nmask = mask;
      int b = bitOf(nr, nc);
      if (b >= 0) nmask |= (1 << b);

      int ne;
      if (classroom[nr][nc] == 'R') {
        ne = energy;
      } else {
        if (e >= 1) {
          ne = e - 1;
        } else {
          // e == 0 while on a reset area, but moving off it costs energy; from
          // a reset area energy is already full, so e==0 here means unmovable
          // non-R position, already skipped above.
          continue;
        }
      }

      if (ne > bestEng[nr][nc][nmask]) {
        bestEng[nr][nc][nmask] = ne;
        q.emplace(nr, nc, nmask, ne, dist + 1);
      }
    }
  }

  return -1;
}

}  // namespace

MinimumMovesToCleanTheClassroom::MinimumMovesToCleanTheClassroom() {
  setMetaInfo({.id = 3568,
               .title = "Minimum Moves to Clean the Classroom",
               .url = "https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/"});
  registerStrategy(
      {"state-compressed-bfs", "Accepted", "O(m*n*2^k)", "O(m*n*2^k)",
       {std::string("Breadth-First Search"), std::string("Bit Manipulation"),
        std::string("Array"), std::string("Matrix")},
       "BFS over (row, col, litterMask, energy) with max-energy pruning per "
       "(position, mask)."},
      minMovesImpl);
}

int MinimumMovesToCleanTheClassroom::minMoves(std::vector<std::string>&
                                                  classroom,
                                              int energy) {
  return getSolution()(classroom, energy);
}

}  // namespace leetcode::problem_3568
