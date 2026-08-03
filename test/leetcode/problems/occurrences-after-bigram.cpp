#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/occurrences-after-bigram.h"

namespace leetcode {
namespace problem_1078 {
namespace {

class OccurrencesAfterBigramTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  OccurrencesAfterBigramSolution solution;
};

TEST_P(OccurrencesAfterBigramTest, Example1) {
  auto result = solution.findOcurrences("alice is a good girl she is a good student", "a", "good");
  std::vector<std::string> expected = {"girl", "student"};
  EXPECT_EQ(result, expected);
}

TEST_P(OccurrencesAfterBigramTest, Example2) {
  auto result = solution.findOcurrences("we will we will rock you", "we", "will");
  std::vector<std::string> expected = {"we", "rock"};
  EXPECT_EQ(result, expected);
}

TEST_P(OccurrencesAfterBigramTest, SelfAuthoredNoMatch) {
  auto result = solution.findOcurrences("hello world foo bar", "a", "b");
  std::vector<std::string> expected = {};
  EXPECT_EQ(result, expected);
}

TEST_P(OccurrencesAfterBigramTest, SelfAuthoredSingleMatch) {
  auto result = solution.findOcurrences("a b c a b d", "a", "b");
  std::vector<std::string> expected = {"c", "d"};
  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    OccurrencesAfterBigramTestSuite, OccurrencesAfterBigramTest,
    ::testing::ValuesIn(OccurrencesAfterBigramSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1078
}  // namespace leetcode
