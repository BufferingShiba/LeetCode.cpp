#include <gtest/gtest.h>

#include "leetcode/problems/calculate-digit-sum-of-a-string.h"

namespace leetcode {
namespace problem_2243 {

class CalculateDigitSumOfAStringTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  CalculateDigitSumOfAStringSolution solution_;
};

TEST_P(CalculateDigitSumOfAStringTest, OfficialExample1) {
  EXPECT_EQ(solution_.digitSum("11111222223", 3), "135");
}

TEST_P(CalculateDigitSumOfAStringTest, OfficialExample2) {
  EXPECT_EQ(solution_.digitSum("00000000", 3), "000");
}

TEST_P(CalculateDigitSumOfAStringTest, SelfAuthoredAlreadyShortEnough) {
  // s.length() <= k，直接返回原串
  EXPECT_EQ(solution_.digitSum("12", 3), "12");
}

TEST_P(CalculateDigitSumOfAStringTest, SelfAuthoredSingleDigit) {
  EXPECT_EQ(solution_.digitSum("5", 2), "5");
}

TEST_P(CalculateDigitSumOfAStringTest, SelfAuthoredExactGroupEnd) {
  // 每组恰好 k 个，求和后需要继续
  EXPECT_EQ(solution_.digitSum("1111", 2), "22");
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    CalculateDigitSumOfAStringTest,
    testing::ValuesIn(CalculateDigitSumOfAStringSolution().getStrategyNames()));

}  // namespace problem_2243
}  // namespace leetcode
