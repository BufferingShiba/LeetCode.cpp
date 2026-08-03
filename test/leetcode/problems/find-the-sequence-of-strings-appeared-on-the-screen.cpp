#include <gtest/gtest.h>

#include "leetcode/problems/find-the-sequence-of-strings-appeared-on-the-screen.h"

namespace leetcode::problem_3324 {

class FindTheSequenceOfStringsAppearedOnTheScreenTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  FindTheSequenceOfStringsAppearedOnTheScreenSolution solution_;
};

TEST_P(FindTheSequenceOfStringsAppearedOnTheScreenTest, Example1) {
  std::string target = "abc";
  std::vector<std::string> expected = {"a", "aa", "ab", "aba", "abb", "abc"};
  EXPECT_EQ(solution_.stringSequence(target), expected);
}

TEST_P(FindTheSequenceOfStringsAppearedOnTheScreenTest, Example2) {
  std::string target = "he";
  std::vector<std::string> expected = {"a", "b", "c", "d", "e", "f", "g", "h",
                                       "ha", "hb", "hc", "hd", "he"};
  EXPECT_EQ(solution_.stringSequence(target), expected);
}

TEST_P(FindTheSequenceOfStringsAppearedOnTheScreenTest, SelfAuthoredSingleCharA) {
  std::string target = "a";
  std::vector<std::string> expected = {"a"};
  EXPECT_EQ(solution_.stringSequence(target), expected);
}

TEST_P(FindTheSequenceOfStringsAppearedOnTheScreenTest, SelfAuthoredSingleCharZ) {
  std::string target = "z";
  // a -> b -> ... -> z (26 strings)
  std::vector<std::string> expected;
  std::string cur = "a";
  expected.push_back(cur);
  while (cur.back() != 'z') {
    cur.back() = static_cast<char>(cur.back() + 1);
    expected.push_back(cur);
  }
  EXPECT_EQ(solution_.stringSequence(target), expected);
}

TEST_P(FindTheSequenceOfStringsAppearedOnTheScreenTest, SelfAuthoredWrapAroundZtoA) {
  std::string target = "za";
  // First char 'z': a->b->...->z (26 strings)
  // Then key1: za
  // Then key2: za -> zb? No, 'a' needs to become 'a', so no key2 needed.
  // Actually: after getting "z", press key1 -> "za", which already ends with 'a'. Done.
  std::vector<std::string> expected;
  std::string cur;
  // char 0: 'z'
  cur.push_back('a');
  expected.push_back(cur);
  while (cur.back() != 'z') {
    cur.back() = static_cast<char>(cur.back() + 1);
    expected.push_back(cur);
  }
  // char 1: 'a'
  cur.push_back('a');
  expected.push_back(cur);  // "za" already matches, no key2 needed
  EXPECT_EQ(solution_.stringSequence(target), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    FindTheSequenceOfStringsAppearedOnTheScreenTest,
    ::testing::ValuesIn(
        FindTheSequenceOfStringsAppearedOnTheScreenSolution().getStrategyNames()));

}  // namespace leetcode::problem_3324
