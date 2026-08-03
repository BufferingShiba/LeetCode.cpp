#include "leetcode/problems/k-highest-ranked-items-within-a-price-range.h"

#include <algorithm>
#include <queue>

namespace leetcode {
namespace problem_2146 {

namespace {

int highestRankedKItemsImpl(std::vector<std::vector<int>>& grid,
                            std::vector<int>& pricing, std::vector<int>& start,
                            int k,
                            std::vector<std::vector<int>>& out) {
  const int m = static_cast<int>(grid.size());
  const int n = static_cast<int>(grid[0].size());
  const int low = pricing[0];
  const int high = pricing[1];

  const int sr = start[0];
  const int sc = start[1];

  std::vector<std::vector<int>> dist(m, std::vector<int>(n, -1));
  std::queue<std::pair<int, int>> q;
  dist[sr][sc] = 0;
  q.push({sr, sc});

  const int dr[4] = {1, -1, 0, 0};
  const int dc[4] = {0, 0, 1, -1};

  struct Item {
    int distance;
    int price;
    int row;
    int col;
  };
  std::vector<Item> items;

  // Start cell must have price > 0 (guaranteed by constraints).
  int startPrice = grid[sr][sc];
  if (startPrice >= low && startPrice <= high) {
    items.push_back({0, startPrice, sr, sc});
  }

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();
    for (int d = 0; d < 4; ++d) {
      int nr = r + dr[d];
      int nc = c + dc[d];
      if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
      if (grid[nr][nc] == 0) continue;
      if (dist[nr][nc] != -1) continue;
      dist[nr][nc] = dist[r][c] + 1;
      q.push({nr, nc});
      int price = grid[nr][nc];
      if (price >= low && price <= high) {
        items.push_back({dist[nr][nc], price, nr, nc});
      }
    }
  }

  std::sort(items.begin(), items.end(),
            [](const Item& a, const Item& b) {
              if (a.distance != b.distance) return a.distance < b.distance;
              if (a.price != b.price) return a.price < b.price;
              if (a.row != b.row) return a.row < b.row;
              return a.col < b.col;
            });

  int take = std::min(k, static_cast<int>(items.size()));
  out.clear();
  out.reserve(take);
  for (int i = 0; i < take; ++i) {
    out.push_back({items[i].row, items[i].col});
  }
  return take;
}

}  // namespace

KHighestRankedItemsWithinAPriceRangeSolution::
    KHighestRankedItemsWithinAPriceRangeSolution() {
  setMetaInfo({2146, "K Highest Ranked Items Within a Price Range",
               "https://leetcode.com/problems/"
               "k-highest-ranked-items-within-a-price-range/"});
  registerStrategy(
      {"BFS + Sort", "Accepted", "O(m*n log(m*n))", "O(m*n)",
       {"Breadth-First Search", "Sorting", "Array", "Matrix"}},
      [](std::vector<std::vector<int>>& grid, std::vector<int>& pricing,
         std::vector<int>& start, int k) -> std::vector<std::vector<int>> {
        std::vector<std::vector<int>> result;
        highestRankedKItemsImpl(grid, pricing, start, k, result);
        return result;
      });
}

std::vector<std::vector<int>>
KHighestRankedItemsWithinAPriceRangeSolution::highestRankedKItems(
    std::vector<std::vector<int>>& grid, std::vector<int>& pricing,
    std::vector<int>& start, int k) {
  return getSolution()(grid, pricing, start, k);
}

}  // namespace problem_2146
}  // namespace leetcode
