#include "leetcode/problems/find-maximum-area-of-a-triangle.h"

#include <algorithm>
#include <climits>
#include <unordered_map>

namespace leetcode {
namespace problem_3588 {

static long long maxAreaImpl(std::vector<std::vector<int>>& coords) {
  int n = static_cast<int>(coords.size());
  if (n < 3) return -1;

  int global_min_x = INT_MAX, global_max_x = INT_MIN;
  int global_min_y = INT_MAX, global_max_y = INT_MIN;

  std::unordered_map<int, int> min_y_at_x, max_y_at_x;
  std::unordered_map<int, int> min_x_at_y, max_x_at_y;

  for (const auto& p : coords) {
    int x = p[0], y = p[1];

    global_min_x = std::min(global_min_x, x);
    global_max_x = std::max(global_max_x, x);
    global_min_y = std::min(global_min_y, y);
    global_max_y = std::max(global_max_y, y);

    auto it_x = min_y_at_x.find(x);
    if (it_x == min_y_at_x.end()) {
      min_y_at_x[x] = y;
      max_y_at_x[x] = y;
    } else {
      min_y_at_x[x] = std::min(min_y_at_x[x], y);
      max_y_at_x[x] = std::max(max_y_at_x[x], y);
    }

    auto it_y = min_x_at_y.find(y);
    if (it_y == min_x_at_y.end()) {
      min_x_at_y[y] = x;
      max_x_at_y[y] = x;
    } else {
      min_x_at_y[y] = std::min(min_x_at_y[y], x);
      max_x_at_y[y] = std::max(max_x_at_y[y], x);
    }
  }

  long long ans = -1;

  // Horizontal base (parallel to x-axis): shared y
  for (const auto& [y, min_x] : min_x_at_y) {
    int max_x = max_x_at_y[y];
    if (min_x == max_x) continue;  // need at least two points at this y
    long long base = static_cast<long long>(max_x) - min_x;

    if (global_max_y != y) {
      long long height = static_cast<long long>(global_max_y) - y;
      ans = std::max(ans, base * height);
    }
    if (global_min_y != y) {
      long long height = static_cast<long long>(y) - global_min_y;
      ans = std::max(ans, base * height);
    }
  }

  // Vertical base (parallel to y-axis): shared x
  for (const auto& [x, min_y] : min_y_at_x) {
    int max_y = max_y_at_x[x];
    if (min_y == max_y) continue;  // need at least two points at this x
    long long base = static_cast<long long>(max_y) - min_y;

    if (global_max_x != x) {
      long long height = static_cast<long long>(global_max_x) - x;
      ans = std::max(ans, base * height);
    }
    if (global_min_x != x) {
      long long height = static_cast<long long>(x) - global_min_x;
      ans = std::max(ans, base * height);
    }
  }

  return ans;
}

FindMaximumAreaOfATriangleSolution::FindMaximumAreaOfATriangleSolution() {
  setMetaInfo({.id = 3588,
               .title = "Find Maximum Area of a Triangle",
               .url = "https://leetcode.com/problems/find-maximum-area-of-a-triangle/"});
  registerStrategy(
      {.name = "Greedy",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "Math", "Greedy", "Geometry", "Enumeration"}},
      maxAreaImpl);
}

long long FindMaximumAreaOfATriangleSolution::maxArea(std::vector<std::vector<int>>& coords) {
  return getSolution()(coords);
}

}  // namespace problem_3588
}  // namespace leetcode
