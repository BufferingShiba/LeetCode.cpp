#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/unique-morse-code-words.h"

namespace leetcode {
namespace problem_804 {

class UniqueMorseCodeWordsTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  UniqueMorseCodeWordsSolution solution;
};

TEST_P(UniqueMorseCodeWordsTest, Example1) {
  std::vector<std::string> words = {"gin", "zen", "gig", "msg"};
  EXPECT_EQ(solution.uniqueMorseRepresentations(words), 2);
}

TEST_P(UniqueMorseCodeWordsTest, Example2) {
  std::vector<std::string> words = {"a"};
  EXPECT_EQ(solution.uniqueMorseRepresentations(words), 1);
}

TEST_P(UniqueMorseCodeWordsTest, SelfAuthoredAllDistinct) {
  std::vector<std::string> words = {"a", "b", "c"};
  EXPECT_EQ(solution.uniqueMorseRepresentations(words), 3);
}

INSTANTIATE_TEST_SUITE_P(
    UniqueMorseCodeWordsTestSuite, UniqueMorseCodeWordsTest,
    ::testing::ValuesIn(UniqueMorseCodeWordsSolution().getStrategyNames()));

}  // namespace problem_804
}  // namespace leetcode
