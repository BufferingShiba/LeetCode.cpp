#include <gtest/gtest.h>

#include "leetcode/problems/check-if-string-is-a-prefix-of-array.h"

namespace leetcode {
namespace problem_1961 {

class CheckIfStringIsAPrefixOfArrayTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }
  CheckIfStringIsAPrefixOfArraySolution solution_;
};

TEST_P(CheckIfStringIsAPrefixOfArrayTest, OfficialExamples) {
  // Example 1
  {
    std::string s = "iloveleetcode";
    std::vector<std::string> words = {"i", "love", "leetcode", "apples"};
    EXPECT_TRUE(solution_.isPrefixString(s, words));
  }

  // Example 2
  {
    std::string s = "iloveleetcode";
    std::vector<std::string> words = {"apples", "i", "love", "leetcode"};
    EXPECT_FALSE(solution_.isPrefixString(s, words));
  }
}

TEST_P(CheckIfStringIsAPrefixOfArrayTest, SelfAuthored) {
  // 单个 word 精确匹配
  {
    std::string s = "abc";
    std::vector<std::string> words = {"abc"};
    EXPECT_TRUE(solution_.isPrefixString(s, words));
  }

  // s 比第一个 word 短，不匹配
  {
    std::string s = "ab";
    std::vector<std::string> words = {"abc", "def"};
    EXPECT_FALSE(solution_.isPrefixString(s, words));
  }

  // words 耗尽时 s 尚未覆盖完
  {
    std::string s = "abcde";
    std::vector<std::string> words = {"ab", "cd"};
    EXPECT_FALSE(solution_.isPrefixString(s, words));
  }
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    CheckIfStringIsAPrefixOfArrayTest,
    testing::ValuesIn(
        CheckIfStringIsAPrefixOfArraySolution().getStrategyNames()));

}  // namespace problem_1961
}  // namespace leetcode
