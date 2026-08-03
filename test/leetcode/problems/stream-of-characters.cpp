#include <gtest/gtest.h>

#include "leetcode/problems/stream-of-characters.h"

namespace leetcode {
namespace problem_1032 {

class StreamOfCharactersTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {}
  void TearDown() override {}
};

// 官方 Example 1
TEST_P(StreamOfCharactersTest, Example1) {
  std::vector<std::string> words = {"cd", "f", "kl"};
  StreamChecker checker(words);
  EXPECT_FALSE(checker.query('a'));
  EXPECT_FALSE(checker.query('b'));
  EXPECT_FALSE(checker.query('c'));
  EXPECT_TRUE(checker.query('d'));   // 后缀 "cd" 在 words 中
  EXPECT_FALSE(checker.query('e'));
  EXPECT_TRUE(checker.query('f'));   // 后缀 "f" 在 words 中
  EXPECT_FALSE(checker.query('g'));
  EXPECT_FALSE(checker.query('h'));
  EXPECT_FALSE(checker.query('i'));
  EXPECT_FALSE(checker.query('j'));
  EXPECT_FALSE(checker.query('k'));
  EXPECT_TRUE(checker.query('l'));   // 后缀 "kl" 在 words 中
}

// 自建：单字符单词
TEST_P(StreamOfCharactersTest, SelfAuthoredSingleCharacterWord) {
  std::vector<std::string> words = {"a"};
  StreamChecker checker(words);
  EXPECT_TRUE(checker.query('a'));
}

// 自建：跨越多个字符的后缀匹配（题目描述示例）
TEST_P(StreamOfCharactersTest, SelfAuthoredSuffixMatchAcrossMultipleChars) {
  std::vector<std::string> words = {"abc", "xyz"};
  StreamChecker checker(words);
  EXPECT_FALSE(checker.query('a'));
  EXPECT_FALSE(checker.query('x'));
  EXPECT_FALSE(checker.query('y'));
  EXPECT_TRUE(checker.query('z'));
}

// 自建：较长字符流中的尾部后缀匹配
TEST_P(StreamOfCharactersTest, SelfAuthoredLongerStreamMatch) {
  std::vector<std::string> words = {"cd"};
  StreamChecker checker(words);
  EXPECT_FALSE(checker.query('a'));
  EXPECT_FALSE(checker.query('c'));
  EXPECT_TRUE(checker.query('d'));
  // 此时流为 "acd"，后缀仍是 "cd"
  EXPECT_FALSE(checker.query('x')); // 流 "acdx"，最近后缀无匹配
}

INSTANTIATE_TEST_SUITE_P(StreamOfCharactersSuit, StreamOfCharactersTest,
                         ::testing::Values("StreamChecker"));

}  // namespace problem_1032
}  // namespace leetcode
