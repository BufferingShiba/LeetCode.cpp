
#include "leetcode/problems/decoded-string-at-index.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_880 {

class DecodedStringAtIndexTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DecodedStringAtIndexSolution solution;
};

TEST_P(DecodedStringAtIndexTest, Example1) {
  EXPECT_EQ(std::string("o"), solution.decodeAtIndex("leet2code3", 10));
}

TEST_P(DecodedStringAtIndexTest, Example2) {
  EXPECT_EQ(std::string("h"), solution.decodeAtIndex("ha22", 5));
}

TEST_P(DecodedStringAtIndexTest, Example3) {
  EXPECT_EQ(std::string("a"), solution.decodeAtIndex("a2345678999999999999999", 1));
}

TEST_P(DecodedStringAtIndexTest, SelfAuthoredSingleRepeatedLetter) {
  EXPECT_EQ(std::string("a"), solution.decodeAtIndex("a2", 2));
}

TEST_P(DecodedStringAtIndexTest, SelfAuthoredMultipleDigitsInARow) {
  // "ab23" -> "abababababab" ("ab" repeated 6 times = 12 chars), 1-indexed
  // position 9 is 'a' (group 4, char 0)
  EXPECT_EQ(std::string("a"), solution.decodeAtIndex("ab23", 9));
}

TEST_P(DecodedStringAtIndexTest, SelfAuthoredLargeK) {
  EXPECT_EQ(std::string("y"), solution.decodeAtIndex("y959q969u3hb22odq595", 1));
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, DecodedStringAtIndexTest,
    ::testing::ValuesIn(DecodedStringAtIndexSolution().getStrategyNames()));

}  // namespace problem_880
}  // namespace leetcode
