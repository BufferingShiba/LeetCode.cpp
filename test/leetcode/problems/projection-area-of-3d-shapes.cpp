#include <gtest/gtest.h>

#include "leetcode/problems/projection-area-of-3d-shapes.h"

namespace leetcode::problem_883::test {

class ProjectionAreaOf3dShapesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ProjectionAreaOf3dShapesSolution solution_;
};

TEST_P(ProjectionAreaOf3dShapesTest, Example1) {
  std::vector<std::vector<int>> grid = {{1, 2}, {3, 4}};
  EXPECT_EQ(solution_.projectionArea(grid), 17);
}

TEST_P(ProjectionAreaOf3dShapesTest, Example2) {
  std::vector<std::vector<int>> grid = {{2}};
  EXPECT_EQ(solution_.projectionArea(grid), 5);
}

TEST_P(ProjectionAreaOf3dShapesTest, Example3) {
  std::vector<std::vector<int>> grid = {{1, 0}, {0, 2}};
  EXPECT_EQ(solution_.projectionArea(grid), 8);
}

TEST_P(ProjectionAreaOf3dShapesTest, SelfAuthoredAllZeros) {
  std::vector<std::vector<int>> grid = {{0, 0}, {0, 0}};
  EXPECT_EQ(solution_.projectionArea(grid), 0);
}

TEST_P(ProjectionAreaOf3dShapesTest, SelfAuthoredUniformHeight) {
  std::vector<std::vector<int>> grid = {{3, 3}, {3, 3}};
  // xy: 4, yz: 3+3=6, zx: 3+3=6 => 16
  EXPECT_EQ(solution_.projectionArea(grid), 16);
}

INSTANTIATE_TEST_SUITE_P(
    ProjectionAreaOf3dShapesTestInstance, ProjectionAreaOf3dShapesTest,
    ::testing::ValuesIn(ProjectionAreaOf3dShapesSolution().getStrategyNames()));

}  // namespace leetcode::problem_883::test
