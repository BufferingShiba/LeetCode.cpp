#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/circular-sentence.h"

namespace leetcode {
namespace problem_2490 {

class CircularSentenceTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CircularSentenceSolution solution_;
};

TEST_P(CircularSentenceTest, Example1) {
  EXPECT_TRUE(solution_.isCircularSentence("leetcode exercises sound delightful"));
}

TEST_P(CircularSentenceTest, Example2) {
  EXPECT_TRUE(solution_.isCircularSentence("eetcode"));
}

TEST_P(CircularSentenceTest, Example3) {
  EXPECT_FALSE(solution_.isCircularSentence("Leetcode is cool"));
}

TEST_P(CircularSentenceTest, SelfAuthoredSingleChar) {
  EXPECT_TRUE(solution_.isCircularSentence("a"));
}

INSTANTIATE_TEST_SUITE_P(
    CircularSentenceStrategies,
    CircularSentenceTest,
    ::testing::ValuesIn(CircularSentenceSolution().getStrategyNames()));

}  // namespace problem_2490
}  // namespace leetcode
