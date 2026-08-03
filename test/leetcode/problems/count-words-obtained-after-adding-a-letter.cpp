#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-words-obtained-after-adding-a-letter.h"

namespace leetcode {
namespace problem_2135 {

namespace {
std::vector<std::string> V(std::initializer_list<std::string> l) {
  return std::vector<std::string>(l);
}
}  // namespace

class CountWordsObtainedAfterAddingALetterTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CountWordsObtainedAfterAddingALetterSolution solution_;
};

TEST_P(CountWordsObtainedAfterAddingALetterTest, Example1) {
  auto startWords = V({"ant", "act", "tack"});
  auto targetWords = V({"tack", "act", "acti"});
  EXPECT_EQ(solution_.wordCount(startWords, targetWords), 2);
}

TEST_P(CountWordsObtainedAfterAddingALetterTest, Example2) {
  auto startWords = V({"ab", "a"});
  auto targetWords = V({"abc", "abcd"});
  EXPECT_EQ(solution_.wordCount(startWords, targetWords), 1);
}

INSTANTIATE_TEST_SUITE_P(
    CountWordsObtainedAfterAddingALetterTests,
    CountWordsObtainedAfterAddingALetterTest,
    ::testing::ValuesIn(
        CountWordsObtainedAfterAddingALetterSolution().getStrategyNames()));

}  // namespace problem_2135
}  // namespace leetcode
