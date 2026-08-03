#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/number-of-wonderful-substrings.h"

namespace leetcode::problem_1915 {

class NumberOfWonderfulSubstringsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  NumberOfWonderfulSubstringsSolution solution_;
};

TEST_P(NumberOfWonderfulSubstringsTest, Example1) {
  EXPECT_EQ(solution_.wonderfulSubstrings("aba"), 4);
}

TEST_P(NumberOfWonderfulSubstringsTest, Example2) {
  EXPECT_EQ(solution_.wonderfulSubstrings("aabb"), 9);
}

TEST_P(NumberOfWonderfulSubstringsTest, Example3) {
  EXPECT_EQ(solution_.wonderfulSubstrings("he"), 2);
}

TEST_P(NumberOfWonderfulSubstringsTest, SelfAuthoredSingleChar) {
  EXPECT_EQ(solution_.wonderfulSubstrings("a"), 1);
}

TEST_P(NumberOfWonderfulSubstringsTest, SelfAuthoredAllSame) {
  EXPECT_EQ(solution_.wonderfulSubstrings("aaaa"), 10);
}

TEST_P(NumberOfWonderfulSubstringsTest, SelfAuthoredTwoDistinctPairs) {
  // "aabb": already covered in Example2. Use "ab" -> a, ab, b => only
  // singles are wonderful (ab has two odd letters), so answer = 2.
  EXPECT_EQ(solution_.wonderfulSubstrings("ab"), 2);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfWonderfulSubstringsTestSuite,
    NumberOfWonderfulSubstringsTest,
    ::testing::ValuesIn(NumberOfWonderfulSubstringsSolution().getStrategyNames()));

}  // namespace leetcode::problem_1915
