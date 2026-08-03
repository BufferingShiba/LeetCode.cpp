#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/splitting-a-string-into-descending-consecutive-values.h"

namespace leetcode {
namespace problem_1849 {

class SplittingAStringIntoDescendingConsecutiveValuesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  SplittingAStringIntoDescendingConsecutiveValuesSolution solution_;
};

TEST_P(SplittingAStringIntoDescendingConsecutiveValuesTest, Example1) {
  EXPECT_FALSE(solution_.splitString("1234"));
}

TEST_P(SplittingAStringIntoDescendingConsecutiveValuesTest, Example2) {
  EXPECT_TRUE(solution_.splitString("050043"));
}

TEST_P(SplittingAStringIntoDescendingConsecutiveValuesTest, Example3) {
  EXPECT_FALSE(solution_.splitString("9080701"));
}

TEST_P(SplittingAStringIntoDescendingConsecutiveValuesTest, DescriptionExamples) {
  EXPECT_TRUE(solution_.splitString("0090089"));
  EXPECT_FALSE(solution_.splitString("001"));
}

TEST_P(SplittingAStringIntoDescendingConsecutiveValuesTest, SelfComplement) {
  EXPECT_TRUE(solution_.splitString("21"));
  EXPECT_FALSE(solution_.splitString("1234"));
}

TEST_P(SplittingAStringIntoDescendingConsecutiveValuesTest, LongDigitsDoNotOverflow) {
  EXPECT_FALSE(solution_.splitString("99999999999999999999"));
}

INSTANTIATE_TEST_SUITE_P(
    SplittingAStringIntoDescendingConsecutiveValuesTest,
    SplittingAStringIntoDescendingConsecutiveValuesTest,
    ::testing::ValuesIn(
        SplittingAStringIntoDescendingConsecutiveValuesSolution()
            .getStrategyNames()));

}  // namespace problem_1849
}  // namespace leetcode
