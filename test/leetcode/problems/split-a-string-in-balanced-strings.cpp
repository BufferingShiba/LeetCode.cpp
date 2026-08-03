#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/split-a-string-in-balanced-strings.h"

namespace leetcode::problem_1221 {

class SplitAStringInBalancedStringsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_ = std::make_unique<SplitAStringInBalancedStringsSolution>();
    solution_->setStrategy(GetParam());
  }

  std::unique_ptr<SplitAStringInBalancedStringsSolution> solution_;
};

TEST_P(SplitAStringInBalancedStringsTest, Example1) {
  EXPECT_EQ(solution_->balancedStringSplit("RLRRLLRLRL"), 4);
}

TEST_P(SplitAStringInBalancedStringsTest, Example2) {
  EXPECT_EQ(solution_->balancedStringSplit("RLRRRLLRLL"), 2);
}

TEST_P(SplitAStringInBalancedStringsTest, Example3) {
  EXPECT_EQ(solution_->balancedStringSplit("LLLLRRRR"), 1);
}

TEST_P(SplitAStringInBalancedStringsTest, SelfAuthoredBasic) {
  EXPECT_EQ(solution_->balancedStringSplit("RL"), 1);
}

TEST_P(SplitAStringInBalancedStringsTest, SelfAuthoredRepeatedRL) {
  EXPECT_EQ(solution_->balancedStringSplit("RLRLRLRL"), 4);
}

INSTANTIATE_TEST_SUITE_P(
    SplitAStringInBalancedStringsTestSuite,
    SplitAStringInBalancedStringsTest,
    ::testing::ValuesIn(
        SplitAStringInBalancedStringsSolution().getStrategyNames()));

}  // namespace leetcode::problem_1221
