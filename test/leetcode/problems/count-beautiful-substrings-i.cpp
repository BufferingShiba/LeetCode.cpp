#include <gtest/gtest.h>

#include "leetcode/problems/count-beautiful-substrings-i.h"

using namespace leetcode::problem_2947;

class CountBeautifulSubstringsITest : public ::testing::TestWithParam<std::string> {
 protected:
  CountBeautifulSubstringsISolution solution;

  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(CountBeautifulSubstringsITest, Example1) {
  EXPECT_EQ(solution.beautifulSubstrings("baeyh", 2), 2);
}

TEST_P(CountBeautifulSubstringsITest, Example2) {
  EXPECT_EQ(solution.beautifulSubstrings("abba", 1), 3);
}

TEST_P(CountBeautifulSubstringsITest, Example3) {
  EXPECT_EQ(solution.beautifulSubstrings("bcdf", 1), 0);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CountBeautifulSubstringsITest,
    ::testing::ValuesIn(CountBeautifulSubstringsISolution().getStrategyNames()));
