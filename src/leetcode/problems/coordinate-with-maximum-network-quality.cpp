#include "leetcode/problems/coordinate-with-maximum-network-quality.h"

#include <cmath>
#include <cstdint>

namespace leetcode {
namespace problem_1620 {
namespace {

// 暴力枚举 [0,50]×[0,50] 所有整数坐标点，计算每个点处网络质量总和。
std::vector<int> bestCoordinateImpl(std::vector<std::vector<int>>& towers,
                                    int radius) {
  int bestX = 0, bestY = 0;
  long long bestQuality = -1;

  double radiusSq = static_cast<double>(radius) * radius;

  for (int x = 0; x <= 50; ++x) {
    for (int y = 0; y <= 50; ++y) {
      long long total = 0;
      for (const auto& tower : towers) {
        int tx = tower[0], ty = tower[1], q = tower[2];
        int dx = x - tx;
        int dy = y - ty;
        double distSq =
            static_cast<double>(dx) * dx + static_cast<double>(dy) * dy;
        if (distSq > radiusSq + 1e-9) continue;  // 不可达
        double d = std::sqrt(distSq);
        total += static_cast<long long>(q / (1.0 + d));
      }
      // 字典序最小：先 x 小再 y 小；由于按 x,y 递增枚举，> 时更新（保留更小的坐标）
      if (total > bestQuality) {
        bestQuality = total;
        bestX = x;
        bestY = y;
      }
    }
  }

  return {bestX, bestY};
}

}  // namespace

CoordinateWithMaximumNetworkQualitySolution::
    CoordinateWithMaximumNetworkQualitySolution() {
  setMetaInfo(
      {.id = 1620,
       .title = "Coordinate With Maximum Network Quality",
       .url = "https://leetcode.com/problems/coordinate-with-maximum-network-quality/"});
  registerStrategy(
      {.name = "BruteForceEnum",
       .expected = "Accepted",
       .time_complexity = "O(51*51*N) where N<=50",
       .space_complexity = "O(1)",
       .tags = {"Array", "Enumeration"}},
      bestCoordinateImpl);
}

std::vector<int> CoordinateWithMaximumNetworkQualitySolution::bestCoordinate(
    std::vector<std::vector<int>>& towers, int radius) {
  return getSolution()(towers, radius);
}

}  // namespace problem_1620
}  // namespace leetcode
