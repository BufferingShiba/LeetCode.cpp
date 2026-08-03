#include <gtest/gtest.h>
#include <string>
#include "leetcode/problems/unique-length-3-palindromic-subsequences.h"

namespace leetcode {
namespace problem_1930 {

class UniqueLength3PalindromicSubsequencesTest : public ::testing::TestWithParam<std::string> {
protected:
    UniqueLength3PalindromicSubsequencesSolution solution;
    void SetUp() override {
        solution.setStrategy(GetParam());
    }
};

TEST_P(UniqueLength3PalindromicSubsequencesTest, Example1) {
    EXPECT_EQ(solution.countPalindromicSubsequence("aabca"), 3);
}

TEST_P(UniqueLength3PalindromicSubsequencesTest, Example2) {
    EXPECT_EQ(solution.countPalindromicSubsequence("adc"), 0);
}

TEST_P(UniqueLength3PalindromicSubsequencesTest, Example3) {
    EXPECT_EQ(solution.countPalindromicSubsequence("bbcbaba"), 4);
}

TEST_P(UniqueLength3PalindromicSubsequencesTest, AllSame) {
    EXPECT_EQ(solution.countPalindromicSubsequence("aaaa"), 1);
}

TEST_P(UniqueLength3PalindromicSubsequencesTest, RepeatingPattern) {
    // s = "abca": palindromes are "aba" and "aca".
    EXPECT_EQ(solution.countPalindromicSubsequence("abca"), 2);
}

INSTANTIATE_TEST_SUITE_P(
    UniqueLength3PalindromicSubsequencesStrategies,
    UniqueLength3PalindromicSubsequencesTest,
    ::testing::ValuesIn(UniqueLength3PalindromicSubsequencesSolution().getStrategyNames()));

}  // namespace problem_1930
}  // namespace leetcode
