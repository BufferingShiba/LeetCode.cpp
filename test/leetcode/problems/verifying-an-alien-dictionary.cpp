#include "leetcode/problems/verifying-an-alien-dictionary.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode::problem_953 {

class VerifyingAnAlienDictionaryTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  VerifyingAnAlienDictionarySolution solution;
};

TEST_P(VerifyingAnAlienDictionaryTest, Example1) {
  std::vector<std::string> words = {"hello", "leetcode"};
  EXPECT_TRUE(solution.isAlienSorted(words, "hlabcdefgijkmnopqrstuvwxyz"));
}

TEST_P(VerifyingAnAlienDictionaryTest, Example2) {
  std::vector<std::string> words = {"word", "world", "row"};
  EXPECT_FALSE(solution.isAlienSorted(words, "worldabcefghijkmnpqstuvxyz"));
}

TEST_P(VerifyingAnAlienDictionaryTest, Example3) {
  std::vector<std::string> words = {"apple", "app"};
  EXPECT_FALSE(solution.isAlienSorted(words, "abcdefghijklmnopqrstuvwxyz"));
}

TEST_P(VerifyingAnAlienDictionaryTest, SelfAuthoredSingleWord) {
  std::vector<std::string> words = {"hello"};
  EXPECT_TRUE(solution.isAlienSorted(words, "abcdefghijklmnopqrstuvwxyz"));
}

INSTANTIATE_TEST_SUITE_P(
    VerifyingAnAlienDictionaryTest, VerifyingAnAlienDictionaryTest,
    ::testing::ValuesIn(VerifyingAnAlienDictionarySolution().getStrategyNames()));

}  // namespace leetcode::problem_953
