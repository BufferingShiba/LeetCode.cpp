#include <gtest/gtest.h>

#include "leetcode/problems/right-triangles.h"

using namespace leetcode::problem_3128;

class RightTrianglesTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  RightTrianglesSolution solution;
};

TEST_P(RightTrianglesTest, Example1) {
  std::vector<std::vector<int>> grid = {{0, 1, 0}, {0, 1, 1}, {0, 1, 0}};
  EXPECT_EQ(solution.numberOfRightTriangles(grid), 2);
}

TEST_P(RightTrianglesTest, Example2) {
  std::vector<std::vector<int>> grid = {
      {1, 0, 0, 0}, {0, 1, 0, 1}, {1, 0, 0, 0}};
  EXPECT_EQ(solution.numberOfRightTriangles(grid), 0);
}

TEST_P(RightTrianglesTest, Example3) {
  std::vector<std::vector<int>> grid = {{1, 0, 1}, {1, 0, 0}, {1, 0, 0}};
  EXPECT_EQ(solution.numberOfRightTriangles(grid), 2);
}

INSTANTIATE_TEST_SUITE_P(AllStrategies, RightTrianglesTest,
                         testing::ValuesIn(RightTrianglesSolution().getStrategyNames()));
