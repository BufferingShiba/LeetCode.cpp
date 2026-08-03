#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/verbal-arithmetic-puzzle.h"

namespace leetcode {
namespace problem_1307 {

class VerbalArithmeticPuzzleTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  VerbalArithmeticPuzzleSolution solution;
};

TEST_P(VerbalArithmeticPuzzleTest, Example1) {
  std::vector<std::string> words = {"SEND", "MORE"};
  std::string result = "MONEY";
  EXPECT_TRUE(solution.isSolvable(words, result));
}

TEST_P(VerbalArithmeticPuzzleTest, Example2) {
  std::vector<std::string> words = {"SIX", "SEVEN", "SEVEN"};
  std::string result = "TWENTY";
  EXPECT_TRUE(solution.isSolvable(words, result));
}

TEST_P(VerbalArithmeticPuzzleTest, Example3) {
  std::vector<std::string> words = {"LEET", "CODE"};
  std::string result = "POINT";
  EXPECT_FALSE(solution.isSolvable(words, result));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    VerbalArithmeticPuzzleTest,
    testing::ValuesIn(VerbalArithmeticPuzzleSolution().getStrategyNames()));

}  // namespace problem_1307
}  // namespace leetcode
