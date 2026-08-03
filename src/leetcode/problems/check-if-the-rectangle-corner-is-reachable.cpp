#include "leetcode/problems/check-if-the-rectangle-corner-is-reachable.h"

#include <vector>

namespace leetcode {
namespace problem_3235 {

namespace {

class DSU {
 public:
  DSU(int n) : parent_(n), rank_(n, 0) {
    for (int i = 0; i < n; ++i) parent_[i] = i;
  }

  int find(int x) {
    if (parent_[x] != x) parent_[x] = find(parent_[x]);
    return parent_[x];
  }

  void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx == ry) return;
    if (rank_[rx] < rank_[ry])
      parent_[rx] = ry;
    else if (rank_[rx] > rank_[ry])
      parent_[ry] = rx;
    else {
      parent_[ry] = rx;
      ++rank_[rx];
    }
  }

 private:
  std::vector<int> parent_;
  std::vector<int> rank_;
};

bool canReachCornerImpl(int xCorner, int yCorner,
                        std::vector<std::vector<int>>& circles) {
  using ll = long long;
  ll X = xCorner, Y = yCorner;
  int n = static_cast<int>(circles.size());

  // 1. 检查起点/终点是否在某个圆内（含边界）
  for (int i = 0; i < n; ++i) {
    ll x = circles[i][0], y = circles[i][1], r = circles[i][2];
    ll r2 = r * r;
    // 起点 (0,0)
    if (x * x + y * y <= r2) return false;
    // 终点 (X,Y)
    ll dx = X - x, dy = Y - y;
    if (dx * dx + dy * dy <= r2) return false;
  }

  // 2. 并查集：前 n 个节点为圆，额外两个虚拟节点
  DSU dsu(n + 2);
  const int SOURCE = n;  // 左上边界（左边界 ∪ 上边界）
  const int SINK = n + 1;  // 右下边界（右边界 ∪ 下边界）

  for (int i = 0; i < n; ++i) {
    ll x = circles[i][0], y = circles[i][1], r = circles[i][2];
    ll r2 = r * r;

    // 圆到矩形区域 [0,X]×[0,Y] 的最短距离平方
    ll dx2 = 0;
    if (x < 0)
      dx2 = x * x;
    else if (x > X)
      dx2 = (x - X) * (x - X);

    ll dy2 = 0;
    if (y < 0)
      dy2 = y * y;
    else if (y > Y)
      dy2 = (y - Y) * (y - Y);

    // 左边界 (x=0)
    if (x * x + dy2 <= r2) dsu.unite(i, SOURCE);
    // 上边界 (y=Y)
    ll topDy = Y - y;
    if (topDy * topDy + dx2 <= r2) dsu.unite(i, SOURCE);

    // 右边界 (x=X)
    ll rightDx = X - x;
    if (rightDx * rightDx + dy2 <= r2) dsu.unite(i, SINK);
    // 下边界 (y=0)
    if (y * y + dx2 <= r2) dsu.unite(i, SINK);
  }

  // 3. 圆-圆相交判断
  for (int i = 0; i < n; ++i) {
    ll xi = circles[i][0], yi = circles[i][1], ri = circles[i][2];
    for (int j = i + 1; j < n; ++j) {
      ll xj = circles[j][0], yj = circles[j][1], rj = circles[j][2];
      ll dx = xi - xj, dy = yi - yj;
      ll dist2 = dx * dx + dy * dy;
      ll sumR = ri + rj;
      if (dist2 <= sumR * sumR) {
        dsu.unite(i, j);
      }
    }
  }

  // 4. 如果左上边界与右下边界连通，则路径被阻断
  if (dsu.find(SOURCE) == dsu.find(SINK)) return false;
  return true;
}

}  // namespace

CheckIfTheRectangleCornerIsReachableSolution::
    CheckIfTheRectangleCornerIsReachableSolution() {
  setMetaInfo({.id = 3235,
               .title = "Check if the Rectangle Corner Is Reachable",
               .url = "https://leetcode.com/problems/check-if-the-rectangle-corner-is-reachable/"});
  registerStrategy(
      {.name = "union-find",
       .expected = "Accepted",
       .time_complexity = "O(N^2)",
       .space_complexity = "O(N)",
       .tags = {"Array", "Math", "Depth-First Search", "Breadth-First Search",
                "Union-Find", "Geometry"}},
      canReachCornerImpl);
}

bool CheckIfTheRectangleCornerIsReachableSolution::canReachCorner(
    int xCorner, int yCorner, std::vector<std::vector<int>>& circles) {
  return getSolution()(xCorner, yCorner, circles);
}

}  // namespace problem_3235
}  // namespace leetcode
