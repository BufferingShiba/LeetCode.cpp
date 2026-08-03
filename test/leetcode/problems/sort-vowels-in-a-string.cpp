#include "leetcode/problems/sort-vowels-in-a-string.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_2785 {

class SortVowelsInAStringTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SortVowelsInAStringSolution solution;
};

TEST_P(SortVowelsInAStringTest, OfficialExample1) {
  std::string result = solution.sortVowels("lEetcOde");
  EXPECT_EQ("lEOtcede", result);
}

TEST_P(SortVowelsInAStringTest, OfficialExample2) {
  std::string result = solution.sortVowels("lYmpH");
  EXPECT_EQ("lYmpH", result);
}

INSTANTIATE_TEST_SUITE_P(
    LeetCode, SortVowelsInAStringTest,
    ::testing::ValuesIn(SortVowelsInAStringSolution().getStrategyNames()));

}  // namespace problem_2785
}  // namespace leetcode
