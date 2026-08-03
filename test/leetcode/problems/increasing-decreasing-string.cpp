#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/increasing-decreasing-string.h"

namespace leetcode::problem_1370 {

class IncreasingDecreasingStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  IncreasingDecreasingStringSolution solution_;
};

TEST_P(IncreasingDecreasingStringTest, Example1) {
  EXPECT_EQ(solution_.sortString("aaaabbbbcccc"), "abccbaabccba");
}

TEST_P(IncreasingDecreasingStringTest, Example2) {
  EXPECT_EQ(solution_.sortString("rat"), "art");
}

TEST_P(IncreasingDecreasingStringTest, SelfAuthoredSingleCharacter) {
  EXPECT_EQ(solution_.sortString("a"), "a");
}

TEST_P(IncreasingDecreasingStringTest, SelfAuthoredAllSame) {
  EXPECT_EQ(solution_.sortString("gggg"), "gggg");
}

TEST_P(IncreasingDecreasingStringTest, SelfAuthoredReverseOrderInput) {
  EXPECT_EQ(solution_.sortString("cba"), "abc");
}

INSTANTIATE_TEST_SUITE_P(
    IncreasingDecreasingStringTestSuite, IncreasingDecreasingStringTest,
    ::testing::ValuesIn(IncreasingDecreasingStringSolution().getStrategyNames()));

}  // namespace leetcode::problem_1370
