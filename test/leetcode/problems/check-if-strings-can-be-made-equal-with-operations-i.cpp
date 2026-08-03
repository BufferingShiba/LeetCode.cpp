#include <gtest/gtest.h>
#include "leetcode/problems/check-if-strings-can-be-made-equal-with-operations-i.h"

namespace leetcode::problem_2839 {
namespace {

class CheckIfStringsCanBeMadeEqualWithOperationsITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  CheckIfStringsCanBeMadeEqualWithOperationsISolution solution;
};

TEST_P(CheckIfStringsCanBeMadeEqualWithOperationsITest, Example1) {
  EXPECT_TRUE(solution.canBeEqual("abcd", "cdab"));
}

TEST_P(CheckIfStringsCanBeMadeEqualWithOperationsITest, Example2) {
  EXPECT_FALSE(solution.canBeEqual("abcd", "dacb"));
}

TEST_P(CheckIfStringsCanBeMadeEqualWithOperationsITest, SameString) {
  EXPECT_TRUE(solution.canBeEqual("abcd", "abcd"));
}

TEST_P(CheckIfStringsCanBeMadeEqualWithOperationsITest, SwapOddOnly) {
  // s1 "acbd" -> swap(1,3) gives "adbc".
  EXPECT_TRUE(solution.canBeEqual("acbd", "adbc"));
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfStringsCanBeMadeEqualWithOperationsITestSuite,
    CheckIfStringsCanBeMadeEqualWithOperationsITest,
    ::testing::ValuesIn(
        CheckIfStringsCanBeMadeEqualWithOperationsISolution()
            .getStrategyNames()));

}  // namespace
}  // namespace leetcode::problem_2839
