#include "leetcode/problems/cat-and-mouse-ii.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_1728 {

namespace {

bool canMouseWinImpl(std::vector<std::string>& grid, int catJump, int mouseJump) {
  const int rows = static_cast<int>(grid.size());
  const int cols = static_cast<int>(grid[0].size());
  int mousePos = 0, catPos = 0, food = 0;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      int id = i * cols + j;
      char ch = grid[i][j];
      if (ch == 'M') mousePos = id;
      else if (ch == 'C') catPos = id;
      else if (ch == 'F') food = id;
    }
  }
  const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  const int size = rows * cols;

  // memo[m][c][turn]: -1 unknown, 1 mouse wins, 0 mouse loses.
  // turn: 0 = mouse to move, 1 = cat to move.
  std::vector<std::vector<std::vector<int>>> memo(
      size, std::vector<std::vector<int>>(size, std::vector<int>(2, -1)));
  // onStack detects cycles along the current DFS path. In this game a loop
  // means the mouse cannot force the food within the 1000-turn limit, so the
  // mouse loses (return 0) for that branch.
  std::vector<std::vector<std::vector<char>>> onStack(
      size, std::vector<std::vector<char>>(size, std::vector<char>(2, 0)));

  std::function<int(int, int, int)> dfs = [&](int m, int c, int turn) -> int {
    if (m == food) return 1;
    if (c == food || c == m) return 0;
    int& res = memo[m][c][turn];
    if (res != -1) return res;
    if (onStack[m][c][turn]) return 0;
    onStack[m][c][turn] = 1;

    const int mr = m / cols, mc = m % cols;
    const int cr = c / cols, cc = c % cols;

    if (turn == 0) {
      // Mouse's turn: mouse wins if any move leads to a mouse-win state.
      res = 0;
      for (int d = 0; d < 4 && res == 0; ++d) {
        for (int step = 1; step <= mouseJump; ++step) {
          int nr = mr + dirs[d][0] * step;
          int nc = mc + dirs[d][1] * step;
          if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) break;
          if (grid[nr][nc] == '#') break;
          int nm = nr * cols + nc;
          if (nm == c) continue;  // landing on cat means being caught; not a win
          if (dfs(nm, c, 1)) { res = 1; break; }
        }
      }
      if (res == 0 && dfs(m, c, 1)) res = 1;  // mouse may stay in place
    } else {
      // Cat's turn: mouse wins only if every cat move leaves a mouse-win state.
      int mouseWins = 1;
      for (int d = 0; d < 4 && mouseWins == 1; ++d) {
        for (int step = 0; step <= catJump; ++step) {
          if (step == 0) {
            if (!dfs(m, c, 0)) { mouseWins = 0; break; }
            continue;
          }
          int nr = cr + dirs[d][0] * step;
          int nc = cc + dirs[d][1] * step;
          if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) break;
          if (grid[nr][nc] == '#') break;
          int np = nr * cols + nc;
          if (np == m) {          // cat catches the mouse -> mouse loses
            mouseWins = 0;
            break;
          }
          if (np == food) { mouseWins = 0; break; }  // cat reaches food first
          if (!dfs(m, np, 0)) { mouseWins = 0; break; }
        }
      }
      res = (mouseWins ? 1 : 0);
    }
    onStack[m][c][turn] = 0;
    return res;
  };

  return dfs(mousePos, catPos, 0) == 1;
}
}  // namespace

CatAndMouseIiSolution::CatAndMouseIiSolution() {
  setMetaInfo({.id = 1728,
               .title = "Cat and Mouse II",
               .url = "https://leetcode.com/problems/cat-and-mouse-ii/"});
  registerStrategy(
      {.name = "Minimax DFS + cycle detection",
       .expected = "Accepted",
       .time_complexity = "O((rows*cols)^2 * (mouseJump+catJump))",
       .space_complexity = "O((rows*cols)^2)",
       .tags = {"Memoization", "Game Theory", "Depth-First Search", "Matrix"}},
      canMouseWinImpl);
}

bool CatAndMouseIiSolution::canMouseWin(std::vector<std::string>& grid,
                                        int catJump, int mouseJump) {
  return getSolution()(grid, catJump, mouseJump);
}

}  // namespace leetcode::problem_1728
