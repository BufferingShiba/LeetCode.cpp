#include <gtest/gtest.h>

#include "leetcode/problems/ransom-note.h"

namespace leetcode::problem_383 {

class RansomNoteTest : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override { solution.setStrategy(GetParam()); }

    RansomNoteSolution solution;
};

TEST_P(RansomNoteTest, Example1) {
    EXPECT_FALSE(solution.canConstruct("a", "b"));
}

TEST_P(RansomNoteTest, Example2) {
    EXPECT_FALSE(solution.canConstruct("aa", "ab"));
}

TEST_P(RansomNoteTest, Example3) {
    EXPECT_TRUE(solution.canConstruct("aa", "aab"));
}

TEST_P(RansomNoteTest, SelfAuthored_ExactMatch) {
    EXPECT_TRUE(solution.canConstruct("abc", "cba"));
}

TEST_P(RansomNoteTest, SelfAuthored_EmptyMagazineShortage) {
    EXPECT_FALSE(solution.canConstruct("ab", "a"));
}

INSTANTIATE_TEST_SUITE_P(RansomNoteTestSuite, RansomNoteTest,
                         ::testing::ValuesIn(RansomNoteSolution().getStrategyNames()));

}  // namespace leetcode::problem_383
