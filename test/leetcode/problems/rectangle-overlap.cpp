#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/rectangle-overlap.h"

namespace leetcode {
namespace problem_836 {
namespace {

class RectangleOverlapTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  RectangleOverlapSolution solution_;
};

TEST_P(RectangleOverlapTest, Example1) {
  std::vector<int> rec1{0, 0, 2, 2};
  std::vector<int> rec2{1, 1, 3, 3};
  EXPECT_TRUE(solution_.isRectangleOverlap(rec1, rec2));
}

TEST_P(RectangleOverlapTest, Example2) {
  std::vector<int> rec1{0, 0, 1, 1};
  std::vector<int> rec2{1, 0, 2, 1};
  EXPECT_FALSE(solution_.isRectangleOverlap(rec1, rec2));
}

TEST_P(RectangleOverlapTest, Example3) {
  std::vector<int> rec1{0, 0, 1, 1};
  std::vector<int> rec2{2, 2, 3, 3};
  EXPECT_FALSE(solution_.isRectangleOverlap(rec1, rec2));
}

TEST_P(RectangleOverlapTest, SelfAuthoredEdgeTouchingEdge) {
  std::vector<int> rec1{0, 0, 2, 2};
  std::vector<int> rec2{2, 0, 4, 2};
  EXPECT_FALSE(solution_.isRectangleOverlap(rec1, rec2));
}

TEST_P(RectangleOverlapTest, SelfAuthoredEdgeTouchingCorner) {
  std::vector<int> rec1{0, 0, 2, 2};
  std::vector<int> rec2{2, 2, 3, 3};
  EXPECT_FALSE(solution_.isRectangleOverlap(rec1, rec2));
}

TEST_P(RectangleOverlapTest, SelfAuthoredContainedRect) {
  std::vector<int> rec1{0, 0, 5, 5};
  std::vector<int> rec2{1, 1, 2, 2};
  EXPECT_TRUE(solution_.isRectangleOverlap(rec1, rec2));
}

INSTANTIATE_TEST_SUITE_P(
    RectangleOverlapTestSuite, RectangleOverlapTest,
    ::testing::ValuesIn(RectangleOverlapSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_836
}  // namespace leetcode
