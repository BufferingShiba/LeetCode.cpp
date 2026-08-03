#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/minimum-number-of-flips-to-make-the-binary-string-alternating.h"

namespace leetcode {
namespace problem_1888 {

using MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingTestSolution =
    MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingSolution;

class MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingTestSolution solution;
};

TEST_P(MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingTest, Example1) {
  EXPECT_EQ(solution.minFlips("111000"), 2);
}

TEST_P(MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingTest, Example2) {
  EXPECT_EQ(solution.minFlips("010"), 0);
}

TEST_P(MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingTest, Example3) {
  EXPECT_EQ(solution.minFlips("1110"), 1);
}

TEST_P(MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingTest, SelfAuthoredSingleCharacter) {
  EXPECT_EQ(solution.minFlips("0"), 0);
  EXPECT_EQ(solution.minFlips("1"), 0);
}

TEST_P(MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingTest, SelfAuthoredTwoCharacters) {
  EXPECT_EQ(solution.minFlips("01"), 0);
  EXPECT_EQ(solution.minFlips("00"), 1);
  EXPECT_EQ(solution.minFlips("11"), 1);
}

TEST_P(MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingTest, SelfAuthoredThreeCharacters) {
  EXPECT_EQ(solution.minFlips("101"), 0);
  EXPECT_EQ(solution.minFlips("000"), 1);
  EXPECT_EQ(solution.minFlips("111"), 1);
}

TEST_P(MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingTest, SelfAuthoredShiftByOne) {
  // "111000": we use cyclic shifts to get 2. Also check "0011":
  // cyclic shifts: 0011, 0110, 1100, 1001. "0110" has a "11", "1001" has
  // "00". None alternating; best flip count = 2 (e.g. turn into 0101).
  EXPECT_EQ(solution.minFlips("0011"), 2);
}

TEST_P(MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingTest, SelfAuthoredAllSame) {
  // n = 5 all zeros: to alternate needs flipping ceil? "00000" -> one position
  // pattern 01010 needs 2 flips, 10101 needs 3, min = 2.
  EXPECT_EQ(solution.minFlips("00000"), 2);
}


// LeetCode 失败用例: WrongAnswerCase1
TEST_P(MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingTest, WrongAnswerCase1) {
  // 输入: s = "0001100010101000111101000110101111000000101100000001001"
    // 期望: 22, got 23
    EXPECT_EQ(solution.minFlips("0001100010101000111101000110101111000000101100000001001"), 22);
}

// LeetCode 失败用例: BruteForceIsolateWA
TEST_P(MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingTest, BruteForceIsolateWA) {
  std::string s = "0001100010101000111101000110101111000000101100000001001";
    int n = (int)s.size();
    int naive = INT_MAX;
    for (int r = 0; r < n; ++r) {
      std::string t = s.substr(r) + s.substr(0, r);
      int c0 = 0, c1 = 0;
      for (int j = 0; j < n; ++j) {
        if (t[j] != static_cast<char>('0' + (j % 2))) ++c0;
        if (t[j] != static_cast<char>('1' - (j % 2))) ++c1;
      }
      naive = std::min(naive, std::min(c0, c1));
    }
    EXPECT_EQ(22, naive);
    EXPECT_EQ(naive, solution.minFlips(s));
}
INSTANTIATE_TEST_SUITE_P(
    MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingTestSuite,
    MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingTest,
    ::testing::ValuesIn(
        MinimumNumberOfFlipsToMakeTheBinaryStringAlternatingTestSolution()
            .getStrategyNames()));

}  // namespace problem_1888
}  // namespace leetcode
