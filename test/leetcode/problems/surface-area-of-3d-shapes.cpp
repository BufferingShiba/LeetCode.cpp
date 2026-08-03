#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/surface-area-of-3d-shapes.h"

namespace leetcode {
namespace problem_892 {
namespace {

class SurfaceAreaOf3dShapesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SurfaceAreaOf3dShapesSolution solution;
};

TEST_P(SurfaceAreaOf3dShapesTest, Example1) {
  std::vector<std::vector<int>> grid = {{1, 2}, {3, 4}};
  EXPECT_EQ(34, solution.surfaceArea(grid));
}

TEST_P(SurfaceAreaOf3dShapesTest, Example2) {
  std::vector<std::vector<int>> grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  EXPECT_EQ(32, solution.surfaceArea(grid));
}

TEST_P(SurfaceAreaOf3dShapesTest, Example3) {
  std::vector<std::vector<int>> grid = {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}};
  EXPECT_EQ(46, solution.surfaceArea(grid));
}

TEST_P(SurfaceAreaOf3dShapesTest, SelfAuthoredSingleCube) {
  std::vector<std::vector<int>> grid = {{1}};
  EXPECT_EQ(6, solution.surfaceArea(grid));
}

INSTANTIATE_TEST_SUITE_P(
    SurfaceAreaOf3dShapesTestSuite, SurfaceAreaOf3dShapesTest,
    ::testing::ValuesIn(SurfaceAreaOf3dShapesSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_892
}  // namespace leetcode
