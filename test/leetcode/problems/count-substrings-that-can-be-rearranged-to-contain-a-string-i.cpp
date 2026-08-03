#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-i.h"

namespace leetcode::problem_3297 {

class CountSubstringsThatCanBeRearrangedToContainAStringISolutionTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CountSubstringsThatCanBeRearrangedToContainAStringISolution solution_;
};

TEST_P(CountSubstringsThatCanBeRearrangedToContainAStringISolutionTest,
       Example1) {
  EXPECT_EQ(1, solution_.validSubstringCount("bcca", "abc"));
}

TEST_P(CountSubstringsThatCanBeRearrangedToContainAStringISolutionTest,
       Example2) {
  EXPECT_EQ(10, solution_.validSubstringCount("abcabc", "abc"));
}

TEST_P(CountSubstringsThatCanBeRearrangedToContainAStringISolutionTest,
       Example3) {
  EXPECT_EQ(0, solution_.validSubstringCount("abcabc", "aaabc"));
}

TEST_P(CountSubstringsThatCanBeRearrangedToContainAStringISolutionTest,
       SelfAuthoredSingleCharMatch) {
  EXPECT_EQ(1, solution_.validSubstringCount("a", "a"));
}

TEST_P(CountSubstringsThatCanBeRearrangedToContainAStringISolutionTest,
       SelfAuthoredWord2LongerThanWord1) {
  EXPECT_EQ(0, solution_.validSubstringCount("ab", "abc"));
}

INSTANTIATE_TEST_SUITE_P(
    CountSubstringsThatCanBeRearrangedToContainAStringISolutionTest,
    CountSubstringsThatCanBeRearrangedToContainAStringISolutionTest,
    ::testing::ValuesIn(
        CountSubstringsThatCanBeRearrangedToContainAStringISolution()
            .getStrategyNames()));

}  // namespace leetcode::problem_3297
