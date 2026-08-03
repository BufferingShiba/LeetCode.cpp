#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-enemy-forts-that-can-be-captured.h"

namespace leetcode {
namespace problem_2511 {

class MaximumEnemyFortsThatCanBeCapturedTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumEnemyFortsThatCanBeCapturedSolution solution;
};

TEST_P(MaximumEnemyFortsThatCanBeCapturedTest, Example1) {
  std::vector<int> forts = {1, 0, 0, -1, 0, 0, 0, 0, 1};
  EXPECT_EQ(4, solution.captureForts(forts));
}

TEST_P(MaximumEnemyFortsThatCanBeCapturedTest, Example2) {
  std::vector<int> forts = {0, 0, 1, -1};
  EXPECT_EQ(0, solution.captureForts(forts));
}

TEST_P(MaximumEnemyFortsThatCanBeCapturedTest, SelfAuthoredSingleFort) {
  std::vector<int> forts = {1};
  EXPECT_EQ(0, solution.captureForts(forts));
}

INSTANTIATE_TEST_SUITE_P(
    MaximumEnemyFortsThatCanBeCapturedTestSuites,
    MaximumEnemyFortsThatCanBeCapturedTest,
    ::testing::ValuesIn(
        MaximumEnemyFortsThatCanBeCapturedSolution().getStrategyNames()));

}  // namespace problem_2511
}  // namespace leetcode
