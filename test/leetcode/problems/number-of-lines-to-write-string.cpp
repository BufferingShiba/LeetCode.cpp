#include <gtest/gtest.h>

#include "leetcode/problems/number-of-lines-to-write-string.h"

namespace leetcode::problem_806 {

class NumberOfLinesToWriteStringTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfLinesToWriteStringSolution solution;
};

TEST_P(NumberOfLinesToWriteStringTest, Example1) {
  std::vector<int> widths(26, 10);
  std::string s = "abcdefghijklmnopqrstuvwxyz";
  auto result = solution.numberOfLines(widths, s);
  EXPECT_EQ(result, (std::vector<int>{3, 60}));
}

TEST_P(NumberOfLinesToWriteStringTest, Example2) {
  std::vector<int> widths = {4, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                             10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                             10, 10, 10, 10, 10, 10};
  std::string s = "bbbcccdddaaa";
  auto result = solution.numberOfLines(widths, s);
  EXPECT_EQ(result, (std::vector<int>{2, 4}));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    NumberOfLinesToWriteStringTest,
    testing::ValuesIn(
        NumberOfLinesToWriteStringSolution().getStrategyNames()));

}  // namespace leetcode::problem_806
