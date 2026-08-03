#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/binary-string-with-substrings-representing-1-to-n.h"

namespace leetcode::problem_1016 {
namespace {

class BinaryStringWithSubstringsRepresenting1ToNTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  BinaryStringWithSubstringsRepresenting1ToNSolution solution_;
};

TEST_P(BinaryStringWithSubstringsRepresenting1ToNTest, Example1) {
  EXPECT_TRUE(solution_.queryString("0110", 3));
}

TEST_P(BinaryStringWithSubstringsRepresenting1ToNTest, Example2) {
  EXPECT_FALSE(solution_.queryString("0110", 4));
}

TEST_P(BinaryStringWithSubstringsRepresenting1ToNTest, SingleChar) {
  EXPECT_TRUE(solution_.queryString("1", 1));
  EXPECT_FALSE(solution_.queryString("0", 1));
}

TEST_P(BinaryStringWithSubstringsRepresenting1ToNTest, LargerN) {
  EXPECT_FALSE(solution_.queryString("0110", 5));
}

TEST_P(BinaryStringWithSubstringsRepresenting1ToNTest, MissingPattern) {
  // "000101" 不含 "11"，因此 n=3（二进制 "11"）为 false。
  EXPECT_FALSE(solution_.queryString("000101", 3));
}

TEST_P(BinaryStringWithSubstringsRepresenting1ToNTest, ContainsAll) {
  // "1101" 的子串含 "1"、"10"、"11"，覆盖 [1,3]。
  EXPECT_TRUE(solution_.queryString("1101", 3));
}

INSTANTIATE_TEST_SUITE_P(
    BinaryStringWithSubstringsRepresenting1ToNTestCases,
    BinaryStringWithSubstringsRepresenting1ToNTest,
    ::testing::ValuesIn(
        BinaryStringWithSubstringsRepresenting1ToNSolution()
            .getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_1016
