#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/check-if-a-string-is-an-acronym-of-words.h"

namespace leetcode {
namespace problem_2828 {

class CheckIfAStringIsAnAcronymOfWordsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  CheckIfAStringIsAnAcronymOfWordsSolution solution_;
};

TEST_P(CheckIfAStringIsAnAcronymOfWordsTest, Example1) {
  std::vector<std::string> words = {"alice", "bob", "charlie"};
  EXPECT_TRUE(solution_.isAcronym(words, "abc"));
}

TEST_P(CheckIfAStringIsAnAcronymOfWordsTest, Example2) {
  std::vector<std::string> words = {"an", "apple"};
  EXPECT_FALSE(solution_.isAcronym(words, "a"));
}

TEST_P(CheckIfAStringIsAnAcronymOfWordsTest, Example3) {
  std::vector<std::string> words = {"never", "gonna", "give", "up", "on", "you"};
  EXPECT_TRUE(solution_.isAcronym(words, "ngguoy"));
}

TEST_P(CheckIfAStringIsAnAcronymOfWordsTest, SelfAuthoredLengthMismatchLonger) {
  std::vector<std::string> words = {"a", "b"};
  EXPECT_FALSE(solution_.isAcronym(words, "abc"));
}

TEST_P(CheckIfAStringIsAnAcronymOfWordsTest, SelfAuthoredCharMismatch) {
  std::vector<std::string> words = {"bear", "aardvark"};
  EXPECT_FALSE(solution_.isAcronym(words, "ab"));
}

INSTANTIATE_TEST_SUITE_P(
    CheckIfAStringIsAnAcronymOfWordsTestSuite,
    CheckIfAStringIsAnAcronymOfWordsTest,
    testing::ValuesIn(CheckIfAStringIsAnAcronymOfWordsSolution().getStrategyNames()));

}  // namespace problem_2828
}  // namespace leetcode
