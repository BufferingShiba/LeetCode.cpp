#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-sorted-vowel-strings.h"

namespace leetcode {
namespace problem_1641 {

class CountSortedVowelStringsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CountSortedVowelStringsSolution solution;
};

TEST_P(CountSortedVowelStringsTest, Example1) {
  EXPECT_EQ(5, solution.countVowelStrings(1));
}

TEST_P(CountSortedVowelStringsTest, Example2) {
  EXPECT_EQ(15, solution.countVowelStrings(2));
}

TEST_P(CountSortedVowelStringsTest, Example3) {
  EXPECT_EQ(66045, solution.countVowelStrings(33));
}

TEST_P(CountSortedVowelStringsTest, SelfAuthoredEdgeCase) {
  // n = 50 (max constraint).
  EXPECT_EQ(316251, solution.countVowelStrings(50));
  // n = 3 -> C(7,4) = 35.
  EXPECT_EQ(35, solution.countVowelStrings(3));
}

INSTANTIATE_TEST_SUITE_P(
    CountSortedVowelStringsTestSuite, CountSortedVowelStringsTest,
    ::testing::ValuesIn(CountSortedVowelStringsSolution().getStrategyNames()));

}  // namespace problem_1641
}  // namespace leetcode
