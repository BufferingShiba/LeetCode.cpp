#include "leetcode/problems/minimum-lines-to-represent-a-line-chart.h"

#include <algorithm>

namespace leetcode {
namespace problem_2280 {

static int solution1(vector<vector<int>>& stockPrices) {
  int n = static_cast<int>(stockPrices.size());
  if (n < 2) return 0;

  // Sort points by day (X-axis).
  std::sort(stockPrices.begin(), stockPrices.end(),
            [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

  // At least one line connects the first two points.
  int lines = 1;
  // Compare consecutive slopes using cross-multiplication to avoid floating point.
  auto sameSlope = [](long long dy1, long long dx1, long long dy2, long long dx2) {
    return dy1 * dx2 == dy2 * dx1;
  };

  long long prevDy = stockPrices[1][1] - stockPrices[0][1];
  long long prevDx = stockPrices[1][0] - stockPrices[0][0];
  for (int i = 1; i < n - 1; ++i) {
    long long curDy = stockPrices[i + 1][1] - stockPrices[i][1];
    long long curDx = stockPrices[i + 1][0] - stockPrices[i][0];
    if (!sameSlope(prevDy, prevDx, curDy, curDx)) {
      ++lines;
      prevDy = curDy;
      prevDx = curDx;
    }
  }
  return lines;
}

MinimumLinesToRepresentALineChartSolution::MinimumLinesToRepresentALineChartSolution() {
  setMetaInfo({
      .id = 2280,
      .title = "Minimum Lines to Represent a Line Chart",
      .url = "https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart"
  });
  registerStrategy({.name = "Brute Force",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "Sorting"}},
                   solution1);
}

int MinimumLinesToRepresentALineChartSolution::minimumLines(vector<vector<int>>& stockPrices) {
  return getSolution()(stockPrices);
}

}  // namespace problem_2280
}  // namespace leetcode
