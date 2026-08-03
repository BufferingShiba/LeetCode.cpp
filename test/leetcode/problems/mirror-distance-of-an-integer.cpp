#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/mirror-distance-of-an-integer.h"

using leetcode::problem_3783::MirrorDistanceOfAnIntegerSolution;

class MirrorDistanceOfAnIntegerTest
    : public ::testing::TestWithParam<std::string> {
protected:
    MirrorDistanceOfAnIntegerSolution solution;
    void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MirrorDistanceOfAnIntegerTest, Example1) {
    EXPECT_EQ(solution.mirrorDistance(25), 27);
}

TEST_P(MirrorDistanceOfAnIntegerTest, Example2) {
    EXPECT_EQ(solution.mirrorDistance(10), 9);
}

TEST_P(MirrorDistanceOfAnIntegerTest, Example3) {
    EXPECT_EQ(solution.mirrorDistance(7), 0);
}

TEST_P(MirrorDistanceOfAnIntegerTest, SelfAuthoredSingleDigit) {
    EXPECT_EQ(solution.mirrorDistance(9), 0);
}

TEST_P(MirrorDistanceOfAnIntegerTest, SelfAuthoredPalindrome) {
    EXPECT_EQ(solution.mirrorDistance(121), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MirrorDistanceOfAnIntegerVariants, MirrorDistanceOfAnIntegerTest,
    ::testing::ValuesIn(MirrorDistanceOfAnIntegerSolution().getStrategyNames()));
