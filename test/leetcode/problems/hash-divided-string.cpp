#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/hash-divided-string.h"

namespace leetcode {
namespace problem_3271 {
namespace {

class HashDividedStringTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  HashDividedStringSolution solution;
};

TEST_P(HashDividedStringTest, Example1) {
  EXPECT_EQ(solution.stringHash("abcd", 2), "bf");
}

TEST_P(HashDividedStringTest, Example2) {
  EXPECT_EQ(solution.stringHash("mxz", 3), "i");
}

TEST_P(HashDividedStringTest, SelfAuthoredSingleChar) {
  EXPECT_EQ(solution.stringHash("a", 1), "a");
}

TEST_P(HashDividedStringTest, SelfAuthoredSingleGroup) {
  EXPECT_EQ(solution.stringHash("zz", 2), "y");
}

INSTANTIATE_TEST_SUITE_P(
    HashDividedStringStrategies, HashDividedStringTest,
    ::testing::ValuesIn(HashDividedStringSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3271
}  // namespace leetcode
