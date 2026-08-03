#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/most-common-word.h"

namespace leetcode::problem_819 {

class MostCommonWordTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  MostCommonWordSolution solution;
};

TEST_P(MostCommonWordTest, Example1) {
  std::string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
  std::vector<std::string> banned = {"hit"};
  EXPECT_EQ("ball", solution.mostCommonWord(paragraph, banned));
}

TEST_P(MostCommonWordTest, Example2) {
  std::string paragraph = "a.";
  std::vector<std::string> banned = {};
  EXPECT_EQ("a", solution.mostCommonWord(paragraph, banned));
}

TEST_P(MostCommonWordTest, SelfAuthoredBannedAllButOne) {
  std::string paragraph = "dog cat, dog!dog dog";
  std::vector<std::string> banned = {"dog"};
  EXPECT_EQ("cat", solution.mostCommonWord(paragraph, banned));
}

INSTANTIATE_TEST_SUITE_P(MostCommonWordStrategies, MostCommonWordTest,
                         ::testing::ValuesIn(MostCommonWordSolution().getStrategyNames()));

}  // namespace leetcode::problem_819
