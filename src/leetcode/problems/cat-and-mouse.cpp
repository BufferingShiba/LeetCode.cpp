#include "leetcode/problems/cat-and-mouse.h"

#include <queue>
#include <tuple>

namespace leetcode::problem_913 {

namespace {

constexpr int DRAW = 0;
constexpr int MOUSE = 1;
constexpr int CAT = 2;

int catMouseGameImpl(std::vector<std::vector<int>>& graph) {
  const int n = static_cast<int>(graph.size());

  auto contains = [&](int node, int target) {
    for (int nb : graph[node]) {
      if (nb == target) return true;
    }
    return false;
  };

  // color[turn][m][c]: turn 0 = mouse's turn, 1 = cat's turn.
  // value: DRAW(0) unknown, MOUSE(1), CAT(2).
  std::vector<std::vector<std::vector<int>>> color(
      2, std::vector<std::vector<int>>(n, std::vector<int>(n, DRAW)));
  // degree: number of moves leading to an *active* intermediate state.
  std::vector<std::vector<std::vector<int>>> degree(
      2, std::vector<std::vector<int>>(n, std::vector<int>(n, 0)));

  std::queue<std::tuple<int, int, int>> q;

  for (int m = 1; m < n; ++m) {
    for (int c = 1; c < n; ++c) {
      // mouse's turn: moves to x in graph[m], only active states count.
      // Terminal results: x == 0 (mouse wins), x == c (cat wins immediately).
      int d0 = 0;
      for (int x : graph[m]) {
        if (x != 0 && x != c) ++d0;
      }
      degree[0][m][c] = d0;

      // cat's turn: moves to y in graph[c], y != 0, y != m.
      int d1 = 0;
      for (int y : graph[c]) {
        if (y != 0 && y != m) ++d1;
      }
      degree[1][m][c] = d1;

      // Seed terminal states.
      // Mouse turn, mouse can step into the hole -> mouse wins.
      if (contains(m, 0)) {
        color[0][m][c] = MOUSE;
        q.emplace(m, c, 0);
      }
      // Mouse turn, mouse has no active move and no hole escape: every
      // possible move steps into the cat (x == c), so the cat captures it
      // and wins immediately -> cat wins.
      if (d0 == 0 && !contains(m, 0)) {
        color[0][m][c] = CAT;
        q.emplace(m, c, 0);
      }
      // Cat turn, cat can capture the mouse (mouse is a neighbor) -> cat wins.
      if (contains(c, m)) {
        color[1][m][c] = CAT;
        q.emplace(m, c, 1);
      }
    }
  }

  while (!q.empty()) {
    auto [m, c, turn] = q.front();
    q.pop();
    int winner = color[turn][m][c];

    if (turn == 0) {
      // Current state (mouse's turn) reached after cat moved c2 -> c.
      // Predecessors: (m, c2, 1), where c2 adjacent to c, c2 != 0, c2 != m.
      for (int c2 : graph[c]) {
        if (c2 == 0 || c2 == m) continue;
        int& pc = color[1][m][c2];
        if (pc != DRAW) continue;
        if (winner == CAT) {
          // Cat moves into a cat-winning state.
          pc = CAT;
          q.emplace(m, c2, 1);
        } else {
          // That move loses for cat; reduce its remaining lazy count.
          if (--degree[1][m][c2] == 0) {
            pc = MOUSE;
            q.emplace(m, c2, 1);
          }
        }
      }
    } else {
      // Current state (cat's turn) reached after mouse moved m2 -> m.
      // Predecessors: (m2, c, 0), where m2 adjacent to m, m2 != 0, m2 != c.
      for (int m2 : graph[m]) {
        if (m2 == 0 || m2 == c) continue;
        int& pc = color[0][m2][c];
        if (pc != DRAW) continue;
        if (winner == MOUSE) {
          pc = MOUSE;
          q.emplace(m2, c, 0);
        } else {
          if (--degree[0][m2][c] == 0) {
            pc = CAT;
            q.emplace(m2, c, 0);
          }
        }
      }
    }
  }

  return color[0][1][2];
}

}  // namespace

CatAndMouseSolution::CatAndMouseSolution() {
  setMetaInfo({.id = 913,
               .title = "Cat and Mouse",
               .url = "https://leetcode.com/problems/cat-and-mouse/"});

  registerStrategy(
      {
          .name = "RetrogradeTopologicalBFS",
          .expected = "Accepted",
          .time_complexity = "O(n^3)",
          .space_complexity = "O(n^2)",
          .tags = {"Game Theory", "BFS", "Topological Sort", "Memoization"},
      },
      catMouseGameImpl);
}

}  // namespace leetcode::problem_913
