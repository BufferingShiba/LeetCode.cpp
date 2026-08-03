#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/map-of-highest-peak.h"

namespace leetcode::problem_1765 {

class MapOfHighestPeakTest : public ::testing::TestWithParam<std::string> {
 protected:
  MapOfHighestPeakSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }

  static void ValidateAssignment(const std::vector<std::vector<int>>& isWater,
                                 const std::vector<std::vector<int>>& height) {
    const int m = static_cast<int>(isWater.size());
    const int n = static_cast<int>(isWater[0].size());
    ASSERT_EQ(height.size(), static_cast<size_t>(m));

    for (int i = 0; i < m; ++i) {
      ASSERT_EQ(height[i].size(), static_cast<size_t>(n));
      for (int j = 0; j < n; ++j) {
        EXPECT_GE(height[i][j], 0) << "height must be non-negative at (" << i << "," << j << ")";
        if (isWater[i][j] == 1) {
          EXPECT_EQ(height[i][j], 0) << "water cell must have height 0 at (" << i << "," << j << ")";
        }
      }
    }

    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (const auto& d : dirs) {
          const int nx = i + d[0];
          const int ny = j + d[1];
          if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
          EXPECT_LE(std::abs(height[i][j] - height[nx][ny]), 1)
              << "adjacent diff exceeds 1 at (" << i << "," << j << ")-(\\" << nx << "," << ny << ")";
        }
      }
    }
  }
};

TEST_P(MapOfHighestPeakTest, Example1) {
  std::vector<std::vector<int>> isWater = {{0, 1}, {0, 0}};
  auto result = solution.highestPeak(isWater);
  ValidateAssignment(isWater, result);
  // Expected (any valid): distances from nearest water.
  std::vector<std::vector<int>> expected = {{1, 0}, {2, 1}};
  EXPECT_EQ(result, expected);
}

TEST_P(MapOfHighestPeakTest, Example2) {
  std::vector<std::vector<int>> isWater = {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
  auto result = solution.highestPeak(isWater);
  ValidateAssignment(isWater, result);
  std::vector<std::vector<int>> expected = {{1, 1, 0}, {0, 1, 1}, {1, 2, 2}};
  EXPECT_EQ(result, expected);
}

TEST_P(MapOfHighestPeakTest, SelfAuthoredSingleWaterSingleCell) {
  std::vector<std::vector<int>> isWater = {{1}};
  auto result = solution.highestPeak(isWater);
  std::vector<std::vector<int>> expected = {{0}};
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    MapOfHighestPeakTestSuite, MapOfHighestPeakTest,
    ::testing::ValuesIn(MapOfHighestPeakSolution().getStrategyNames()));

}  // namespace leetcode::problem_1765
