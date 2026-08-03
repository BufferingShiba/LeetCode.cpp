#include <gtest/gtest.h>
#include "leetcode/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii.h"

namespace leetcode {
namespace problem_3756 {

class ConcatenateNonZeroDigitsAndMultiplyBySumIiTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  ConcatenateNonZeroDigitsAndMultiplyBySumIiSolution solution_;
};

TEST_P(ConcatenateNonZeroDigitsAndMultiplyBySumIiTest, Example1) {
  std::string s = "10203004";
  std::vector<std::vector<int>> queries = {{0, 7}, {1, 3}, {4, 6}};
  std::vector<int> expected = {12340, 4, 9};
  EXPECT_EQ(solution_.sumAndMultiply(s, queries), expected);
}

TEST_P(ConcatenateNonZeroDigitsAndMultiplyBySumIiTest, Example2) {
  std::string s = "1000";
  std::vector<std::vector<int>> queries = {{0, 3}, {1, 1}};
  std::vector<int> expected = {1, 0};
  EXPECT_EQ(solution_.sumAndMultiply(s, queries), expected);
}

TEST_P(ConcatenateNonZeroDigitsAndMultiplyBySumIiTest, Example3) {
  std::string s = "9876543210";
  std::vector<std::vector<int>> queries = {{0, 9}};
  std::vector<int> expected = {444444137};
  EXPECT_EQ(solution_.sumAndMultiply(s, queries), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, ConcatenateNonZeroDigitsAndMultiplyBySumIiTest,
    ::testing::ValuesIn(
        ConcatenateNonZeroDigitsAndMultiplyBySumIiSolution().getStrategyNames()));

}  // namespace problem_3756
}  // namespace leetcode
