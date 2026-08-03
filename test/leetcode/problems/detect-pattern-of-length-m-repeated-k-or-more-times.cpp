#include <gtest/gtest.h>

#include "leetcode/problems/detect-pattern-of-length-m-repeated-k-or-more-times.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_1566 {
namespace {

class DetectPatternOfLengthMRepeatedKOrMoreTimesTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DetectPatternOfLengthMRepeatedKOrMoreTimesSolution solution;
};

TEST_P(DetectPatternOfLengthMRepeatedKOrMoreTimesTest, Example1) {
  std::vector<int> arr = {1, 2, 4, 4, 4, 4};
  EXPECT_TRUE(solution.containsPattern(arr, 1, 3));
}

TEST_P(DetectPatternOfLengthMRepeatedKOrMoreTimesTest, Example2) {
  std::vector<int> arr = {1, 2, 1, 2, 1, 1, 1, 3};
  EXPECT_TRUE(solution.containsPattern(arr, 2, 2));
}

TEST_P(DetectPatternOfLengthMRepeatedKOrMoreTimesTest, Example3) {
  std::vector<int> arr = {1, 2, 1, 2, 1, 3};
  EXPECT_FALSE(solution.containsPattern(arr, 2, 3));
}

TEST_P(DetectPatternOfLengthMRepeatedKOrMoreTimesTest, SelfAuthoredTooShort) {
  std::vector<int> arr = {1, 2, 3};
  EXPECT_FALSE(solution.containsPattern(arr, 2, 2));
}

TEST_P(DetectPatternOfLengthMRepeatedKOrMoreTimesTest, SelfAuthoredRepeatedAtEnd) {
  std::vector<int> arr = {1, 2, 5, 5, 5};
  EXPECT_TRUE(solution.containsPattern(arr, 1, 3));
}

INSTANTIATE_TEST_SUITE_P(
    DetectPatternOfLengthMRepeatedKOrMoreTimesTestSuite,
    DetectPatternOfLengthMRepeatedKOrMoreTimesTest,
    ::testing::ValuesIn(DetectPatternOfLengthMRepeatedKOrMoreTimesSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1566
}  // namespace leetcode
