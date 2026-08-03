#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii.h"

namespace leetcode::problem_2186 {

class MinimumNumberOfStepsToMakeTwoStringsAnagramIiTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MinimumNumberOfStepsToMakeTwoStringsAnagramIiSolution solution_;
};

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MinimumNumberOfStepsToMakeTwoStringsAnagramIiTest,
    testing::ValuesIn(
        MinimumNumberOfStepsToMakeTwoStringsAnagramIiSolution()
            .getStrategyNames()));

TEST_P(MinimumNumberOfStepsToMakeTwoStringsAnagramIiTest, Example1) {
  EXPECT_EQ(solution_.minSteps("leetcode", "coats"), 7);
}

TEST_P(MinimumNumberOfStepsToMakeTwoStringsAnagramIiTest, Example2) {
  EXPECT_EQ(solution_.minSteps("night", "thing"), 0);
}

}  // namespace leetcode::problem_2186
