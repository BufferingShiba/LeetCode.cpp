#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/circle-and-rectangle-overlapping.h"

namespace leetcode::problem_1401 {

class CircleAndRectangleOverlappingTest : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution_.setStrategy(GetParam());
    }

    CircleAndRectangleOverlappingSolution solution_;
};

TEST_P(CircleAndRectangleOverlappingTest, Example1) {
    EXPECT_TRUE(solution_.checkOverlap(1, 0, 0, 1, -1, 3, 1));
}

TEST_P(CircleAndRectangleOverlappingTest, Example2) {
    EXPECT_FALSE(solution_.checkOverlap(1, 1, 1, 1, -3, 2, -1));
}

TEST_P(CircleAndRectangleOverlappingTest, Example3) {
    EXPECT_TRUE(solution_.checkOverlap(1, 0, 0, -1, 0, 0, 1));
}

TEST_P(CircleAndRectangleOverlappingTest, SelfAuthoredCircleInsideRectangle) {
    EXPECT_TRUE(solution_.checkOverlap(1, 0, 0, -3, -3, 3, 3));
}

TEST_P(CircleAndRectangleOverlappingTest, SelfAuthoredCircleFarAway) {
    EXPECT_FALSE(solution_.checkOverlap(1, 10, 10, 0, 0, 2, 2));
}

TEST_P(CircleAndRectangleOverlappingTest, SelfAuthoredTouchCorner) {
    // center at (1,1), radius 1, rectangle bottom-left corner (2,2);
    // distance from center to closest rectangle point is sqrt(2) > 1 => no overlap.
    EXPECT_FALSE(solution_.checkOverlap(1, 1, 1, 2, 2, 3, 3));
}

INSTANTIATE_TEST_SUITE_P(
    CircleAndRectangleOverlappingTestSuite,
    CircleAndRectangleOverlappingTest,
    ::testing::ValuesIn(CircleAndRectangleOverlappingSolution().getStrategyNames()));

}  // namespace leetcode::problem_1401
