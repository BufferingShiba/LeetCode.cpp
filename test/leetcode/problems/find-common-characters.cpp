#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/find-common-characters.h"

namespace leetcode {
namespace problem_1002 {

class FindCommonCharactersTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  FindCommonCharactersSolution solution;
};

TEST_P(FindCommonCharactersTest, Example1) {
  std::vector<std::string> words = {"bella", "label", "roller"};
  std::vector<std::string> expected = {"e", "l", "l"};
  EXPECT_EQ(solution.commonChars(words), expected);
}

TEST_P(FindCommonCharactersTest, Example2) {
  std::vector<std::string> words = {"cool", "lock", "cook"};
  std::vector<std::string> expected = {"c", "o"};
  EXPECT_EQ(solution.commonChars(words), expected);
}

TEST_P(FindCommonCharactersTest, SelfAuthoredSingleWord) {
  std::vector<std::string> words = {"abc"};
  std::vector<std::string> expected = {"a", "b", "c"};
  EXPECT_EQ(solution.commonChars(words), expected);
}

TEST_P(FindCommonCharactersTest, SelfAuthoredNoCommon) {
  std::vector<std::string> words = {"abc", "def"};
  std::vector<std::string> expected = {};
  EXPECT_EQ(solution.commonChars(words), expected);
}

INSTANTIATE_TEST_SUITE_P(
    FindCommonCharactersTestSuite, FindCommonCharactersTest,
    ::testing::ValuesIn(FindCommonCharactersSolution().getStrategyNames()));

}  // namespace problem_1002
}  // namespace leetcode
