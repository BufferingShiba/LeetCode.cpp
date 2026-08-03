#include <gtest/gtest.h>
#include "leetcode/problems/last-stone-weight.h"

namespace leetcode {
namespace problem_1046 {

class LastStoneWeightTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  LastStoneWeightSolution solution;
};

TEST_P(LastStoneWeightTest, Example1) {
  std::vector<int> stones = {2, 7, 4, 1, 8, 1};
  EXPECT_EQ(solution.lastStoneWeight(stones), 1);
}

TEST_P(LastStoneWeightTest, Example2) {
  std::vector<int> stones = {1};
  EXPECT_EQ(solution.lastStoneWeight(stones), 1);
}

TEST_P(LastStoneWeightTest, SelfAuthoredAllSameStones) {
  std::vector<int> stones = {5, 5, 5, 5};
  EXPECT_EQ(solution.lastStoneWeight(stones), 0);
}

TEST_P(LastStoneWeightTest, SelfAuthoredTwoDifferentStones) {
  std::vector<int> stones = {3, 7};
  EXPECT_EQ(solution.lastStoneWeight(stones), 4);
}

INSTANTIATE_TEST_SUITE_P(AllStrategies, LastStoneWeightTest,
                         ::testing::ValuesIn(LastStoneWeightSolution()
                                                 .getStrategyNames()));

}  // namespace problem_1046
}  // namespace leetcode
