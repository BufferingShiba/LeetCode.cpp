#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/split-strings-by-separator.h"

namespace leetcode::problem_2788 {

class SplitStringsBySeparatorTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  SplitStringsBySeparatorSolution solution;
};

TEST_P(SplitStringsBySeparatorTest, Example1) {
  std::vector<std::string> words = {"one.two.three", "four.five", "six"};
  std::vector<std::string> expected = {"one", "two", "three", "four", "five", "six"};
  EXPECT_EQ(solution.splitWordsBySeparator(words, '.'), expected);
}

TEST_P(SplitStringsBySeparatorTest, Example2) {
  std::vector<std::string> words = {"$easy$", "$problem$"};
  std::vector<std::string> expected = {"easy", "problem"};
  EXPECT_EQ(solution.splitWordsBySeparator(words, '$'), expected);
}

TEST_P(SplitStringsBySeparatorTest, Example3) {
  std::vector<std::string> words = {"|||"};
  std::vector<std::string> expected = {};
  EXPECT_EQ(solution.splitWordsBySeparator(words, '|'), expected);
}

TEST_P(SplitStringsBySeparatorTest, SelfAuthoredSingleWord) {
  std::vector<std::string> words = {"hello"};
  std::vector<std::string> expected = {"hello"};
  EXPECT_EQ(solution.splitWordsBySeparator(words, ','), expected);
}

TEST_P(SplitStringsBySeparatorTest, SelfAuthoredNoSeparator) {
  std::vector<std::string> words = {"a#b", "c#d#e", "f"};
  std::vector<std::string> expected = {"a", "b", "c", "d", "e", "f"};
  EXPECT_EQ(solution.splitWordsBySeparator(words, '#'), expected);
}

INSTANTIATE_TEST_SUITE_P(
    SplitStringsBySeparatorTestSuite, SplitStringsBySeparatorTest,
    ::testing::ValuesIn(SplitStringsBySeparatorSolution().getStrategyNames()));

}  // namespace leetcode::problem_2788
