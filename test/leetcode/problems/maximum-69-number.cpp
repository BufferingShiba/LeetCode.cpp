#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-69-number.h"

namespace leetcode {
namespace problem_1323 {

class Maximum69NumberTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  Maximum69NumberSolution solution_;
};

TEST_P(Maximum69NumberTest, Example1) {
  EXPECT_EQ(9969, solution_.maximum69Number(9669));
}

TEST_P(Maximum69NumberTest, Example2) {
  EXPECT_EQ(9999, solution_.maximum69Number(9996));
}

TEST_P(Maximum69NumberTest, Example3) {
  EXPECT_EQ(9999, solution_.maximum69Number(9999));
}

TEST_P(Maximum69NumberTest, SelfAuthoredSingleDigitSix) {
  EXPECT_EQ(9, solution_.maximum69Number(6));
}

TEST_P(Maximum69NumberTest, SelfAuthoredSingleDigitNine) {
  EXPECT_EQ(9, solution_.maximum69Number(9));
}

INSTANTIATE_TEST_SUITE_P(
    Maximum69NumberTestSuite, Maximum69NumberTest,
    ::testing::ValuesIn(Maximum69NumberSolution().getStrategyNames()));

}  // namespace problem_1323
}  // namespace leetcode
