#include <algorithm>
#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/flower-planting-with-no-adjacent.h"

namespace leetcode::problem_1042 {

namespace {

bool IsValid(int n, const std::vector<std::vector<int>>& paths,
             const std::vector<int>& answer) {
  if (static_cast<int>(answer.size()) != n) return false;
  for (int c : answer) {
    if (c < 1 || c > 4) return false;
  }
  for (const auto& path : paths) {
    int a = path[0] - 1;
    int b = path[1] - 1;
    if (answer[a] == answer[b]) return false;
  }
  return true;
}

}  // namespace

class FlowerPlantingWithNoAdjacentTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  FlowerPlantingWithNoAdjacentSolution solution_;
};

TEST_P(FlowerPlantingWithNoAdjacentTest, Example1) {
  int n = 3;
  std::vector<std::vector<int>> paths = {{1, 2}, {2, 3}, {3, 1}};
  auto result = solution_.gardenNoAdj(n, paths);
  EXPECT_TRUE(IsValid(n, paths, result));
}

TEST_P(FlowerPlantingWithNoAdjacentTest, Example2) {
  int n = 4;
  std::vector<std::vector<int>> paths = {{1, 2}, {3, 4}};
  auto result = solution_.gardenNoAdj(n, paths);
  EXPECT_TRUE(IsValid(n, paths, result));
}

TEST_P(FlowerPlantingWithNoAdjacentTest, Example3) {
  int n = 4;
  std::vector<std::vector<int>> paths = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 3}, {2, 4}};
  auto result = solution_.gardenNoAdj(n, paths);
  EXPECT_TRUE(IsValid(n, paths, result));
}

TEST_P(FlowerPlantingWithNoAdjacentTest, SelfAuthoredSingleGarden) {
  int n = 1;
  std::vector<std::vector<int>> paths = {};
  auto result = solution_.gardenNoAdj(n, paths);
  EXPECT_TRUE(IsValid(n, paths, result));
}

TEST_P(FlowerPlantingWithNoAdjacentTest, SelfAuthoredStarGraph) {
  // Center garden 1 connected to a leaf 2. Degree of each <= 1.
  int n = 2;
  std::vector<std::vector<int>> paths = {{1, 2}};
  auto result = solution_.gardenNoAdj(n, paths);
  EXPECT_TRUE(IsValid(n, paths, result));
}

INSTANTIATE_TEST_SUITE_P(
    FlowerPlantingWithNoAdjacentTestCases, FlowerPlantingWithNoAdjacentTest,
    ::testing::ValuesIn(FlowerPlantingWithNoAdjacentSolution().getStrategyNames()));

}  // namespace leetcode::problem_1042
