#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/check-if-digits-are-equal-in-string-after-operations-i.h"

namespace leetcode {
namespace problem_3461 {

class CheckIfDigitsAreEqualInStringAfterOperationsITest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CheckIfDigitsAreEqualInStringAfterOperationsISolution solution;
};

TEST_P(CheckIfDigitsAreEqualInStringAfterOperationsITest, Example1) {
  EXPECT_TRUE(solution.hasSameDigits("3902"));
}

TEST_P(CheckIfDigitsAreEqualInStringAfterOperationsITest, Example2) {
  EXPECT_FALSE(solution.hasSameDigits("34789"));
}

TEST_P(CheckIfDigitsAreEqualInStringAfterOperationsITest, SelfAuthoredEdgeCaseLength3) {
  // "111": (1+1)%10=2, (1+1)%10=2 -> "22", same
  EXPECT_TRUE(solution.hasSameDigits("111"));
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfDigitsAreEqualInStringAfterOperationsITests,
    CheckIfDigitsAreEqualInStringAfterOperationsITest,
    ::testing::ValuesIn(
        CheckIfDigitsAreEqualInStringAfterOperationsISolution()
            .getStrategyNames()));

}  // namespace problem_3461
}  // namespace leetcode
