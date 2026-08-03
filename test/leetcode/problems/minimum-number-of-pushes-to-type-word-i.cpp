#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-number-of-pushes-to-type-word-i.h"

namespace leetcode {
namespace problem_3014 {

class MinimumNumberOfPushesToTypeWordITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumNumberOfPushesToTypeWordISolution solution_;
};

TEST_P(MinimumNumberOfPushesToTypeWordITest, Example1) {
  EXPECT_EQ(solution_.minimumPushes("abcde"), 5);
}

TEST_P(MinimumNumberOfPushesToTypeWordITest, Example2) {
  EXPECT_EQ(solution_.minimumPushes("xycdefghij"), 12);
}

TEST_P(MinimumNumberOfPushesToTypeWordITest, SelfAuthoredSingleChar) {
  EXPECT_EQ(solution_.minimumPushes("a"), 1);
}

TEST_P(MinimumNumberOfPushesToTypeWordITest, SelfAuthoredEightChars) {
  EXPECT_EQ(solution_.minimumPushes("abcdefgh"), 8);
}

TEST_P(MinimumNumberOfPushesToTypeWordITest, SelfAuthoredNineChars) {
  EXPECT_EQ(solution_.minimumPushes("abcdefghi"), 10);
}

TEST_P(MinimumNumberOfPushesToTypeWordITest, SelfAuthoredMaxTwentySix) {
  EXPECT_EQ(solution_.minimumPushes("abcdefghijklmnopqrstuvwxyz"), 8 + 16 + 24 + 8);
}

INSTANTIATE_TEST_SUITE_P(
    MinimumNumberOfPushesToTypeWordITests,
    MinimumNumberOfPushesToTypeWordITest,
    ::testing::ValuesIn(
        MinimumNumberOfPushesToTypeWordISolution().getStrategyNames()));

}  // namespace problem_3014
}  // namespace leetcode
