#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

#include "leetcode/problems/expression-add-operators.h"

namespace leetcode {
namespace problem_282 {

class ExpressionAddOperatorsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ExpressionAddOperatorsSolution solution_;
};

TEST_P(ExpressionAddOperatorsTest, Example1) {
  auto result = solution_.addOperators("123", 6);
  std::vector<std::string> expected = {"1*2*3", "1+2+3"};
  std::sort(result.begin(), result.end());
  std::sort(expected.begin(), expected.end());
  EXPECT_EQ(result, expected);
}

TEST_P(ExpressionAddOperatorsTest, Example2) {
  auto result = solution_.addOperators("232", 8);
  std::vector<std::string> expected = {"2*3+2", "2+3*2"};
  std::sort(result.begin(), result.end());
  std::sort(expected.begin(), expected.end());
  EXPECT_EQ(result, expected);
}

TEST_P(ExpressionAddOperatorsTest, Example3) {
  auto result = solution_.addOperators("3456237490", 9191);
  std::vector<std::string> expected = {};
  EXPECT_EQ(result, expected);
}

TEST_P(ExpressionAddOperatorsTest, SelfAuthoredSingleDigit) {
  auto result = solution_.addOperators("5", 5);
  std::vector<std::string> expected = {"5"};
  EXPECT_EQ(result, expected);
}

TEST_P(ExpressionAddOperatorsTest, SelfAuthoredLeadingZero) {
  auto result = solution_.addOperators("105", 5);
  // "10-5" = 5, "1*0+5" = 5
  std::vector<std::string> expected = {"10-5", "1*0+5"};
  std::sort(result.begin(), result.end());
  std::sort(expected.begin(), expected.end());
  EXPECT_EQ(result, expected);
}

TEST_P(ExpressionAddOperatorsTest, SelfAuthoredZeroOnly) {
  auto result = solution_.addOperators("0", 0);
  std::vector<std::string> expected = {"0"};
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    ExpressionAddOperatorsTest,
    ::testing::ValuesIn(ExpressionAddOperatorsSolution().getStrategyNames()));

}  // namespace problem_282
}  // namespace leetcode
