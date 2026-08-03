#include <gtest/gtest.h>
#include "leetcode/problems/count-substrings-starting-and-ending-with-given-character.h"

using namespace leetcode::problem_3084;

class CountSubstringsStartingAndEndingWithGivenCharacterTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }
  CountSubstringsStartingAndEndingWithGivenCharacterSolution solution;
};

TEST_P(CountSubstringsStartingAndEndingWithGivenCharacterTest, OfficialExample1) {
  EXPECT_EQ(solution.countSubstrings("abada", 'a'), 6);
}

TEST_P(CountSubstringsStartingAndEndingWithGivenCharacterTest, OfficialExample2) {
  EXPECT_EQ(solution.countSubstrings("zzz", 'z'), 6);
}

TEST_P(CountSubstringsStartingAndEndingWithGivenCharacterTest, SelfAuthoredSingleChar) {
  EXPECT_EQ(solution.countSubstrings("a", 'a'), 1);
}

TEST_P(CountSubstringsStartingAndEndingWithGivenCharacterTest, SelfAuthoredNoMatch) {
  EXPECT_EQ(solution.countSubstrings("abc", 'z'), 0);
}

TEST_P(CountSubstringsStartingAndEndingWithGivenCharacterTest, SelfAuthoredAllMatch) {
  EXPECT_EQ(solution.countSubstrings("aaaa", 'a'), 10);
}

INSTANTIATE_TEST_SUITE_P(
  Strategies,
  CountSubstringsStartingAndEndingWithGivenCharacterTest,
  testing::ValuesIn(CountSubstringsStartingAndEndingWithGivenCharacterSolution().getStrategyNames())
);
