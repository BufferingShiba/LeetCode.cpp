#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/check-if-the-sentence-is-pangram.h"

namespace leetcode {
namespace problem_1832 {

class CheckIfTheSentenceIsPangramTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  CheckIfTheSentenceIsPangramSolution solution;
};

TEST_P(CheckIfTheSentenceIsPangramTest, Example1) {
  EXPECT_TRUE(solution.checkIfPangram("thequickbrownfoxjumpsoverthelazydog"));
}

TEST_P(CheckIfTheSentenceIsPangramTest, Example2) {
  EXPECT_FALSE(solution.checkIfPangram("leetcode"));
}

TEST_P(CheckIfTheSentenceIsPangramTest, SelfAuthoredSingleChar) {
  EXPECT_FALSE(solution.checkIfPangram("a"));
}

TEST_P(CheckIfTheSentenceIsPangramTest, SelfAuthoredAllLettersOneEach) {
  EXPECT_TRUE(solution.checkIfPangram("abcdefghijklmnopqrstuvwxyz"));
}

TEST_P(CheckIfTheSentenceIsPangramTest, SelfAuthoredRepeatedMissingOne) {
  EXPECT_FALSE(solution.checkIfPangram("abcdefghijklmnopqrstuvwxyaa"));
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfTheSentenceIsPangramTestSuite, CheckIfTheSentenceIsPangramTest,
    ::testing::ValuesIn(CheckIfTheSentenceIsPangramSolution().getStrategyNames()));

}  // namespace problem_1832
}  // namespace leetcode
