#include <gtest/gtest.h>

#include "leetcode/problems/number-of-good-ways-to-split-a-string.h"

namespace leetcode::problem_1525 {

class NumberOfGoodWaysToSplitAStringTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  NumberOfGoodWaysToSplitAStringSolution solution_;
};

TEST_P(NumberOfGoodWaysToSplitAStringTest, OfficialExamples) {
  EXPECT_EQ(solution_.numSplits("aacaba"), 2);
  EXPECT_EQ(solution_.numSplits("abcd"), 1);
}

TEST_P(NumberOfGoodWaysToSplitAStringTest, SelfAuthored) {
  // 单字符无法分割
  EXPECT_EQ(solution_.numSplits("a"), 0);

  // 两个相同字符：只有一个分割点，左右各1个distinct
  EXPECT_EQ(solution_.numSplits("aa"), 1);

  // 两个不同字符：左右各1个distinct
  EXPECT_EQ(solution_.numSplits("ab"), 1);

  // 所有字符相同：每个分割点左1右1，全部good
  EXPECT_EQ(solution_.numSplits("aaaa"), 3);

  // 所有字符不同：只有一个点使左右distinct相等？
  // "abcde": 分割"ab"|"cde" → 左2右3；"abc"|"de" → 左3右2；没有相等
  EXPECT_EQ(solution_.numSplits("abcde"), 0);
}

INSTANTIATE_TEST_SUITE_P(Strategies,
                         NumberOfGoodWaysToSplitAStringTest,
                         testing::ValuesIn(
                             NumberOfGoodWaysToSplitAStringSolution()
                                 .getStrategyNames()));

}  // namespace leetcode::problem_1525
