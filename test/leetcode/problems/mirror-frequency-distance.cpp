#include "leetcode/problems/mirror-frequency-distance.h"
#include <gtest/gtest.h>
#include <string>

namespace leetcode::problem_3889 {

class MirrorFrequencyDistanceTest : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution_.setStrategy(GetParam());
    }

    MirrorFrequencyDistanceSolution solution_;
};

TEST_P(MirrorFrequencyDistanceTest, Example1) {
    EXPECT_EQ(solution_.mirrorFrequency("ab1z9"), 3);
}

TEST_P(MirrorFrequencyDistanceTest, Example2) {
    EXPECT_EQ(solution_.mirrorFrequency("4m7n"), 2);
}

TEST_P(MirrorFrequencyDistanceTest, Example3) {
    EXPECT_EQ(solution_.mirrorFrequency("byby"), 0);
}

TEST_P(MirrorFrequencyDistanceTest, SingleCharacter) {
    EXPECT_EQ(solution_.mirrorFrequency("a"), 1);
}

TEST_P(MirrorFrequencyDistanceTest, SymmetricMirrorPair) {
    EXPECT_EQ(solution_.mirrorFrequency("amp"), 3);
}

TEST_P(MirrorFrequencyDistanceTest, BalancedSinglePair) {
    EXPECT_EQ(solution_.mirrorFrequency("az"), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MirrorFrequencyDistanceStrategies, MirrorFrequencyDistanceTest,
    ::testing::ValuesIn(MirrorFrequencyDistanceSolution().getStrategyNames()));

}  // namespace leetcode::problem_3889
