#include <gtest/gtest.h>

#include "leetcode/problems/count-beautiful-numbers.h"

using namespace leetcode::problem_3490;

class CountBeautifulNumbersTest : public testing::TestWithParam<std::string> {
 public:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  CountBeautifulNumbersSolution solution_;
};

TEST_P(CountBeautifulNumbersTest, Example1) {
  EXPECT_EQ(solution_.beautifulNumbers(10, 20), 2);
}

TEST_P(CountBeautifulNumbersTest, Example2) {
  EXPECT_EQ(solution_.beautifulNumbers(1, 15), 10);
}

TEST_P(CountBeautifulNumbersTest, SelfAuthoredSingleElementBeautiful) {
  EXPECT_EQ(solution_.beautifulNumbers(1, 1), 1);
}

TEST_P(CountBeautifulNumbersTest, SelfAuthoredSingleElementNotBeautiful) {
  EXPECT_EQ(solution_.beautifulNumbers(11, 11), 0);
}

TEST_P(CountBeautifulNumbersTest, SelfAuthoredLargeRange) {
  // Sanity: count should be monotonic
  int a = solution_.beautifulNumbers(1, 500000);
  int b = solution_.beautifulNumbers(1, 999999999);
  EXPECT_LE(a, b);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, CountBeautifulNumbersTest,
    testing::ValuesIn(CountBeautifulNumbersSolution().getStrategyNames()));
