#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/shortest-completing-word.h"

namespace leetcode {
namespace problem_748 {

class ShortestCompletingWordTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ShortestCompletingWordSolution solution_;
};

TEST_P(ShortestCompletingWordTest, Example1) {
  std::string licensePlate = "1s3 PSt";
  std::vector<std::string> words = {"step", "steps", "stripe", "stepple"};
  EXPECT_EQ("steps", solution_.shortestCompletingWord(licensePlate, words));
}

TEST_P(ShortestCompletingWordTest, Example2) {
  std::string licensePlate = "1s3 456";
  std::vector<std::string> words = {"looks", "pest", "stew", "show"};
  EXPECT_EQ("pest", solution_.shortestCompletingWord(licensePlate, words));
}

TEST_P(ShortestCompletingWordTest, SelfAuthoredCaseInsensitive) {
  std::string licensePlate = "Abc";
  std::vector<std::string> words = {"cab", "bac", "xyz", "abc"};
  // "cab" length 3, "bac" length 3, "abc" length 3 -> first is "cab".
  EXPECT_EQ("cab", solution_.shortestCompletingWord(licensePlate, words));
}

INSTANTIATE_TEST_SUITE_P(
    ShortestCompletingWordTestSuite, ShortestCompletingWordTest,
    ::testing::ValuesIn(ShortestCompletingWordSolution().getStrategyNames()));

}  // namespace problem_748
}  // namespace leetcode
