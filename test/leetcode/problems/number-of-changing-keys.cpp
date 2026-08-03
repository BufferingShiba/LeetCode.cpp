#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/number-of-changing-keys.h"

namespace leetcode {
namespace problem_3019 {

class NumberOfChangingKeysTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  NumberOfChangingKeysSolution solution;
};

TEST_P(NumberOfChangingKeysTest, Example1) {
  EXPECT_EQ(solution.countKeyChanges("aAbBcC"), 2);
}

TEST_P(NumberOfChangingKeysTest, Example2) {
  EXPECT_EQ(solution.countKeyChanges("AaAaAaaA"), 0);
}

TEST_P(NumberOfChangingKeysTest, SelfAuthoredSingleCharacter) {
  EXPECT_EQ(solution.countKeyChanges("z"), 0);
}

TEST_P(NumberOfChangingKeysTest, SelfAuthoredAllDistinct) {
  EXPECT_EQ(solution.countKeyChanges("abcd"), 3);
}

INSTANTIATE_TEST_SUITE_P(
    NumberOfChangingKeysTestCases, NumberOfChangingKeysTest,
    ::testing::ValuesIn(NumberOfChangingKeysSolution().getStrategyNames()));

}  // namespace problem_3019
}  // namespace leetcode
