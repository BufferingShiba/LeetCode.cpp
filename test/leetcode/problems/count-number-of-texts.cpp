#include <gtest/gtest.h>

#include "leetcode/problems/count-number-of-texts.h"

using namespace leetcode::problem_2266;

class CountNumberOfTextsTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  CountNumberOfTextsSolution solution;
};

TEST_P(CountNumberOfTextsTest, Example1) {
  EXPECT_EQ(solution.countTexts("22233"), 8);
}

TEST_P(CountNumberOfTextsTest, Example2) {
  EXPECT_EQ(solution.countTexts(
                "222222222222222222222222222222222222"),
            82876089);
}

INSTANTIATE_TEST_SUITE_P(AllStrategies,
                         CountNumberOfTextsTest,
                         testing::ValuesIn(CountNumberOfTextsSolution()
                                               .getStrategyNames()));
