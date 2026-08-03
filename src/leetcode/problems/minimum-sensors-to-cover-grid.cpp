#include "leetcode/problems/minimum-sensors-to-cover-grid.h"

namespace leetcode {
namespace problem_3648 {

static int solution1(int n, int m, int k) {
  // Each sensor covers a (2k+1) x (2k+1) square in Chebyshev distance.
  // Greedy tiling: ceil(n / span) * ceil(m / span), where span = 2k + 1.
  long long span = 2LL * k + 1;
  long long rows = (n + span - 1) / span;
  long long cols = (m + span - 1) / span;
  return static_cast<int>(rows * cols);
}

MinimumSensorsToCoverGridSolution::MinimumSensorsToCoverGridSolution() {
  setMetaInfo({
      .id = 3648,
      .title = "Minimum Sensors to Cover Grid",
      .url = "https://leetcode.com/problems/minimum-sensors-to-cover-grid"
  });
  registerStrategy({.name = "Greedy Tiling"}, solution1);
}

int MinimumSensorsToCoverGridSolution::minSensors(int n, int m, int k) {
  return getSolution()(n, m, k);
}

}  // namespace problem_3648
}  // namespace leetcode
