#include <gtest/gtest.h>

#include "leetcode/problems/print-words-vertically.h"

using namespace leetcode::problem_1324;

class PrintWordsVerticallyTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  PrintWordsVerticallySolution solution;
};

TEST_P(PrintWordsVerticallyTest, Example1) {
  auto result = solution.printVertically("HOW ARE YOU");
  std::vector<std::string> expected = {"HAY", "ORO", "WEU"};
  EXPECT_EQ(result, expected);
}

TEST_P(PrintWordsVerticallyTest, Example2) {
  auto result = solution.printVertically("TO BE OR NOT TO BE");
  std::vector<std::string> expected = {"TBONTB", "OEROOE", "   T"};
  EXPECT_EQ(result, expected);
}

TEST_P(PrintWordsVerticallyTest, Example3) {
  auto result = solution.printVertically("CONTEST IS COMING");
  std::vector<std::string> expected = {"CIC", "OSO", "N M", "T I",
                                        "E N", "S G", "T"};
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    PrintWordsVerticallyTest,
    testing::ValuesIn(PrintWordsVerticallySolution().getStrategyNames()));
