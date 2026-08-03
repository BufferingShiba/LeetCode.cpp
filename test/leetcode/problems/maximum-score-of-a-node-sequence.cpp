#include <gtest/gtest.h>

#include "leetcode/problems/maximum-score-of-a-node-sequence.h"

namespace leetcode {
namespace problem_2242 {

class MaximumScoreOfANodeSequenceTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  MaximumScoreOfANodeSequenceSolution solution;
};

TEST_P(MaximumScoreOfANodeSequenceTest, OfficialExample1) {
  std::vector<int> scores = {5, 2, 9, 8, 4};
  std::vector<std::vector<int>> edges = {
      {0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
  EXPECT_EQ(solution.maximumScore(scores, edges), 24);
}

TEST_P(MaximumScoreOfANodeSequenceTest, OfficialExample2) {
  std::vector<int> scores = {9, 20, 6, 4, 11, 12};
  std::vector<std::vector<int>> edges = {{0, 3}, {5, 3}, {2, 4}, {1, 3}};
  EXPECT_EQ(solution.maximumScore(scores, edges), -1);
}

namespace {
const auto kStrategies =
    MaximumScoreOfANodeSequenceSolution().getStrategyNames();
}  // namespace

INSTANTIATE_TEST_SUITE_P(AllStrategies, MaximumScoreOfANodeSequenceTest,
                         testing::ValuesIn(kStrategies));

}  // namespace problem_2242
}  // namespace leetcode
