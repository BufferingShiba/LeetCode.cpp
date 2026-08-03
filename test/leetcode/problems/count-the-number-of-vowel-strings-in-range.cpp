#include "leetcode/problems/count-the-number-of-vowel-strings-in-range.h"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2586 {

using CountTheNumberOfVowelStringsInRangeTest =
    ::testing::TestWithParam<std::string>;

class CountTheNumberOfVowelStringsInRangeFixture
    : public CountTheNumberOfVowelStringsInRangeTest {
 protected:
  void SetUp() override {
    solution.setStrategy(GetParam());
  }

  CountTheNumberOfVowelStringsInRangeSolution solution;
};

TEST_P(CountTheNumberOfVowelStringsInRangeFixture, Example1) {
  std::vector<std::string> words = {"are", "amy", "u"};
  EXPECT_EQ(2, solution.vowelStrings(words, 0, 2));
}

TEST_P(CountTheNumberOfVowelStringsInRangeFixture, Example2) {
  std::vector<std::string> words = {"hey", "aeo", "mu", "ooo", "artro"};
  EXPECT_EQ(3, solution.vowelStrings(words, 1, 4));
}

TEST_P(CountTheNumberOfVowelStringsInRangeFixture, SelfAuthoredSingleWordVowel) {
  std::vector<std::string> words = {"aeiou"};
  EXPECT_EQ(1, solution.vowelStrings(words, 0, 0));
}

TEST_P(CountTheNumberOfVowelStringsInRangeFixture, SelfAuthoredSingleWordNotVowel) {
  std::vector<std::string> words = {"bcdfg"};
  EXPECT_EQ(0, solution.vowelStrings(words, 0, 0));
}

INSTANTIATE_TEST_SUITE_P(
    CountTheNumberOfVowelStringsInRangeSuite,
    CountTheNumberOfVowelStringsInRangeFixture,
    ::testing::ValuesIn(
        CountTheNumberOfVowelStringsInRangeSolution().getStrategyNames()));

}  // namespace problem_2586
}  // namespace leetcode
