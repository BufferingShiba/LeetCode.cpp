#include "leetcode/problems/count-covered-buildings.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode::problem_3531 {

class CountCoveredBuildingsTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override { solution.setStrategy(GetParam()); }

    CountCoveredBuildingsSolution solution;
};

TEST_P(CountCoveredBuildingsTest, Example1) {
    int n = 3;
    std::vector<std::vector<int>> buildings = {{1, 2}, {2, 2}, {3, 2},
                                               {2, 1}, {2, 3}};
    EXPECT_EQ(solution.countCoveredBuildings(n, buildings), 1);
}

TEST_P(CountCoveredBuildingsTest, Example2) {
    int n = 3;
    std::vector<std::vector<int>> buildings = {{1, 1}, {1, 2}, {2, 1},
                                               {2, 2}};
    EXPECT_EQ(solution.countCoveredBuildings(n, buildings), 0);
}

TEST_P(CountCoveredBuildingsTest, Example3) {
    int n = 5;
    std::vector<std::vector<int>> buildings = {{1, 3}, {3, 2}, {3, 3},
                                               {3, 5}, {5, 3}};
    EXPECT_EQ(solution.countCoveredBuildings(n, buildings), 1);
}

// Cross-shaped: three buildings on row 2 (cols 1..3) and three buildings on
// col 2 (rows 1..3). Only [2,2] is covered.
TEST_P(CountCoveredBuildingsTest, SelfAuthoredCrossShape) {
    int n = 3;
    std::vector<std::vector<int>> buildings = {{1, 2}, {2, 1}, {2, 2},
                                               {2, 3}, {3, 2}};
    EXPECT_EQ(solution.countCoveredBuildings(n, buildings), 1);
}

// Two buildings only: neither can possibly be covered.
TEST_P(CountCoveredBuildingsTest, SelfAuthoredOnlyTwoBuildings) {
    int n = 4;
    std::vector<std::vector<int>> buildings = {{1, 1}, {4, 4}};
    EXPECT_EQ(solution.countCoveredBuildings(n, buildings), 0);
}

// Full row and full column: only [2,2] is covered.
TEST_P(CountCoveredBuildingsTest, SelfAuthoredRowAndColumn) {
    int n = 3;
    std::vector<std::vector<int>> buildings = {{2, 1}, {2, 2}, {2, 3},
                                               {1, 2}, {3, 2}};
    EXPECT_EQ(solution.countCoveredBuildings(n, buildings), 1);
}

INSTANTIATE_TEST_SUITE_P(
    CountCoveredBuildingsSuite, CountCoveredBuildingsTest,
    ::testing::ValuesIn(CountCoveredBuildingsSolution().getStrategyNames()));

}  // namespace leetcode::problem_3531
