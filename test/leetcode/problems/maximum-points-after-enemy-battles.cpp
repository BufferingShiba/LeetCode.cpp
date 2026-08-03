#include <gtest/gtest.h>

#include "leetcode/problems/maximum-points-after-enemy-battles.h"

namespace leetcode {
namespace problem_3207 {

class MaximumPointsAfterEnemyBattlesTest
    : public ::testing::TestWithParam<std::string> {
protected:
    void SetUp() override { solution.setStrategy(GetParam()); }

    MaximumPointsAfterEnemyBattlesSolution solution;
};

TEST_P(MaximumPointsAfterEnemyBattlesTest, Example1) {
    std::vector<int> enemyEnergies = {3, 2, 2};
    EXPECT_EQ(3, solution.maximumPoints(enemyEnergies, 2));
}

TEST_P(MaximumPointsAfterEnemyBattlesTest, Example2) {
    std::vector<int> enemyEnergies = {2};
    EXPECT_EQ(5, solution.maximumPoints(enemyEnergies, 10));
}

TEST_P(MaximumPointsAfterEnemyBattlesTest, SelfAuthoredCannotStart) {
    std::vector<int> enemyEnergies = {5, 7, 10};
    EXPECT_EQ(0, solution.maximumPoints(enemyEnergies, 3));
}

TEST_P(MaximumPointsAfterEnemyBattlesTest, SelfAuthoredSingleEnemyExactlyEnough) {
    std::vector<int> enemyEnergies = {2};
    EXPECT_EQ(1, solution.maximumPoints(enemyEnergies, 2));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumPointsAfterEnemyBattlesTestSuite,
    MaximumPointsAfterEnemyBattlesTest,
    ::testing::ValuesIn(MaximumPointsAfterEnemyBattlesSolution().getStrategyNames()));

}  // namespace problem_3207
}  // namespace leetcode
