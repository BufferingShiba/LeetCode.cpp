#include <gtest/gtest.h>

#include <string>
#include <utility>
#include <vector>

#include "leetcode/problems/count-ways-to-group-overlapping-ranges.h"

namespace leetcode::problem_2580 {

class CountWaysToGroupOverlappingRangesTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override {
        solution_.setStrategy(GetParam());
    }

    CountWaysToGroupOverlappingRangesSolution solution_;
};

TEST_P(CountWaysToGroupOverlappingRangesTest, Example1) {
    std::vector<std::vector<int>> ranges = {{6, 10}, {5, 15}};
    EXPECT_EQ(solution_.countWays(ranges), 2);
}

TEST_P(CountWaysToGroupOverlappingRangesTest, Example2) {
    std::vector<std::vector<int>> ranges = {{1, 3}, {10, 20}, {2, 5}, {4, 8}};
    EXPECT_EQ(solution_.countWays(ranges), 4);
}

TEST_P(CountWaysToGroupOverlappingRangesTest, SelfAuthoredSingleRange) {
    std::vector<std::vector<int>> ranges = {{1, 5}};
    EXPECT_EQ(solution_.countWays(ranges), 2);
}

TEST_P(CountWaysToGroupOverlappingRangesTest, SelfAuthoredAllDisjoint) {
    std::vector<std::vector<int>> ranges = {{1, 2}, {3, 4}, {5, 6}};
    EXPECT_EQ(solution_.countWays(ranges), 8);
}

TEST_P(CountWaysToGroupOverlappingRangesTest, SelfAuthoredLinearlyChained) {
    std::vector<std::vector<int>> ranges = {{1, 3}, {2, 5}, {4, 8}, {7, 9}};
    // all connected via transitive overlap -> 1 component
    EXPECT_EQ(solution_.countWays(ranges), 2);
}

INSTANTIATE_TEST_SUITE_P(
    CountWaysToGroupOverlappingRangesTestCases,
    CountWaysToGroupOverlappingRangesTest,
    ::testing::ValuesIn(
        CountWaysToGroupOverlappingRangesSolution().getStrategyNames()));

}  // namespace leetcode::problem_2580
