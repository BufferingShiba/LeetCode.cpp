#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/unique-number-of-occurrences.h"

namespace leetcode {

class UniqueNumberOfOccurrencesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  UniqueNumberOfOccurrencesSolution solution;
};

TEST_P(UniqueNumberOfOccurrencesTest, Example1) {
  std::vector<int> arr = {1, 2, 2, 1, 1, 3};
  EXPECT_TRUE(solution.uniqueOccurrences(arr));
}

TEST_P(UniqueNumberOfOccurrencesTest, Example2) {
  std::vector<int> arr = {1, 2};
  EXPECT_FALSE(solution.uniqueOccurrences(arr));
}

TEST_P(UniqueNumberOfOccurrencesTest, Example3) {
  std::vector<int> arr = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
  EXPECT_TRUE(solution.uniqueOccurrences(arr));
}

TEST_P(UniqueNumberOfOccurrencesTest, SelfAuthoredSingleElement) {
  std::vector<int> arr = {7};
  EXPECT_TRUE(solution.uniqueOccurrences(arr));
}

TEST_P(UniqueNumberOfOccurrencesTest, SelfAuthoredAllSameValue) {
  std::vector<int> arr = {3, 3, 3, 3};
  EXPECT_TRUE(solution.uniqueOccurrences(arr));
}

TEST_P(UniqueNumberOfOccurrencesTest, SelfAuthoredTwoDistinctWithSameFreq) {
  std::vector<int> arr = {1, 1, 2, 2};
  EXPECT_FALSE(solution.uniqueOccurrences(arr));
}

INSTANTIATE_TEST_SUITE_P(
    UniqueNumberOfOccurrencesTests, UniqueNumberOfOccurrencesTest,
    ::testing::ValuesIn(UniqueNumberOfOccurrencesSolution().getStrategyNames()));

}  // namespace leetcode
