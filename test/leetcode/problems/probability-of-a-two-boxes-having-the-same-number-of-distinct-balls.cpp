#include <gtest/gtest.h>

#include "leetcode/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls.h"

namespace leetcode {
namespace problem_1467 {

class ProbabilityOfATwoBoxesHavingTheSameNumberOfDistinctBallsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  ProbabilityOfATwoBoxesHavingTheSameNumberOfDistinctBallsSolution solution;
};

TEST_P(ProbabilityOfATwoBoxesHavingTheSameNumberOfDistinctBallsTest, Example1) {
  std::vector<int> balls = {1, 1};
  double expected = 1.0;
  double result = solution.getProbability(balls);
  EXPECT_NEAR(result, expected, 1e-5);
}

TEST_P(ProbabilityOfATwoBoxesHavingTheSameNumberOfDistinctBallsTest, Example2) {
  std::vector<int> balls = {2, 1, 1};
  double expected = 2.0 / 3.0;
  double result = solution.getProbability(balls);
  EXPECT_NEAR(result, expected, 1e-5);
}

TEST_P(ProbabilityOfATwoBoxesHavingTheSameNumberOfDistinctBallsTest, Example3) {
  std::vector<int> balls = {1, 2, 1, 2};
  double expected = 0.6;
  double result = solution.getProbability(balls);
  EXPECT_NEAR(result, expected, 1e-5);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    ProbabilityOfATwoBoxesHavingTheSameNumberOfDistinctBallsTest,
    testing::ValuesIn(ProbabilityOfATwoBoxesHavingTheSameNumberOfDistinctBallsSolution()
                          .getStrategyNames()));

}  // namespace problem_1467
}  // namespace leetcode
