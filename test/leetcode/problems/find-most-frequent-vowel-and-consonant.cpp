#include <gtest/gtest.h>
#include <string>

#include "leetcode/problems/find-most-frequent-vowel-and-consonant.h"

namespace leetcode {
namespace problem_3541 {
namespace {

class FindMostFrequentVowelAndConsonantTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindMostFrequentVowelAndConsonantSolution solution_;
};

TEST_P(FindMostFrequentVowelAndConsonantTest, Example1) {
  EXPECT_EQ(solution_.maxFreqSum("successes"), 6);
}

TEST_P(FindMostFrequentVowelAndConsonantTest, Example2) {
  EXPECT_EQ(solution_.maxFreqSum("aeiaeia"), 3);
}

TEST_P(FindMostFrequentVowelAndConsonantTest, OnlyConsonants) {
  EXPECT_EQ(solution_.maxFreqSum("bbbccc"), 3);
}

TEST_P(FindMostFrequentVowelAndConsonantTest, OnlyVowels) {
  EXPECT_EQ(solution_.maxFreqSum("aeiou"), 1);
}

static const std::vector<std::string> kStrategyNames =
    FindMostFrequentVowelAndConsonantSolution().getStrategyNames();

INSTANTIATE_TEST_SUITE_P(
    FindMostFrequentVowelAndConsonantTestCases,
    FindMostFrequentVowelAndConsonantTest,
    ::testing::ValuesIn(kStrategyNames));

}  // namespace
}  // namespace problem_3541
}  // namespace leetcode
