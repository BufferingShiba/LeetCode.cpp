#include <gtest/gtest.h>

#include "leetcode/problems/painting-a-grid-with-three-different-colors.h"

namespace leetcode {
namespace problem_1931 {

class PaintingAGridWithThreeDifferentColorsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  PaintingAGridWithThreeDifferentColorsSolution solution_;
};

TEST_P(PaintingAGridWithThreeDifferentColorsTest, Example1) {
  EXPECT_EQ(solution_.colorTheGrid(1, 1), 3);
}

TEST_P(PaintingAGridWithThreeDifferentColorsTest, Example2) {
  EXPECT_EQ(solution_.colorTheGrid(1, 2), 6);
}

TEST_P(PaintingAGridWithThreeDifferentColorsTest, Example3) {
  EXPECT_EQ(solution_.colorTheGrid(5, 5), 580986);
}

TEST_P(PaintingAGridWithThreeDifferentColorsTest, SelfAuthoredSingleRowThreeCols) {
  // m=1: each row is just adjacent horizontal constraints.
  // 3*2*2 = 12.
  EXPECT_EQ(solution_.colorTheGrid(1, 3), 12);
}

INSTANTIATE_TEST_SUITE_P(
    PaintingAGridWithThreeDifferentColorsTests,
    PaintingAGridWithThreeDifferentColorsTest,
    ::testing::ValuesIn(PaintingAGridWithThreeDifferentColorsSolution().getStrategyNames()));

}  // namespace problem_1931
}  // namespace leetcode
