#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/valid-anagram.h"

namespace leetcode {
namespace problem_242 {

class ValidAnagramTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  ValidAnagramSolution solution;
};

TEST_P(ValidAnagramTest, Example1) {
  EXPECT_TRUE(solution.isAnagram("anagram", "nagaram"));
}

TEST_P(ValidAnagramTest, Example2) {
  EXPECT_FALSE(solution.isAnagram("rat", "car"));
}

TEST_P(ValidAnagramTest, SelfAuthoredSingleCharSame) {
  EXPECT_TRUE(solution.isAnagram("a", "a"));
}

TEST_P(ValidAnagramTest, SelfAuthoredSameLengthDifferent) {
  EXPECT_FALSE(solution.isAnagram("ab", "aa"));
}

INSTANTIATE_TEST_SUITE_P(
    ValidAnagramTestSuite, ValidAnagramTest,
    ::testing::ValuesIn(ValidAnagramSolution().getStrategyNames()));

}  // namespace problem_242
}  // namespace leetcode
