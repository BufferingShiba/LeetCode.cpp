#include <gtest/gtest.h>

#include "leetcode/problems/string-compression-ii.h"

using namespace leetcode::problem_1531;

class StringCompressionIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  StringCompressionIiSolution solution;

  void SetUp() override {
    solution.setStrategy(GetParam());
  }
};

TEST_P(StringCompressionIiTest, Example1) {
  EXPECT_EQ(solution.getLengthOfOptimalCompression("aaabcccd", 2), 4);
}

TEST_P(StringCompressionIiTest, Example2) {
  EXPECT_EQ(solution.getLengthOfOptimalCompression("aabbaa", 2), 2);
}

TEST_P(StringCompressionIiTest, Example3) {
  EXPECT_EQ(solution.getLengthOfOptimalCompression("aaaaaaaaaaa", 0), 3);
}

INSTANTIATE_TEST_SUITE_P(Strategies, StringCompressionIiTest,
                         ::testing::ValuesIn(StringCompressionIiSolution().getStrategyNames()));
