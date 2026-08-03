#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/find-longest-special-substring-that-occurs-thrice-i.h"

namespace leetcode {
namespace problem_2981 {
namespace {

class FindLongestSpecialSubstringThatOccursThriceITest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindLongestSpecialSubstringThatOccursThriceISolution solution_;
};

TEST_P(FindLongestSpecialSubstringThatOccursThriceITest, Example1) {
  EXPECT_EQ(solution_.maximumLength("aaaa"), 2);
}

TEST_P(FindLongestSpecialSubstringThatOccursThriceITest, Example2) {
  EXPECT_EQ(solution_.maximumLength("abcdef"), -1);
}

TEST_P(FindLongestSpecialSubstringThatOccursThriceITest, Example3) {
  EXPECT_EQ(solution_.maximumLength("abcaba"), 1);
}

TEST_P(FindLongestSpecialSubstringThatOccursThriceITest, SelfAuthoredAllSameChar) {
  // s = "aaaaaaaaaa" (10个a), 最长 run=10
  // L=8 时 count=10-8+1=3, 所以答案是 8
  EXPECT_EQ(solution_.maximumLength("aaaaaaaaaa"), 8);
}

TEST_P(FindLongestSpecialSubstringThatOccursThriceITest, SelfAuthoredMultipleRuns) {
  // s = "aabaaabaaa" -> runs of 'a': 2, 3, 3 (还有末尾? 等等)
  // "aabaaabaaa": a(2), b(1), a(3), b(1), a(3)
  // L=2: 三个 run 贡献 (2-2+1)=1, (3-2+1)=2, (3-2+1)=2 sum=5 >=3 ✓
  // L=3: (3-3+1)=1, (3-3+1)=1 sum=2 <3 ✗
  // 答案=2
  EXPECT_EQ(solution_.maximumLength("aabaaabaaa"), 2);
}

TEST_P(FindLongestSpecialSubstringThatOccursThriceITest, SelfAuthoredMinimumLength) {
  // s 长度恰好 3，三个相同字符
  EXPECT_EQ(solution_.maximumLength("aaa"), 1);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindLongestSpecialSubstringThatOccursThriceITest,
    testing::ValuesIn(
        FindLongestSpecialSubstringThatOccursThriceISolution()
            .getStrategyNames()));

}  // namespace
}  // namespace problem_2981
}  // namespace leetcode
