#include <gtest/gtest.h>

#include "leetcode/problems/expressive-words.h"

using namespace leetcode::problem_809;

class ExpressiveWordsTest : public ::testing::TestWithParam<std::string> {
 protected:
  ExpressiveWordsSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(ExpressiveWordsTest, Example1) {
  std::string s = "heeellooo";
  std::vector<std::string> words = {"hello", "hi", "helo"};
  EXPECT_EQ(solution.expressiveWords(s, words), 1);
}

TEST_P(ExpressiveWordsTest, Example2) {
  std::string s = "zzzzzyyyyy";
  std::vector<std::string> words = {"zzyy", "zy", "zyy"};
  EXPECT_EQ(solution.expressiveWords(s, words), 3);
}

INSTANTIATE_TEST_SUITE_P(AllStrategies, ExpressiveWordsTest,
                         ::testing::ValuesIn(
                             ExpressiveWordsSolution().getStrategyNames()));
