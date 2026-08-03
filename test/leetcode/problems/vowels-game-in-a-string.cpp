#include "leetcode/problems/vowels-game-in-a-string.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3227 {

class VowelsGameInAStringTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  VowelsGameInAStringSolution solution;
};

TEST_P(VowelsGameInAStringTest, Example1) {
  EXPECT_TRUE(solution.doesAliceWin("leetcoder"));
}

TEST_P(VowelsGameInAStringTest, Example2) {
  EXPECT_FALSE(solution.doesAliceWin("bbcd"));
}

TEST_P(VowelsGameInAStringTest, SelfAuthoredSingleVowel) {
  EXPECT_TRUE(solution.doesAliceWin("a"));
}

TEST_P(VowelsGameInAStringTest, SelfAuthoredNoVowelSingleChar) {
  EXPECT_FALSE(solution.doesAliceWin("z"));
}

TEST_P(VowelsGameInAStringTest, SelfAuthoredAllVowelsEven) {
  EXPECT_TRUE(solution.doesAliceWin("aeiou"));
}

INSTANTIATE_TEST_SUITE_P(
    VowelsGameInAStringSuite, VowelsGameInAStringTest,
    ::testing::ValuesIn(VowelsGameInAStringSolution().getStrategyNames()));

}  // namespace problem_3227
}  // namespace leetcode
