#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/maximum-number-of-vowels-in-a-substring-of-given-length.h"

namespace leetcode {
namespace problem_1456 {

class MaximumNumberOfVowelsInASubstringOfGivenLengthTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MaximumNumberOfVowelsInASubstringOfGivenLengthSolution solution;
};

TEST_P(MaximumNumberOfVowelsInASubstringOfGivenLengthTest, Example1) {
  EXPECT_EQ(solution.maxVowels("abciiidef", 3), 3);
}

TEST_P(MaximumNumberOfVowelsInASubstringOfGivenLengthTest, Example2) {
  EXPECT_EQ(solution.maxVowels("aeiou", 2), 2);
}

TEST_P(MaximumNumberOfVowelsInASubstringOfGivenLengthTest, Example3) {
  EXPECT_EQ(solution.maxVowels("leetcode", 3), 2);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    MaximumNumberOfVowelsInASubstringOfGivenLengthTest,
    testing::ValuesIn(
        MaximumNumberOfVowelsInASubstringOfGivenLengthSolution().getStrategyNames()));

}  // namespace problem_1456
}  // namespace leetcode
