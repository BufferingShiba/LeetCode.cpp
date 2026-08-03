#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/string-matching-in-an-array.h"

namespace leetcode {
namespace problem_1408 {

namespace {

void ExpectUnorderedEq(const std::vector<std::string>& expected,
                       const std::vector<std::string>& actual) {
  EXPECT_EQ(expected.size(), actual.size());
  std::vector<std::string> a = actual;
  std::sort(a.begin(), a.end());
  std::vector<std::string> e = expected;
  std::sort(e.begin(), e.end());
  EXPECT_EQ(e, a);
}

}  // namespace

class StringMatchingInAnArrayTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  StringMatchingInAnArraySolution solution;
};

TEST_P(StringMatchingInAnArrayTest, Example1) {
  std::vector<std::string> words = {"mass", "as", "hero", "superhero"};
  std::vector<std::string> expected = {"as", "hero"};
  ExpectUnorderedEq(expected, solution.stringMatching(words));
}

TEST_P(StringMatchingInAnArrayTest, Example2) {
  std::vector<std::string> words = {"leetcode", "et", "code"};
  std::vector<std::string> expected = {"et", "code"};
  ExpectUnorderedEq(expected, solution.stringMatching(words));
}

TEST_P(StringMatchingInAnArrayTest, Example3) {
  std::vector<std::string> words = {"blue", "green", "bu"};
  std::vector<std::string> expected = {};
  ExpectUnorderedEq(expected, solution.stringMatching(words));
}

TEST_P(StringMatchingInAnArrayTest, SelfAuthoredSingleWord) {
  std::vector<std::string> words = {"abc"};
  std::vector<std::string> expected = {};
  ExpectUnorderedEq(expected, solution.stringMatching(words));
}

TEST_P(StringMatchingInAnArrayTest, SelfAuthoredNoSubstring) {
  std::vector<std::string> words = {"aa", "bb", "cc"};
  std::vector<std::string> expected = {};
  ExpectUnorderedEq(expected, solution.stringMatching(words));
}

INSTANTIATE_TEST_SUITE_P(
    StringMatchingInAnArrayTestSuite, StringMatchingInAnArrayTest,
    ::testing::ValuesIn(StringMatchingInAnArraySolution().getStrategyNames()));

}  // namespace problem_1408
}  // namespace leetcode
