#include "leetcode/problems/find-all-good-strings.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1397 {

class FindAllGoodStringsTest : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution.setStrategy(GetParam());
    }
    FindAllGoodStringsSolution solution;
};

TEST_P(FindAllGoodStringsTest, Example1) {
    EXPECT_EQ(solution.getSolution()(2, "aa", "da", "b"), 51);
}

TEST_P(FindAllGoodStringsTest, Example2) {
    EXPECT_EQ(solution.getSolution()(8, "leetcode", "leetgoes", "leet"), 0);
}

TEST_P(FindAllGoodStringsTest, Example3) {
    EXPECT_EQ(solution.getSolution()(2, "gx", "gz", "x"), 2);
}

TEST_P(FindAllGoodStringsTest, SelfAuthoredSingleNoEvilBoundary) {
    // n=1, evil has length... if evil longer than n, cannot appear. Good strings = all in [s1,s2].
    EXPECT_EQ(solution.getSolution()(1, "a", "a", "ab"), 1);
    // [b,c] with evil "a"
    EXPECT_EQ(solution.getSolution()(1, "b", "c", "a"), 2);
}

TEST_P(FindAllGoodStringsTest, SelfAuthoredRangeExcludesEvilStart) {
    // n=1, s1="a", s2="z", evil="b" -> all except 'b' = 25
    EXPECT_EQ(solution.getSolution()(1, "a", "z", "b"), 25);
}

INSTANTIATE_TEST_SUITE_P(
    FindAllGoodStringsSuite,
    FindAllGoodStringsTest,
    ::testing::ValuesIn(FindAllGoodStringsSolution().getStrategyNames()));

}  // namespace problem_1397
}  // namespace leetcode
