#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "leetcode/problems/split-message-based-on-limit.h"

namespace leetcode {
namespace problem_2468 {
namespace {

class SplitMessageBasedOnLimitTest : public ::testing::TestWithParam<std::string> {
 protected:
  SplitMessageBasedOnLimitSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(SplitMessageBasedOnLimitTest, Example1) {
  auto res = solution.getSolution()("this is really a very awesome message", 9);
  std::vector<std::string> expected = {
      "thi<1/14>", "s i<2/14>", "s r<3/14>", "eal<4/14>", "ly <5/14>",
      "a v<6/14>", "ery<7/14>", " aw<8/14>", "eso<9/14>", "me<10/14>",
      " m<11/14>", "es<12/14>", "sa<13/14>", "ge<14/14>"};
  EXPECT_EQ(res, expected);
}

TEST_P(SplitMessageBasedOnLimitTest, Example2) {
  auto res = solution.getSolution()("short message", 15);
  std::vector<std::string> expected = {"short mess<1/2>", "age<2/2>"};
  EXPECT_EQ(res, expected);
}

TEST_P(SplitMessageBasedOnLimitTest, ThreeSingleCharsWithTinyLimit) {
  // message="abc", limit=6; b=1 content=1<n, b=2 content sum=2<n, b=3 content=3>=n.
  auto res = solution.getSolution()("abc", 6);
  std::vector<std::string> expected = {"a<1/3>", "b<2/3>", "c<3/3>"};
  EXPECT_EQ(res, expected);
}

TEST_P(SplitMessageBasedOnLimitTest, ImpossibleTinyLimit) {
  // limit=3 too small for any suffix "<a/b>".
  EXPECT_TRUE(solution.getSolution()("ab", 3).empty());
  EXPECT_TRUE(solution.getSolution()("hello", 3).empty());
}

TEST_P(SplitMessageBasedOnLimitTest, SinglePartFits) {
  auto res = solution.getSolution()("xy", 7);
  // limit-5 = 2 >= n=2 -> single part "xy<1/1>".
  std::vector<std::string> expected = {"xy<1/1>"};
  EXPECT_EQ(res, expected);
}

INSTANTIATE_TEST_SUITE_P(
    SplitMessageBasedOnLimitTestCases, SplitMessageBasedOnLimitTest,
    ::testing::ValuesIn(SplitMessageBasedOnLimitSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2468
}  // namespace leetcode
