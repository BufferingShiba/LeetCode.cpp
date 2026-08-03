#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "leetcode/problems/lexicographically-smallest-beautiful-string.h"

namespace leetcode {
namespace problem_2663 {

class LexicographicallySmallestBeautifulStringTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  LexicographicallySmallestBeautifulStringSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(LexicographicallySmallestBeautifulStringTest, Example1) {
  EXPECT_EQ(solution.smallestBeautifulString("abcz", 26), "abda");
}

TEST_P(LexicographicallySmallestBeautifulStringTest, Example2) {
  EXPECT_EQ(solution.smallestBeautifulString("dc", 4), "");
}

TEST_P(LexicographicallySmallestBeautifulStringTest, SelfAuthoredSingleCharIncrement) {
  // "a" cannot become anything bigger? Actually "a" < ... single char just needs
  // to differ from nothing except exceeding 'a'.
  EXPECT_EQ(solution.smallestBeautifulString("a", 26), "b");
}

TEST_P(LexicographicallySmallestBeautifulStringTest, SelfAuthoredMaxAlphabetNoRoom) {
  // k=4 uses a,b,c,d. "dc" leaves no increment for 'd' (position 1) and
  // for 'd' at position 0 since limit is 'd'. Covered by Example2.
  EXPECT_EQ(solution.smallestBeautifulString("dcd", 4), "");
}

INSTANTIATE_TEST_SUITE_P(
    LexicographicallySmallestBeautifulStringTestSuite,
    LexicographicallySmallestBeautifulStringTest,
    ::testing::ValuesIn(
        LexicographicallySmallestBeautifulStringSolution().getStrategyNames()));

}  // namespace problem_2663
}  // namespace leetcode
