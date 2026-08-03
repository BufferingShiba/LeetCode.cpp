#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/truncate-sentence.h"

namespace leetcode::problem_1816 {

class TruncateSentenceTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  TruncateSentenceSolution solution;
};

TEST_P(TruncateSentenceTest, Example1) {
  EXPECT_EQ(solution.truncateSentence("Hello how are you Contestant", 4),
            "Hello how are you");
}

TEST_P(TruncateSentenceTest, Example2) {
  EXPECT_EQ(solution.truncateSentence("What is the solution to this problem", 4),
            "What is the solution");
}

TEST_P(TruncateSentenceTest, Example3) {
  EXPECT_EQ(solution.truncateSentence("chopper is not a tanuki", 5),
            "chopper is not a tanuki");
}

INSTANTIATE_TEST_SUITE_P(TruncateSentenceTestCases, TruncateSentenceTest,
                         ::testing::ValuesIn(
                             TruncateSentenceSolution().getStrategyNames()));

}  // namespace leetcode::problem_1816
