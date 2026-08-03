#include "leetcode/problems/relative-ranks.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode::problem_506 {

namespace {

using namespace std::string_literals;

}  // namespace

class RelativeRanksTest : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override { solution.setStrategy(GetParam()); }

    RelativeRanksSolution solution;
};

TEST_P(RelativeRanksTest, Example1) {
    std::vector<int> score{5, 4, 3, 2, 1};
    const std::vector<std::string> expected = {"Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"};
    EXPECT_EQ(solution.findRelativeRanks(score), expected);
}

TEST_P(RelativeRanksTest, Example2) {
    std::vector<int> score{10, 3, 8, 9, 4};
    const std::vector<std::string> expected = {"Gold Medal", "5", "Bronze Medal", "Silver Medal", "4"};
    EXPECT_EQ(solution.findRelativeRanks(score), expected);
}

TEST_P(RelativeRanksTest, SelfAuthoredSingleAthlete) {
    std::vector<int> score{7};
    const std::vector<std::string> expected = {"Gold Medal"};
    EXPECT_EQ(solution.findRelativeRanks(score), expected);
}

TEST_P(RelativeRanksTest, SelfAuthoredTwoAthletes) {
    std::vector<int> score{100, 56};
    const std::vector<std::string> expected = {"Gold Medal", "Silver Medal"};
    EXPECT_EQ(solution.findRelativeRanks(score), expected);
}

INSTANTIATE_TEST_SUITE_P(
    RelativeRanksTestCases,
    RelativeRanksTest,
    ::testing::ValuesIn(RelativeRanksSolution().getStrategyNames()));

}  // namespace leetcode::problem_506
