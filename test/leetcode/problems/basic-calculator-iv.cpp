#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/basic-calculator-iv.h"

namespace leetcode {
namespace problem_770 {
namespace {

class BasicCalculatorIvTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  BasicCalculatorIvSolution solution;
};

TEST_P(BasicCalculatorIvTest, Example1) {
  std::vector<std::string> evalvars = {"e"};
  std::vector<int> evalints = {1};
  EXPECT_EQ(solution.basicCalculatorIV("e + 8 - a + 5", evalvars, evalints),
            (std::vector<std::string>{"-1*a", "14"}));
}

TEST_P(BasicCalculatorIvTest, Example2) {
  std::vector<std::string> evalvars = {"e", "temperature"};
  std::vector<int> evalints = {1, 12};
  EXPECT_EQ(solution.basicCalculatorIV(
                "e - 8 + temperature - pressure", evalvars, evalints),
            (std::vector<std::string>{"-1*pressure", "5"}));
}

TEST_P(BasicCalculatorIvTest, Example3) {
  std::vector<std::string> evalvars;
  std::vector<int> evalints;
  EXPECT_EQ(solution.basicCalculatorIV("(e + 8) * (e - 8)", evalvars,
                                      evalints),
            (std::vector<std::string>{"1*e*e", "-64"}));
}

TEST_P(BasicCalculatorIvTest, MultiplicationAndZeroTerms) {
  std::vector<std::string> evalvars;
  std::vector<int> evalints;
  EXPECT_EQ(solution.basicCalculatorIV("1 + 2 * 3", evalvars, evalints),
            (std::vector<std::string>{"7"}));
  EXPECT_TRUE(solution.basicCalculatorIV("0", evalvars, evalints).empty());
}

INSTANTIATE_TEST_SUITE_P(
    BasicCalculatorIvStrategyTests, BasicCalculatorIvTest,
    ::testing::ValuesIn(BasicCalculatorIvSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_770
}  // namespace leetcode
