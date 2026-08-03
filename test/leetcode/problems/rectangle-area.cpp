#include "leetcode/problems/rectangle-area.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode::problem_223 {
namespace {

class RectangleAreaTest : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution_.setStrategy(GetParam());
    }

    RectangleAreaSolution solution_;
};

TEST_P(RectangleAreaTest, Example1) {
    EXPECT_EQ(solution_.getSolution()(-3, 0, 3, 4, 0, -1, 9, 2), 45);
}

TEST_P(RectangleAreaTest, Example2_OverlapFully) {
    EXPECT_EQ(solution_.getSolution()(-2, -2, 2, 2, -2, -2, 2, 2), 16);
}

TEST_P(RectangleAreaTest, SelfAuthoredNoOverlap) {
    EXPECT_EQ(solution_.getSolution()(0, 0, 1, 1, 2, 2, 3, 3), 2);
}

TEST_P(RectangleAreaTest, SelfAuthoredTouchEdge_NoOverlapArea) {
    EXPECT_EQ(solution_.getSolution()(0, 0, 2, 2, 2, 0, 4, 2), 8);
}

INSTANTIATE_TEST_SUITE_P(
    RectangleAreaTestSuite, RectangleAreaTest,
    ::testing::ValuesIn(RectangleAreaSolution().getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_223
