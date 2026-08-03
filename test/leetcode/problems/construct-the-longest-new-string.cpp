#include <gtest/gtest.h>

#include "leetcode/problems/construct-the-longest-new-string.h"

namespace leetcode {
namespace problem_2745 {

class ConstructTheLongestNewStringTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ConstructTheLongestNewStringSolution solution_;
};

TEST_P(ConstructTheLongestNewStringTest, OfficialExample1) {
  EXPECT_EQ(solution_.longestString(2, 5, 1), 12);
}

TEST_P(ConstructTheLongestNewStringTest, OfficialExample2) {
  EXPECT_EQ(solution_.longestString(3, 2, 2), 14);
}

TEST_P(ConstructTheLongestNewStringTest, SelfAuthoredEqualXY) {
  // x=3, y=3, z=0: AA BB AA BB AA BB, len=12
  EXPECT_EQ(solution_.longestString(3, 3, 0), 12);
}

TEST_P(ConstructTheLongestNewStringTest, SelfAuthoredOnlyAB) {
  // x=0? But constraints x>=1, so use x=1,y=1,z=5
  // 2*(5 + 2*1 + 0) = 14
  EXPECT_EQ(solution_.longestString(1, 1, 5), 14);
}

TEST_P(ConstructTheLongestNewStringTest, SelfAuthoredLargeDiff) {
  // x=10, y=1, z=2 -> mn=1, extra=1, total=2*(2+2+1)=10
  EXPECT_EQ(solution_.longestString(10, 1, 2), 10);
}

TEST_P(ConstructTheLongestNewStringTest, SelfAuthoredSingleAB) {
  // x=1, y=2, z=1 -> mn=1, extra=1, total=2*(1+2+1)=8
  EXPECT_EQ(solution_.longestString(1, 2, 1), 8);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    ConstructTheLongestNewStringTest,
    testing::ValuesIn(
        ConstructTheLongestNewStringSolution().getStrategyNames()));

}  // namespace problem_2745
}  // namespace leetcode
