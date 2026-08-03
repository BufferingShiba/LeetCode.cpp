#include "leetcode/problems/frequencies-of-shortest-supersequences.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_3435 {
namespace {

static bool freqsEqual(const std::vector<int>& a, const std::vector<int>& b) {
  return a == b;
}

static bool resultSetsEqual(std::vector<std::vector<int>> got,
                            std::vector<std::vector<int>> expected) {
  if (got.size() != expected.size()) return false;
  for (auto& g : got) std::sort(g.begin(), g.end());
  for (auto& e : expected) std::sort(e.begin(), e.end());
  std::sort(got.begin(), got.end());
  std::sort(expected.begin(), expected.end());
  return got == expected;
}

}  // namespace

class FrequenciesOfShortestSupersequencesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  FrequenciesOfShortestSupersequencesSolution solution;
  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(FrequenciesOfShortestSupersequencesTest, Example1) {
  std::vector<std::string> words = {"ab", "ba"};
  std::vector<std::vector<int>> expected = {
      {1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  auto got = solution.supersequences(words);
  EXPECT_TRUE(resultSetsEqual(std::move(got), std::move(expected)));
}

TEST_P(FrequenciesOfShortestSupersequencesTest, Example2) {
  std::vector<std::string> words = {"aa", "ac"};
  std::vector<std::vector<int>> expected = {
      {2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  auto got = solution.supersequences(words);
  EXPECT_TRUE(resultSetsEqual(std::move(got), std::move(expected)));
}

TEST_P(FrequenciesOfShortestSupersequencesTest, Example3) {
  std::vector<std::string> words = {"aa", "bb", "cc"};
  std::vector<std::vector<int>> expected = {
      {2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
  auto got = solution.supersequences(words);
  EXPECT_TRUE(resultSetsEqual(std::move(got), std::move(expected)));
}

INSTANTIATE_TEST_SUITE_P(
    FrequenciesOfShortestSupersequencesTests,
    FrequenciesOfShortestSupersequencesTest,
    ::testing::ValuesIn(
        FrequenciesOfShortestSupersequencesSolution().getStrategyNames()));

}  // namespace problem_3435
}  // namespace leetcode
