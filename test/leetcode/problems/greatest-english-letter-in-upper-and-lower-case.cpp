#include <gtest/gtest.h>

#include "leetcode/problems/greatest-english-letter-in-upper-and-lower-case.h"

namespace leetcode {
namespace problem_2309 {

class GreatestEnglishLetterInUpperAndLowerCaseTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  GreatestEnglishLetterInUpperAndLowerCaseSolution solution;
};

TEST_P(GreatestEnglishLetterInUpperAndLowerCaseTest, Example1) {
  EXPECT_EQ(solution.greatestLetter("lEeTcOdE"), "E");
}

TEST_P(GreatestEnglishLetterInUpperAndLowerCaseTest, Example2) {
  EXPECT_EQ(solution.greatestLetter("arRAzFif"), "R");
}

TEST_P(GreatestEnglishLetterInUpperAndLowerCaseTest, Example3) {
  EXPECT_EQ(solution.greatestLetter("AbCdEfGhIjK"), "");
}

TEST_P(GreatestEnglishLetterInUpperAndLowerCaseTest, SelfAuthored) {
  EXPECT_EQ(solution.greatestLetter("a"), "");
  EXPECT_EQ(solution.greatestLetter("Z"), "");
  EXPECT_EQ(solution.greatestLetter("zZaAbB"), "Z");
}

INSTANTIATE_TEST_SUITE_P(
    Strategies, GreatestEnglishLetterInUpperAndLowerCaseTest,
    testing::ValuesIn(
        GreatestEnglishLetterInUpperAndLowerCaseSolution().getStrategyNames()));

}  // namespace problem_2309
}  // namespace leetcode
