#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "leetcode/problems/score-validator.h"

namespace leetcode {
namespace problem_3921 {

class ScoreValidatorTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ScoreValidatorSolution solution;
};

TEST_P(ScoreValidatorTest, Example1) {
  std::vector<std::string> events = {"1", "4", "W", "6", "WD"};
  std::vector<int> expected = {12, 1};
  EXPECT_EQ(solution.scoreValidator(events), expected);
}

TEST_P(ScoreValidatorTest, Example2) {
  std::vector<std::string> events = {"WD", "NB", "0", "4", "4"};
  std::vector<int> expected = {10, 0};
  EXPECT_EQ(solution.scoreValidator(events), expected);
}

TEST_P(ScoreValidatorTest, Example3) {
  std::vector<std::string> events = {"W", "W", "W", "W", "W", "W", "W", "W", "W", "W", "W"};
  std::vector<int> expected = {0, 10};
  EXPECT_EQ(solution.scoreValidator(events), expected);
}

INSTANTIATE_TEST_SUITE_P(
    ScoreValidatorTestSuite, ScoreValidatorTest,
    ::testing::ValuesIn(ScoreValidatorSolution().getStrategyNames()));

}  // namespace problem_3921
}  // namespace leetcode
