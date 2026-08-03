#include <gtest/gtest.h>

#include "leetcode/problems/keyboard-row.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode::problem_500 {

namespace {

std::vector<std::string> GetSorted(const std::vector<std::string>& in) {
  auto out = in;
  std::sort(out.begin(), out.end());
  return out;
}

}  // namespace

class KeyboardRowTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  KeyboardRowSolution solution_;
};

TEST_P(KeyboardRowTest, Example1) {
  std::vector<std::string> words = {"Hello", "Alaska", "Dad", "Peace"};
  std::vector<std::string> expected = {"Alaska", "Dad"};
  EXPECT_EQ(GetSorted(solution_.findWords(words)), GetSorted(expected));
}

TEST_P(KeyboardRowTest, Example2) {
  std::vector<std::string> words = {"omk"};
  std::vector<std::string> expected = {};
  EXPECT_EQ(GetSorted(solution_.findWords(words)), GetSorted(expected));
}

TEST_P(KeyboardRowTest, Example3) {
  std::vector<std::string> words = {"adsdf", "sfd"};
  std::vector<std::string> expected = {"adsdf", "sfd"};
  EXPECT_EQ(GetSorted(solution_.findWords(words)), GetSorted(expected));
}

TEST_P(KeyboardRowTest, SingleCharacter) {
  std::vector<std::string> words = {"a", "Z", "m"};
  std::vector<std::string> expected = {"a", "Z", "m"};
  EXPECT_EQ(GetSorted(solution_.findWords(words)), GetSorted(expected));
}

TEST_P(KeyboardRowTest, MixedRowsRejected) {
  std::vector<std::string> words = {"Password", "Qwerty", "Alaska"};
  std::vector<std::string> expected = {"Alaska", "Qwerty"};
  EXPECT_EQ(GetSorted(solution_.findWords(words)), GetSorted(expected));
}

INSTANTIATE_TEST_SUITE_P(KeyboardRowTestSuite, KeyboardRowTest,
                         ::testing::ValuesIn(KeyboardRowSolution().getStrategyNames()));

}  // namespace leetcode::problem_500
