#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/remove-digit-from-number-to-maximize-result.h"

namespace leetcode {
namespace problem_2259 {

class RemoveDigitFromNumberToMaximizeResultTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  RemoveDigitFromNumberToMaximizeResultSolution solution_;
};

TEST_P(RemoveDigitFromNumberToMaximizeResultTest, OfficialExample1) {
  EXPECT_EQ(solution_.removeDigit("123", '3'), "12");
}

TEST_P(RemoveDigitFromNumberToMaximizeResultTest, OfficialExample2) {
  EXPECT_EQ(solution_.removeDigit("1231", '1'), "231");
}

TEST_P(RemoveDigitFromNumberToMaximizeResultTest, OfficialExample3) {
  EXPECT_EQ(solution_.removeDigit("551", '5'), "51");
}

TEST_P(RemoveDigitFromNumberToMaximizeResultTest, SelfAuthored_DigitAtEnd) {
  // digit 在末尾，且没有后一位更大的情况 → 移除最后一个
  EXPECT_EQ(solution_.removeDigit("43215", '5'), "4321");
}

TEST_P(RemoveDigitFromNumberToMaximizeResultTest, SelfAuthored_MultipleSameDigit) {
  // 多个相同 digit，贪心应选第一个满足后一位更大的位置
  EXPECT_EQ(solution_.removeDigit("12121", '1'), "2121");
}

TEST_P(RemoveDigitFromNumberToMaximizeResultTest, SelfAuthored_AllSameDigit) {
  // 全部相同 digit，移除最后一个
  EXPECT_EQ(solution_.removeDigit("111", '1'), "11");
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    RemoveDigitFromNumberToMaximizeResultTest,
    ::testing::ValuesIn(
        RemoveDigitFromNumberToMaximizeResultSolution().getStrategyNames()));

}  // namespace problem_2259
}  // namespace leetcode
