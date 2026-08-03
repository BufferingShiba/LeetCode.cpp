#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/check-if-numbers-are-ascending-in-a-sentence.h"

namespace leetcode {
namespace problem_2042 {

class CheckIfNumbersAreAscendingInASentenceTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  CheckIfNumbersAreAscendingInASentenceSolution solution;
};

TEST_P(CheckIfNumbersAreAscendingInASentenceTest, Example1) {
  EXPECT_TRUE(solution.areNumbersAscending(
      "1 box has 3 blue 4 red 6 green and 12 yellow marbles"));
}

TEST_P(CheckIfNumbersAreAscendingInASentenceTest, Example2) {
  EXPECT_FALSE(solution.areNumbersAscending("hello world 5 x 5"));
}

TEST_P(CheckIfNumbersAreAscendingInASentenceTest, Example3) {
  EXPECT_FALSE(solution.areNumbersAscending(
      "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s"));
}

TEST_P(CheckIfNumbersAreAscendingInASentenceTest, SelfAuthoredSingleNumberSequence) {
  EXPECT_TRUE(solution.areNumbersAscending("a 1 b 2 c 3"));
}

TEST_P(CheckIfNumbersAreAscendingInASentenceTest, SelfAuthoredSmallerAfterLarger) {
  EXPECT_FALSE(solution.areNumbersAscending("x 10 y 9"));
}

TEST_P(CheckIfNumbersAreAscendingInASentenceTest, SelfAuthoredWordThenNumber) {
  EXPECT_TRUE(solution.areNumbersAscending("word 5 next 7 end"));
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfNumbersAreAscendingInASentenceTestSuite,
    CheckIfNumbersAreAscendingInASentenceTest,
    ::testing::ValuesIn(
        CheckIfNumbersAreAscendingInASentenceSolution().getStrategyNames()));

}  // namespace problem_2042
}  // namespace leetcode
