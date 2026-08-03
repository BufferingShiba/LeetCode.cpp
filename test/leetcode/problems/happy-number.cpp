#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/happy-number.h"

namespace leetcode {
namespace problem_202 {

class HappyNumberTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  HappyNumberSolution solution;
};

TEST_P(HappyNumberTest, Example1) {
  EXPECT_TRUE(solution.isHappy(19));
}

TEST_P(HappyNumberTest, Example2) {
  EXPECT_FALSE(solution.isHappy(2));
}

TEST_P(HappyNumberTest, SelfAuthoredOneIsHappy) {
  EXPECT_TRUE(solution.isHappy(1));
}

INSTANTIATE_TEST_SUITE_P(
    HappyNumberTestSuite, HappyNumberTest,
    ::testing::ValuesIn(HappyNumberSolution().getStrategyNames()));

}  // namespace problem_202
}  // namespace leetcode
