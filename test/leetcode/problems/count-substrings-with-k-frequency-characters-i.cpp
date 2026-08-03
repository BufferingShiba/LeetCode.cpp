#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/count-substrings-with-k-frequency-characters-i.h"

namespace leetcode {
namespace problem_3325 {

using CountSubstringsWithKFrequencyCharactersITest =
    ::testing::TestWithParam<std::string>;

class CountSubstringsWithKFrequencyCharactersIParamTest
    : public CountSubstringsWithKFrequencyCharactersITest {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  CountSubstringsWithKFrequencyCharactersISolution solution_;
};

TEST_P(CountSubstringsWithKFrequencyCharactersIParamTest,
       Example1) {
  EXPECT_EQ(solution_.numberOfSubstrings("abacb", 2), 4);
}

TEST_P(CountSubstringsWithKFrequencyCharactersIParamTest,
       Example2) {
  EXPECT_EQ(solution_.numberOfSubstrings("abcde", 1), 15);
}

TEST_P(CountSubstringsWithKFrequencyCharactersIParamTest,
       SelfAuthoredSingleCharKEqualsOne) {
  EXPECT_EQ(solution_.numberOfSubstrings("a", 1), 1);
}

TEST_P(CountSubstringsWithKFrequencyCharactersIParamTest,
       SelfAuthoredSingleCharKSame) {
  // s = "aa", k = 2 -> "aa" is the only valid substring.
  EXPECT_EQ(solution_.numberOfSubstrings("aa", 2), 1);
}

INSTANTIATE_TEST_SUITE_P(
    CountSubstringsWithKFrequencyCharactersITests,
    CountSubstringsWithKFrequencyCharactersIParamTest,
    ::testing::ValuesIn(
        CountSubstringsWithKFrequencyCharactersISolution()
            .getStrategyNames()));

}  // namespace problem_3325
}  // namespace leetcode
