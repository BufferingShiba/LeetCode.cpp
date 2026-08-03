#include "leetcode/problems/decode-the-message.h"

#include <gtest/gtest.h>

#include <string>

namespace leetcode {
namespace problem_2325 {

using DecodeTheMessageTest = ::testing::TestWithParam<std::string>;

INSTANTIATE_TEST_SUITE_P(
    DecodeTheMessageSuite, DecodeTheMessageTest,
    ::testing::ValuesIn(DecodeTheMessageSolution().getStrategyNames()));

TEST_P(DecodeTheMessageTest, Example1) {
  DecodeTheMessageSolution solution;
  solution.setStrategy(GetParam());
  std::string key = "the quick brown fox jumps over the lazy dog";
  std::string message = "vkbs bs t suepuv";
  EXPECT_EQ("this is a secret", solution.decodeMessage(key, message));
}

TEST_P(DecodeTheMessageTest, Example2) {
  DecodeTheMessageSolution solution;
  solution.setStrategy(GetParam());
  std::string key = "eljuxhpwnyrdgtqkviszcfmabo";
  std::string message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb";
  EXPECT_EQ("the five boxing wizards jump quickly",
            solution.decodeMessage(key, message));
}

TEST_P(DecodeTheMessageTest, SelfAuthoredAllLettersInOrder) {
  DecodeTheMessageSolution solution;
  solution.setStrategy(GetParam());
  std::string key = "abcdefghijklmnopqrstuvwxyz";
  std::string message = "a b c d e f g h i j k l m n o p q r s t u v w x y z";
  EXPECT_EQ("a b c d e f g h i j k l m n o p q r s t u v w x y z",
            solution.decodeMessage(key, message));
}

}  // namespace problem_2325
}  // namespace leetcode
