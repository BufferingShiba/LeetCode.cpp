#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/remove-letter-to-equalize-frequency.h"

namespace leetcode {
namespace problem_2423 {

class RemoveLetterToEqualizeFrequencyTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RemoveLetterToEqualizeFrequencySolution solution;
};

TEST_P(RemoveLetterToEqualizeFrequencyTest, Example1) {
  EXPECT_TRUE(solution.equalFrequency("abcc"));
}

TEST_P(RemoveLetterToEqualizeFrequencyTest, Example2) {
  EXPECT_FALSE(solution.equalFrequency("aazz"));
}

TEST_P(RemoveLetterToEqualizeFrequencyTest, SingleChar) {
  EXPECT_TRUE(solution.equalFrequency("ab"));
}

TEST_P(RemoveLetterToEqualizeFrequencyTest, SameChars) {
  EXPECT_TRUE(solution.equalFrequency("aaaa"));
}

TEST_P(RemoveLetterToEqualizeFrequencyTest, EdgeTwoSame) {
  EXPECT_TRUE(solution.equalFrequency("zz"));
}

TEST_P(RemoveLetterToEqualizeFrequencyTest, OneExtraMostFrequent) {
  EXPECT_TRUE(solution.equalFrequency("aab"));
}

INSTANTIATE_TEST_SUITE_P(
    RemoveLetterToEqualizeFrequencyTestSuite,
    RemoveLetterToEqualizeFrequencyTest,
    ::testing::ValuesIn(
        RemoveLetterToEqualizeFrequencySolution().getStrategyNames()));

}  // namespace problem_2423
}  // namespace leetcode
