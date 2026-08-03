#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/maximum-repeating-substring.h"

namespace leetcode {
namespace problem_1668 {

class MaximumRepeatingSubstringTest : public ::testing::TestWithParam<std::string> {
 protected:
  MaximumRepeatingSubstringSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(MaximumRepeatingSubstringTest, Example1) {
  EXPECT_EQ(solution.maxRepeating("ababc", "ab"), 2);
}

TEST_P(MaximumRepeatingSubstringTest, Example2) {
  EXPECT_EQ(solution.maxRepeating("ababc", "ba"), 1);
}

TEST_P(MaximumRepeatingSubstringTest, Example3) {
  EXPECT_EQ(solution.maxRepeating("ababc", "ac"), 0);
}

TEST_P(MaximumRepeatingSubstringTest, SelfAuthoredWholeSequence) {
  EXPECT_EQ(solution.maxRepeating("aaa", "a"), 3);
}

TEST_P(MaximumRepeatingSubstringTest, SelfAuthoredWordLongerThanSequence) {
  EXPECT_EQ(solution.maxRepeating("abc", "abcd"), 0);
}

TEST_P(MaximumRepeatingSubstringTest, SelfAuthoredSingleCharNoRepeat) {
  EXPECT_EQ(solution.maxRepeating("b", "a"), 0);
}

INSTANTIATE_TEST_SUITE_P(
    MaximumRepeatingSubstringTestSuite, MaximumRepeatingSubstringTest,
    ::testing::ValuesIn(MaximumRepeatingSubstringSolution().getStrategyNames()));

}  // namespace problem_1668
}  // namespace leetcode
