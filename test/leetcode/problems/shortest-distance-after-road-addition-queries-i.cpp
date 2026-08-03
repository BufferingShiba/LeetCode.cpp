#include <gtest/gtest.h>
#include "leetcode/problems/shortest-distance-after-road-addition-queries-i.h"

using namespace leetcode::problem_3243;

class ShortestDistanceAfterRoadAdditionQueriesITest : public testing::TestWithParam<std::string> {
protected:
    ShortestDistanceAfterRoadAdditionQueriesISolution solution;
    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(ShortestDistanceAfterRoadAdditionQueriesITest, Example1) {
    int n = 5;
    std::vector<std::vector<int>> queries = {{2, 4}, {0, 2}, {0, 4}};
    std::vector<int> expected = {3, 2, 1};
    EXPECT_EQ(solution.shortestDistanceAfterQueries(n, queries), expected);
}

TEST_P(ShortestDistanceAfterRoadAdditionQueriesITest, Example2) {
    int n = 4;
    std::vector<std::vector<int>> queries = {{0, 3}, {0, 2}};
    std::vector<int> expected = {1, 1};
    EXPECT_EQ(solution.shortestDistanceAfterQueries(n, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(, ShortestDistanceAfterRoadAdditionQueriesITest,
                         testing::ValuesIn(ShortestDistanceAfterRoadAdditionQueriesISolution().getStrategyNames()));
